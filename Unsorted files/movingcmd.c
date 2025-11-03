#include <windows.h>
#include <stdio.h>

/*
    * WARNING: the program only works in the windows operating system
    * Just decided  to try windows.h, i believe its called win32 api or sum
    * pretty cool, made a bouncing cmd
*/

typedef struct
{
    int x;
    int y;
} Vector2;

typedef struct
{
    int x;
    int y;
    int width;
    int height;
} Rect;


int main(void)
{
    Vector2 screenSize = {GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN)};
    Rect cmdLoc = {screenSize.x / 2, screenSize.y / 2, 300, 200};
    HWND console = GetConsoleWindow();
    int dx = 5;
    int dy = 5;

    if (console == NULL) 
    {
        fprintf(stderr,"No console window found\n");
        return 1;
    }
    while (TRUE)
    {
        if ((cmdLoc.x <= 0) || ((cmdLoc.x + cmdLoc.width) >= screenSize.x))
        {
            dx = -dx;
        }
        if ((cmdLoc.y <= 0) || ((cmdLoc.y + cmdLoc.height) >= screenSize.y))
        {
            dy = -dy;
        }
        cmdLoc.y += dy;
        cmdLoc.x += dx;
        MoveWindow(console,cmdLoc.x,cmdLoc.y,cmdLoc.width,cmdLoc.height,TRUE);
        Sleep(5);
        
    }
    //printf("%d",console->unused);

}