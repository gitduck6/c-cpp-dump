#include <stdio.h>
#include <stdlib.h>

/*
    * in this code, as u can see im not using any malloc, pretty much replacing it with realloc
    * this seems to have no difference from the typicall "malloc block"
    *
*/
#if defined(_WIN32)
#include <conio.h>
#include <windows.h>
#else
#include <termios>
#include <unistd.h>
char getch(void)
{
    // Function copied of the "insinput.c" program
    struct termios oldattr, newattr;
    char ch;
    tcgetattr(STDIN_FILENO,&oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO,TCSANOW,&newattr);
    ch = getchar();
    tcsetattr(STDIN_FILENO,TCSANOW,&oldattr);
    return ch;
}
#endif

void clearConsole(void)
{
    #if defined(_WIN32)
    HANDLE hConsole = GetStdHandle(STD_INPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD count;
    DWORD cellCount;
    COORD homeCoords = {0,0};

    if (hConsole == INVALID_HANDLE_VALUE) return;

    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) return;
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    FillConsoleOutputCharacter(hConsole, (TCHAR) ' ', cellCount, homeCoords, &count);
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, cellCount, homeCoords, &count);
    SetConsoleCursorPosition(hConsole, homeCoords);

    #elif !defined(_WIN32)
    printf("\033[2J\033[H");
    #endif
}

typedef struct
{
    char *title;
} 
Book;

Book *library = NULL;
size_t libLen = 0;

void AddBook(char * title)
{
    Book *temp = realloc(library,sizeof(Book) * (libLen + 2));// gotta null terminate cos its a tradition or sum
    if (temp == NULL)
    {
        fprintf(stderr,"Memory allocation failure\n");
        return;
    }
    library = temp;

    library[libLen].title = title;
    libLen++;
}

int main(void)
{
    char running = 1;

    while (running)
    {
        printf("Please select an option:\n\t[1]Add a book\n\t[2]Remove a book \n\t[q]Quit\n");
        char ch = getch();
        clearConsole();       

    }

    return 0;
}