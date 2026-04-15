#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(__WIN32) || defined(_WIN32)
    #include <conio.h>
#else    
    #include <termios.h>
    #include <unistd.h>
#endif

#define BOARD_HEIGHT    16
#define BOARD_WIDTH     16

#define ARROW_UP    1
#define ARROW_DOWN  2
#define ARROW_LEFT  3
#define ARROW_RIGHT 4

#define ESC_KEY (char)27


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
/* 
    * according to the ansi standart Arrow keys are in the following format: 27 91 65 (example for the UP arrow key)
    * only the 3rd number varies between arrow keys, from what ive seen here on linux
    * so im not very sure abt windows for now
    * 
    * But that besides the point, we just check if the first 2 characters are 27 and 91 (ESC, [)
    * and precieve it as an arrow key, then determinte its kind based on the 3rd character 
    * with switch statements
    * 'A' for up 'B' for done 'C' for right and 'D' for left
    * 
    * so apparently there an be keys in between or something idk
    * i cant get it to work
*/
int get_arrow_key()
{
    char key_id;

    if (getch() != ESC_KEY)
        return 0;
    if (getch() != '[')
        return 0;
    key_id = getch();

    switch (key_id)
    {
    case 'A': return ARROW_UP;
    case 'B': return ARROW_DOWN;
    case 'C': return ARROW_RIGHT;
    case 'D': return ARROW_LEFT;
    }
    return 0;
}

int main(void)
{
    init_board();
    for (int i = 0;board[i] != NULL;i++)
    {
        printf("%s\n",board[i]);
    }

    char arrow = get_arrow_key();
    printf("The return value is %d\n",arrow);
    return 0;
}