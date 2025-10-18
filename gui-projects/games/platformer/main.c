#include "viewpointdraw.h"
#include "raylib.h"
#include "stdio.h"

#define TILESIZE 50
#define LINEWIDTH 3
/*
    * Also why not call this big guy a DOCBOARD
    * a Board for the "documentation"
    * in reality its just me going insane
    * 
    * Hello, in this project I will try to make a platformer game.
    * For now, my main goal is to implement "Camera movements."
    * At first, it might seem that our window is our canvas, but I want to turn it into just a point of view.
    * What it basically will be is that the canvas will be larger than our window,
    * and we only see what's in our window while there are other things we don't see.
    * We can LEAVE and RETURN to these "Other things,"
    * similar to many platformer games, hence the name.
    * 
    * also i might add a little character and obstacles.
    * Now i better get to work.
    *
    * now that the basic algorithm is present, i need to immitate camera movement a little better
    * Namely by adding a gridlike background
    * 
    * So the first step will be adding a line generator, similar to minecraft
    * how it generates only whats in your field of view (FOV) or our window
    * 
    * Time to think:
    * a global struct array containing the direction and the index of every line
    * Visual analogy:
    *      | <- This would be topside 0
    *   ---+-- <- these would be forward 0 and 1
    *      |
    *      | <- This would be bottomside 1
    *      | <- This would be bottomside 2
    * and so on, i hope that made sense
    * BTW each x line will be screenSize.x long
    * and each y line screenSize.y long
    * We should start counting from 0
    * 
    * generate each one we see, ungenerate them when we lose sight of them
    * ima call them Glines, partially because thats all i can think of and because
*/

Vector2 screenSize = {600,400};

int main(void)
{
    InitWindow(screenSize.x,screenSize.y,"A raylib platformer!");
    SetTargetFPS(60);

    Rectangle square1 = {100,100,50,50};   
    
    MkGline(1,0);

    while (!WindowShouldClose()) 
    {
        //Camera movements
        if (IsKeyDown(KEY_UP)) cameraStart.y++;
        if (IsKeyDown(KEY_DOWN)) cameraStart.y--;
        if (IsKeyDown(KEY_LEFT)) cameraStart.x++;
        if (IsKeyDown(KEY_RIGHT)) cameraStart.x--;

        BeginDrawing();

        //Draw Glines
        for (int i = 0;i < gLineCount;i++)
        {
            Vector2 start = {0};
            Vector2 end = {0};
            switch (gLines[i].direction % 4)
            {
            case 0: //EAST
                start.x = gLines[i].index * screenSize.x;
                start.y = 0;
                end.x = (gLines[i].index + 1) * screenSize.x;
                end.y = 0;
                break;
            case 1: //NORTH
                start.x = 0;
                start.y = -gLines[i].index * screenSize.y;
                end.x = 0;
                end.y = -(gLines[i].index + 1) * screenSize.y;
                break;
            case 2: //WEST
                start.x = -gLines[i].index * screenSize.x;
                start.y = 0;
                end.x = -(gLines[i].index + 1) * screenSize.x;
                end.y = 0;
        
                break;
            case 3: //SOUTH
                start.x = 0;
                start.y = gLines[i].index * screenSize.y;
                end.x = 0;
                end.y = (gLines[i].index + 1) * screenSize.y;
        
                break;
            default:
                fprintf(stderr,"BOOOM!!!! that should NOT have happend, goodbye World\n");
                CloseWindow();
                break;
            }
            vdrawLine(start,end,3,BLACK);
        }

        ClearBackground(RAYWHITE);
        vdrawRect(square1,RED);
        vdrawCircle((Vector2){30,30},20,GRAY);
        //vdrawLine((Vector2){0,0},(Vector2){screenSize.x,0},3,BLACK);

        EndDrawing();
    }   
    CloseWindow();
    return 0;
}