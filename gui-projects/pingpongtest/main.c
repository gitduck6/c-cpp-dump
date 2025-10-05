#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
// my idea is to make a simple ping pong game if thats what its called;

struct floatVec2 {float x; float y;};
struct Rect {Vector2 pos;Vector2 size;};

struct Rect **RectAdresses;
int rectNum = 0;

const int screenWidth = 700;
const int screenHeight = 400;

bool isCircleColiding(float radius,Vector2 center) 
{
    //if ((center.x < (screenWidth - radius)) && ( center.x > radius ) )
    if ((center.y < (screenHeight - radius)) && ( center.y > radius) ) return 1;
    return 0;
}

bool didGoal(Vector2 ballPos) {
    if ((ballPos.x > screenWidth) || ( ballPos.x < 0 ) ) 
    {
        return 1;
    }
    else return 0;
}

void mkRect (int topX,int topY,int sizeX,int sizeY) {
    if (!rectNum) {
        RectAdresses = malloc(sizeof(struct Rect*));
    }
    else {
        RectAdresses = realloc(RectAdresses,sizeof(struct Rect*) * (rectNum + 1));
    }
    RectAdresses[rectNum] = malloc(sizeof(struct Rect));

    RectAdresses[rectNum]->pos.x = topX;
    RectAdresses[rectNum]->pos.y = topY;
    RectAdresses[rectNum]->size.x = sizeX;
    RectAdresses[rectNum]->size.y = sizeY;

    rectNum++;
}
int main(void) 
{
    InitWindow(screenWidth, screenHeight, "A test application in raylib");

    struct Rect player;

    player.pos = (Vector2){ (float)screenWidth/15, (float)screenHeight/2 };
    player.size = (Vector2){10,70};

    Vector2 ballPos = { (float)screenWidth/2, (float)screenHeight/2 };
    struct floatVec2 ballVel = {-1,-10};
    float ballRad = 5.0f;
    
    SetTargetFPS(60);
    
    while (!WindowShouldClose()) 
    {
        // get mouse position
        player.pos.y = GetMouseY() - (player.size.y / 2);
        
        // calculate ball position
        ballPos.y += (int)ballVel.y;
        ballPos.x += (int)ballVel.x;
        if (didGoal(ballPos)) {
            ballPos.x = (float)screenWidth/2;
            ballPos.y = (float)screenHeight/2;
        }
        
        bool lastFlip = 0;
        if (!isCircleColiding(ballRad,ballPos)) {
            if (lastFlip)
            ballVel.x = -ballVel.x;
            else
            ballVel.y = -ballVel.y;
            
            lastFlip != lastFlip;
        }
        // draw screen
        BeginDrawing();
        
        ClearBackground(BLACK);
        DrawRectangle(player.pos.x, player.pos.y, player.size.x, player.size.y, BLUE);
        DrawCircle(ballPos.x, ballPos.y, ballRad, RED);
        
        EndDrawing();
    }
    CloseWindow();
    return 0;
}