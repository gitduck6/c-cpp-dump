#pragma once
// This is basically a header guard
// stops a header from being included multiple times
// to avoid "redefenition errors"

#include "raylib.h"

typedef struct Fvector2
{
    float x;
    float y;
} Fvector2;
// ima make camerastart a float Vector2 type since i want smoother movement later on
// might change it if it proves to be worthless
// Nevermind, i think ill use regular vector2s for the camera, but this struct could be needed

extern Vector2 cameraStart;
// extern is basically a promise that a variable exists apparently
// the compiler doesnt allocate space for it
// i did this since you cant define a vector2 after declaration with {}

void vdrawRect(Rectangle rect,Color color);
void vdrawCircle(Vector2 pos,float radius,Color color);
void vdrawLine(Vector2 start,Vector2 end,int thick, Color color);
Vector2 posToVpos(Vector2 pos);
Vector2 VposTopos(Vector2 vpos);



