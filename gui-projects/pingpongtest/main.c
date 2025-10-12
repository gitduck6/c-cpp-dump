#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "raylib.h"

#define SPEEDLIM 5
// ANYTHING to use preprocessor definitojns bro:sob:

// my idea is to make a simple ping pong game if thats what its called;

struct floatVec2 {float x; float y;};
//struct Rect {Vector2 pos;Vector2 size;};

Rectangle **RectAdresses;
int rectNum = 0;

const int screenWidth = 700;
const int screenHeight = 400;

float abs_add(float x, float a) {
    return x += ((x >= 0) ? 1 : -1) * a;
}

bool isCircleColiding(float radius,struct floatVec2 center) 
{
    if ((center.y < (screenHeight - radius)) && ( center.y > radius) ) return false;
    return true;
}

// damn i just found out there was already a rect struct and i made it for no reason :sob:

bool didGoal(struct floatVec2 ballPos) {
    if ((ballPos.x > screenWidth) || ( ballPos.x < 0 ) ) 
    {
        return 1;
    }
    else return 0;
}

void mkRect (int topX,int topY,int sizeX,int sizeY) {
    if (!rectNum) {
        Rectangle **temp = malloc(sizeof(Rectangle*));
        if (temp == NULL) {
            fprintf(stderr,"Malloc failed e.1\n");
            return;
        }
        RectAdresses = temp;
    }
    else {
        Rectangle **temp = realloc(RectAdresses,sizeof(Rectangle *) * (rectNum + 1));
        if (temp == NULL) {
            fprintf(stderr,"Malloc failed e.2\n");
            return;
        }
        RectAdresses = temp;
    }
    
    RectAdresses[rectNum] = malloc(sizeof(Rectangle));
    
    
    RectAdresses[rectNum]->x = topX;
    RectAdresses[rectNum]->y = topY;
    RectAdresses[rectNum]->width = sizeX;
    RectAdresses[rectNum]->height = sizeY;
    
    rectNum++;
}
bool circTouchingRect(float radius, struct floatVec2 center) {
    int curX = (int)center.x;
    int curY = (int)center.y;
    Vector2 cur = {(int)center.x, (int)center.y};
    for (int i = 0;i < rectNum;i++) {
        if (CheckCollisionCircleRec(cur,radius,*(RectAdresses[i]))) {
            return true;
        }
    }
    return false;
}
int main(void) 
{
    InitWindow(screenWidth, screenHeight, "A test application in raylib");
    bool lastFlip = 0;
    int scores[2] = {0};
    char scoreString[50] =  "The score is 0 : 0";
    

    mkRect((float)screenWidth/15, (float)screenHeight/2, 10,70);
    mkRect((float)screenWidth - (float)screenWidth/15, (float)screenHeight/2, 10,70);
    int enemySpeed = 1;

    //mkRect((float)screenHeight - (float)screenWidth/15, (float)screenHeight/2, 10,70);

    struct floatVec2 ballPos = { (float)screenWidth/2, (float)screenHeight/2 };
    struct floatVec2 ballVel = {-1,-0.5};
    float ballRad = 5.0f;
    //Rectangle = {};
    
    SetTargetFPS(60);
    
    while (!WindowShouldClose()) 
    {
        // get mouse position
        RectAdresses[0]->y = GetMouseY() - (RectAdresses[0]->height / 2);
        
        // calculate ball position
        ballPos.y += ballVel.y;
        ballPos.x += ballVel.x;

        if (didGoal(ballPos)) {
            if (ballPos.x < (screenWidth/2)) {
                scores[1]++;
            }
            else
            {
                scores[0]++;
            }
            ballPos.x = (float)screenWidth/2;
            ballPos.y = (float)screenHeight/2;
            if (enemySpeed < SPEEDLIM) enemySpeed++;
            sprintf(scoreString,"The score is %d : %d",scores[0],scores[1]);

        }
        
        if (isCircleColiding(ballRad,ballPos)) {
            if (lastFlip)
            ballVel.x = -ballVel.x;
            else
            ballVel.y = -ballVel.y;
            
            lastFlip = !lastFlip;
        }

        if (circTouchingRect(ballRad,ballPos)) {
            if (lastFlip)
            ballVel.x = -ballVel.x;
            else
            ballVel.y = -ballVel.y;

            lastFlip = !lastFlip;
            //ballVel.x += 0.5;
            //ballVel.y += 0.5;
            if (ballVel.x < SPEEDLIM) ballVel.x = abs_add(ballVel.x,0.5);

            if (ballVel.y < SPEEDLIM) ballVel.y = abs_add(ballVel.y,0.5);

        }

        // the enemy ai
        if (ballPos.y < RectAdresses[1]->y)
        {
            RectAdresses[1]->y -= enemySpeed;
        } 
        else if (ballPos.y > (RectAdresses[1]->y - RectAdresses[1]->height)) {
            RectAdresses[1]->y += enemySpeed;
        }

        // draw screen
        BeginDrawing();
        
        ClearBackground(BLACK);

        DrawRectangle(RectAdresses[0]->x, RectAdresses[0]->y, RectAdresses[0]->width, RectAdresses[0]->height, RAYWHITE);
        DrawRectangle(RectAdresses[1]->x, RectAdresses[1]->y, RectAdresses[1]->width, RectAdresses[1]->height, RAYWHITE);

        DrawText(scoreString,screenWidth/2,20,20,RAYWHITE);

        DrawCircle(ballPos.x, ballPos.y, ballRad, RED);
        
        EndDrawing();
    }
    CloseWindow();
    return 0;
}