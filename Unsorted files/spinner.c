#include <stdio.h>

#if defined(_WIN32)
    #include <windows.h>
#else
    #include <unistd.h>
#endif

void clearConsole(void)
{

#if defined(_WIN32)
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD count;
    DWORD cellCount;
    COORD homeCord = {0,0};
    if (hConsole == INVALID_HANDLE_VALUE)
    {
        fprintf(stderr,"getting the handle failed\n");
        return;
    }
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) 
    {
        fprintf(stderr,"Failed to get console info.\n");
        return;
    }
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;


    FillConsoleOutputCharacter(hConsole,' ',cellCount,homeCord,&count);
    FillConsoleOutputAttribute(hConsole,csbi.wAttributes,cellCount,homeCord,&count);
    SetConsoleCursorPosition(hConsole,homeCord);
#else
    printf("\033[2J\033[H");
#endif
    fflush(stdin);
}

void portSleep(int seconds)
{
#ifdef _WIN32
    Sleep(seconds * 1000);
#else
    sleep(seconds);
#endif
}

int main(void)
{
    char positions[] = "|\\-/";
    int symbols = sizeof(positions) - 1;

    for (int i = 0;1;i++)
    {
        fputc(positions[i % symbols],stdout);
        fflush(stdin);
        portSleep(1);
        clearConsole();
    }
}