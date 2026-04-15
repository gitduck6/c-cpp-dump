#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(__WIN32) || defined(_WIN32)
    #include <conio.h>
#else    
    #include <termios.h>
    #include <unistd.h>
#endif

#define BOARD_HEIGHT 16
#define BOARD_WIDTH 16

char **board;

#if !(defined(__WIN32) || defined(_WIN32))
char getch(void)
{
    struct termios oldattr, newattr;
    char ch;

    tcgetattr(STDIN_FILENO,&oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO,TCSANOW,&newattr);
    ch = getchar();
    tcsetattr(STDIN_FILENO,TCSANOW,&oldattr);
    // i dont wanna re-document this so please check the insinput.c source :)
}
#endif

void init_board()
{
    board = malloc(sizeof(char **) * (BOARD_HEIGHT + 1));
    for (int i = 0;i < BOARD_HEIGHT;i++)
    {
        board[i] = malloc(BOARD_WIDTH + 1);
        memset(board[i], '_',BOARD_WIDTH);
        board[i][BOARD_WIDTH] = '\0';
    }
    board[BOARD_HEIGHT] = NULL;

}


int main(void)
{
    init_board();
    for (int i = 0;board[i] != NULL;i++)
    {
        printf("%s\n",board[i]);
    }
    return 0;
}