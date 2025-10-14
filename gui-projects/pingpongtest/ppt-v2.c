#include "raylib.h"
#include "stdio.h"
/**\
    * Due to the previous versions suboptimality ive decided to remake it.
    * And to be honest, i pretty much mixed up so many things i think it would be better off if i remade it.
    *
    * 
    * 
    * 
\**/

Vector2 screenSize = {600,400};

typedef struct Ball
{
    //Position:
    float x;
    float y;
    
    float radius;

    //Velocity:
    float xVel;
    float yVel;

} Ball;

typedef struct Entity
{
    //Position:
    int x;
    int y;
    //Velocity:
    int xVel;
    int yVel;
    //Size:
    int width;
    int height;
    //Score:
    unsigned short int score;
    // unsigned short int is basically a 2 byte variable
    // ill use it since we probaby dont need scores over 2^16 (~65K)
    // also its unsigned cos we dont rly need negative numbers

} Entity;

Entity *Charlist = NULL;
int charAmount = 0; 

void mkChar() {
    Entity *temp = NULL;
    if ((Charlist == NULL) && (charAmount == 0)) 
    {   
        temp = MemAlloc(sizeof(Entity));
        if (temp == NULL) 
        {
            fprintf(stderr,"MALLOC failed.\n");
            return;
        }
        Charlist = temp;
        // i just saw this function in the text completor, i guess its raylib's malloc?
    }
    else if (charAmount != 0)
    {
        temp = MemRealloc(Charlist,sizeof(Entity) * (charAmount + 1));
        if (temp == NULL) 
        {
            fprintf(stderr,"MALLOC failed.\n");
            return;
        }
        Charlist = temp;
    }

    charAmount++;
}

void drawEntity(Entity entity, Color color)
{
    DrawRectangle(entity.x,entity.y,entity.width,entity.height,color);
}

int main(void) 
{
    InitWindow(screenSize.x,screenSize.y,"Simple raylib game");
    SetTargetFPS(60);
    
    Ball ball;
    ball.x = screenSize.x / 2;
    ball.y = screenSize.y / 2;
    ball.radius = 8; 
    ball.xVel = 1;
    ball.yVel = 1;

    // The player - [0]
    mkChar();
    Charlist[charAmount - 1].width = 12;
    Charlist[charAmount - 1].height = 70;

    Charlist[charAmount - 1].x = screenSize.x / 10;
    Charlist[charAmount - 1].y = (screenSize.y / 2) - (Charlist[charAmount - 1].height / 2);

    Charlist[charAmount - 1].xVel = 1;
    Charlist[charAmount - 1].yVel = 1;
    /*
    * this is just to reference our entities
    * for example instead of charList[0] we could just go with its name - (*player)
    * OR even player->value since its a struct
    * 
    * mainly just a readibility thing, i dont know if ill use it
    */
    Entity *player = &Charlist[charAmount - 1];
    Charlist[charAmount - 1].score = 0;


    // The opponent - [1]
    mkChar();
    Charlist[charAmount - 1].width = 12;
    Charlist[charAmount - 1].height = 70;

    Charlist[charAmount - 1].x = (screenSize.x * 9) / 10;
    Charlist[charAmount - 1].y = (screenSize.y / 2) - (Charlist[charAmount - 1].height / 2);

    Charlist[charAmount - 1].xVel = 1;
    Charlist[charAmount - 1].yVel = 1;
    // this is also just a reference
    Entity *enemy = &Charlist[charAmount - 1];
    Charlist[charAmount - 1].score = 0;


    //Main loop:
    while (!WindowShouldClose()) 
    {
        //Check if ball is in bounds
        if (ball.x + (2 * ball.radius) <= 0) 
        {
            player->score++;
            //Goto center
            ball.x = screenSize.x / 2;
            ball.y = screenSize.y / 2;

        }
        if (ball.x - (2 * ball.radius) >= screenSize.x) 
        {
            enemy->score++;
            //Goto center
            ball.x = screenSize.x / 2;
            ball.y = screenSize.y / 2;
              
        }
        // the (2 * ball.radius) portion makes it so it registers as a goal only when the ball is entirely out AND an extra radius size
        // not just when the radius leaves the bounds

        //wall boundaries
        if ((ball.y >= screenSize.y - ball.radius) || (ball.y <= ball.radius)) ball.yVel = -ball.yVel;
        
        ball.y += ball.yVel;
        ball.x += ball.xVel;
        // Check for ball-rect collisions
        for (int i = 0;i < charAmount;i++) 
        {
            Rectangle curRect;
            curRect.x = Charlist[i].x;
            curRect.y = Charlist[i].y;
            curRect.width = Charlist[i].width;
            curRect.height = Charlist[i].height;
            if (CheckCollisionCircleRec(
            (Vector2){ball.x,ball.y},
            ball.radius,
            curRect))
            {
                ball.xVel = -ball.xVel;
            }
        }


        //Drawing portion:
        BeginDrawing();

        ClearBackground((Color){150,150,150,255});

        //DrawRectangle();
        DrawCircle(ball.x,ball.y,ball.radius,MAROON);

        //Draw entities
        for (int i = 0;i < charAmount;i++) 
        {
            drawEntity(Charlist[i], (Color){60,60,60,255});
        }

        EndDrawing();
    }
    CloseWindow();
    return 0;

}