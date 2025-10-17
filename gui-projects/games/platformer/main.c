#include "viewpointdraw.h"
#include "raylib.h"
#include "stdio.h"

#define TILESIZE 50
/*
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
*/


Vector2 screenSize = {600,400};

int main(void)
{
    InitWindow(screenSize.x,screenSize.y,"A raylib platformer!");
    SetTargetFPS(60);

    Rectangle square = {100,100,50,50};

    while (!WindowShouldClose()) 
    {
        if (IsKeyDown(KEY_UP)) cameraStart.y++;
        if (IsKeyDown(KEY_DOWN)) cameraStart.y--;
        if (IsKeyDown(KEY_LEFT)) cameraStart.x++;
        if (IsKeyDown(KEY_RIGHT)) cameraStart.x--;



        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawRectangle(square.x + cameraStart.x,square.y + cameraStart.y,square.width,square.height,RED);

        EndDrawing();
    }
    
}