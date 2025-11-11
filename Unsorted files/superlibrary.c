#include <stdio.h>
#include <stdlib.h>

/*
    * in this code, as u can see im not using any malloc, pretty much replacing it with realloc
    * this seems to have no difference from the typicall "malloc block"
    * 
    * Okay i will try to document the windows terminal clearer now,
    * this is actually similar to the termios thing
    * probably another "C tradition"
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

char *getStr(FILE* fHandle)
{
    size_t size = 16;
    size_t len = 0;
    char *str = malloc(sizeof(char) * size);
    if (str == NULL)
    {
        fprintf(stderr,"Malloc fail\n");
        return NULL;
    }

    char character;
    while ( (character = fgetc(fHandle) != '\n') && (character != EOF) )
    {
        str[len] = character;
        len++;
        if (size <= len)
        {
            size *= 2;
            char *temp = realloc(str,size);
            if (temp == NULL) 
            {
                fprintf(stderr,"Realloc fail\n");
                return NULL;
            }
            str = temp;
        }
    }
    str[len] = 0;
    return str;
}

void clearConsole(void)
{
    #if defined(_WIN32)
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Get the handle thing so we can work with the terminal
    // OKAY IT WASNT right to use input here
    CONSOLE_SCREEN_BUFFER_INFO csbi; // we will store the info here
    DWORD count; // DWORD is an unsigned int used in windows, similar to size_t i believe
    DWORD cellCount; 
    COORD homeCoords = {0,0}; // a coordinate struct, similar to Vector2 from raylib

    if (hConsole == INVALID_HANDLE_VALUE) 
    {
        fprintf(stderr,"Failed to get console info.\n");
        return;
    } 

    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) // get the CSBI of the console handle and keep it at csbi's adress
    {
        fprintf(stderr,"Failed to get console info.\n");
        return;
    }
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    FillConsoleOutputCharacter(hConsole, (TCHAR) ' ', cellCount, homeCoords, &count); 
    // fills the hConsole with ' 'spaces, CELLCOUNT times starting from homeCord and stores the amount of
    // characters actually written in count
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, cellCount, homeCoords, &count);
    // this line i believe sets the previous attributes back, tho i dont remmemmber changing it
    // so its kinda confusing for me
    SetConsoleCursorPosition(hConsole, homeCoords);// and finallymoves the cursor back

    #elif !defined(_WIN32)
    printf("\033[2J\033[H");// if we are'nt in windows use ansi escape codes
    // SERIOUSLY WHY IS THIS SO QUICK???
    // WHAT IF A UNIX SYSTEM DOESNT HAVE ANSI
    // OR IS IT A STANDART
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
    library[libLen + 1].title = NULL;
    libLen++;
}

int main(void)
{
    char running = 1;

    while (running)
    {
        printf("Please select an option:\n\t[1]Add a book\n\t[2]Remove a book\n\t[3]List Books \n\t[q]Quit\n");
        char ch = getch();

        switch (ch)
        {
        case '1':
            char *str = getStr(stdin);
            AddBook(str);
            break;

        case '2':
            break;

        case 'Q':
        case 'q':
            printf("Quitting...");
            return 0;
            break;
        
        default:
            break;
        }

        clearConsole();       

    }

    return 0;
}