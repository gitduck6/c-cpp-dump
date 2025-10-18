#include "viewpointdraw.h"
#include "raylib.h"

Vector2 cameraStart = {0,0};

void vdrawRect(Rectangle rect,Color color)
{
    DrawRectangle(rect.x + cameraStart.x,rect.y + cameraStart.y,rect.width,rect.height,color);
}

void vdrawCircle(Vector2 pos,float radius,Color color)
{
    DrawCircle(pos.x + cameraStart.x, pos.y + cameraStart.y,radius,color);
}

/*
    * Okay so this regular Pos is just the good old position on the screen
    * while this new Vpos is a position on the whole screen
*/

Vector2 posToVpos(Vector2 pos) 
{
    return (Vector2){pos.x - cameraStart.x,pos.y - cameraStart.y};
}

Vector2 VposTopos(Vector2 vpos)
{
    return (Vector2){vpos.x + cameraStart.x,vpos.y + cameraStart.y};
}
