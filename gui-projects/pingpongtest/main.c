#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
// my idea is to make a simple ping pong game if thats what its called;

struct floatVec2 {float x; float y;};
//struct Rect {Vector2 pos;Vector2 size;};

struct Rectangle **RectAdresses;
int rectNum = 0;

const int screenWidth = 700;
const int screenHeight = 400;

bool isCircleColiding(float radius,Vector2 center) 
{
    if ((center.y < (screenHeight - radius)) && ( center.y > radius) ) return false;
    return true;
}

bool circTouchingRect(float radius, Vector2 center) {
        for (int i = 0;i < rectNum;i++) {
        if (CheckCollisionCircleRec(center,radius,*(RectAdresses[i]))) {
            return true;
        }
    }
    return false;
}
// damn i just found out there was already a rect struct and i made it for no reason :sob:

bool didGoal(Vector2 ballPos) {
    if ((ballPos.x > screenWidth) || ( ballPos.x < 0 ) ) 
    {
        return 1;
    }
    else return 0;
}

void mkRect (int topX,int topY,int sizeX,int sizeY) {
    if (!rectNum) {
        RectAdresses = malloc(sizeof(struct Rectangle*));
    }
    else {
        RectAdresses = realloc(RectAdresses,sizeof(struct Rectangle *) * (rectNum + 1));
    }
    RectAdresses[rectNum] = malloc(sizeof(struct Rectangle));

    RectAdresses[rectNum]->x = topX;
    RectAdresses[rectNum]->y = topY;
    RectAdresses[rectNum]->width = sizeX;
    RectAdresses[rectNum]->height = sizeY;

    rectNum++;
}
int main(void) 
{
    InitWindow(screenWidth, screenHeight, "A test application in raylib");
    bool lastFlip = 0;

    mkRect((float)screenWidth/15, (float)screenHeight/2, 10,70);

    Vector2 ballPos = { (float)screenWidth/2, (float)screenHeight/2 };
    struct floatVec2 ballVel = {-1,-1};
    float ballRad = 5.0f;
    //Rectangle = {};
    
    SetTargetFPS(60);
    
    while (!WindowShouldClose()) 
    {
        // get mouse position
        RectAdresses[0]->y = GetMouseY() - (RectAdresses[0]->height / 2);
        
        // calculate ball position
        ballPos.y += (int)ballVel.y;
        ballPos.x += (int)ballVel.x;

        if (didGoal(ballPos)) {
            ballPos.x = (float)screenWidth/2;
            ballPos.y = (float)screenHeight/2;
        }
        
        if (isCircleColiding(ballRad,ballPos)) {
            if (lastFlip)
            ballVel.x = -ballVel.x;
            else
            ballVel.y = -ballVel.y;
            
            lastFlip != lastFlip;
        }

        if (circTouchingRect(ballRad,ballPos)) {
            if (lastFlip)
            ballVel.x = -ballVel.x;
            else
            ballVel.y = -ballVel.y;

            //ballVel.x = -ballVel.x;
            //ballVel.y = -ballVel.y;

            ballPos.x -= ballVel.x * 5;
            //ballPos.y += ballVel.y * 5;
        }
        printf("%d ",CheckCollisionCircleRec(ballPos,ballRad,*RectAdresses[0]));
        // draw screen
        BeginDrawing();
        
        ClearBackground(BLACK);
        DrawRectangle(RectAdresses[0]->x, RectAdresses[0]->y, RectAdresses[0]->width, RectAdresses[0]->height, RAYWHITE);
        DrawCircle(ballPos.x, ballPos.y, ballRad, RED);
        
        EndDrawing();
    }
    CloseWindow();
    return 0;
}