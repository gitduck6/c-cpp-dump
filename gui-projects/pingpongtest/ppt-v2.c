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
    int xSize;
    int ySize;

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
            return 0;
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
            return 0;
        }
        Charlist = temp;
    }

    charAmount++;
}

void displayEntity(Entity)
{

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
    Charlist[charAmount - 1].x = screenSize.x / 10;
    Charlist[charAmount - 1].y = screenSize.y / 2;

    Charlist[charAmount - 1].xVel = 1;
    Charlist[charAmount - 1].yVel = 1;
    
    Charlist[charAmount - 1].xSize = 10;
    Charlist[charAmount - 1].ySize = 60;
    Entity *player = &Charlist[charAmount - 1];

    // The opponent - [1]
    mkChar();
    Charlist[charAmount - 1].x = (screenSize.x * 9) / 10;
    Charlist[charAmount - 1].y = screenSize.y / 2;

    Charlist[charAmount - 1].xVel = 1;
    Charlist[charAmount - 1].yVel = 1;
    
    Charlist[charAmount - 1].xSize = 10;
    Charlist[charAmount - 1].ySize = 60;
    Entity *player = &Charlist[charAmount - 1];


    //Main loop:
    while (!WindowShouldClose()) 
    {
        //wall boundaries
        if ((ball.y >= screenSize.y - ball.radius) || (ball.y <= ball.radius)) ball.yVel = -ball.yVel;
        
        ball.y += ball.yVel;
        ball.x += ball.xVel;



        //Drawing portion:
        BeginDrawing();

        ClearBackground(GRAY);

        //DrawRectangle();
        DrawCircle(ball.x,ball.y,ball.radius,MAROON);

        EndDrawing();
    }
    CloseWindow();
    return 0;

}