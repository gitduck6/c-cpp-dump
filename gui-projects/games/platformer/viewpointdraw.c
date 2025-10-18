#include "viewpointdraw.h"
#include "raylib.h"
#include "stdio.h"

Vector2 cameraStart = {0,0};
Gline *gLines = NULL;
int gLineCount = 0;

void vdrawRect(Rectangle rect,Color color)
{
    DrawRectangle(rect.x + cameraStart.x,rect.y + cameraStart.y,rect.width,rect.height,color);
}

void vdrawCircle(Vector2 pos,float radius,Color color)
{
    DrawCircle(pos.x + cameraStart.x, pos.y + cameraStart.y,radius,color);
}

void vdrawLine(Vector2 start, Vector2 end, int width, Color color)
{
    Vector2 mStart = (Vector2){start.x + cameraStart.x,start.y + cameraStart.y};
    Vector2 mEnd = (Vector2){end.x + cameraStart.x,end.y + cameraStart.y};
    // M in mEnd and mStart stands for "Material"
    // which i added to try to indicate that its real, and the position on the screen
    DrawLineEx(mStart,mEnd,width,color);
}

/*
    * Okay so this regular Pos is just the good old position on the screen
    * while this new Vpos is a position on the whole "map" 
    * its positon on the screen varies depending on the cameraStart
*/

Vector2 posToVpos(Vector2 pos) 
{
    return (Vector2){pos.x - cameraStart.x,pos.y - cameraStart.y};
}

Vector2 VposTopos(Vector2 vpos)
{
    return (Vector2){vpos.x + cameraStart.x,vpos.y + cameraStart.y};
}

int MkGline(char direction,int index)
{
    if (gLineCount <= 0)
    {
        gLines = MemAlloc(sizeof(Gline) * (gLineCount + 1));
    }
    else
    {
        gLines = MemRealloc(gLines,sizeof(Gline) * (gLineCount + 1));
    }
    gLines[gLineCount].direction = direction;
    gLines[gLineCount].index = index;


    gLineCount++;
    return gLineCount;
}