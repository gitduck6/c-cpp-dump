#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_HEIGHT 16
#define BOARD_WIDTH 16

char **board;

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