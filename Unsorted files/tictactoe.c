#include <stdio.h>
#include <stdlib.h>

#define SIDE_LEN 3

#define PLAYER_1 'x'
#define PLAYER_2 'o'

/*
    * Arrays are usually confusing to work with, i only use them since theyre easy to work with
    * you just do array[] and boom u got a functional array.
    * im not sure if its hard or im just not used to it
    * also i hate how theres no clear distrinction between arrays and pointers(atleast to my mind)
    * 
    * Lets make it a little less "hardcoded" our buffer is null terminated in every direction
    * so lets just take an advantage of those nulls instead of hardcoding a value such as 3
*/


char **game_buffer;

char check_win()
{
    char winner_char = 0;

    for (int i = 0;game_buffer[i] != NULL;i++)
    {
        char first_char = 0;
        char success = 1;
        for (int j = 0;game_buffer[i][j] != 0;j++)
        {
            if (j == 0) first_char = game_buffer[i][j];
            if (game_buffer[i][j] != first_char) 
            {
                success = 0;
                break;
            }
        }

        if (success && ((first_char == PLAYER_1) || (first_char == PLAYER_2)))
        {
            return first_char;
        }
    }
    return 0;
}

void print_board(char **buffer)
{
    for (int i = 0;buffer[i] != NULL;i++)
    {
        printf("%s\n",buffer[i]);
    }
}

void getpos(int *x,int * y)
{
    while (1) 
        {
        printf("Please enter the X position of your move 1-%d:\n",SIDE_LEN);
        while (scanf("%d",x) != 1)
        {
            printf("Invalid input.\n");
            while (getchar() != '\n');
        }

        if ((*x > SIDE_LEN) || (*x < 1))
            continue;
        else
            break;
        }

        while (1) 
        {
        printf("Please enter the Y position of your move 1-3:\n");
        while (scanf("%d",y) != 1)
        {
            printf("Invalid input.\n");
            while (getchar() != '\n');
        }

        if ((*y > SIDE_LEN) || (*y < 1))
            continue;
        else
            break;
        }
}

void setpos(int x, int y, char goal)
{
    game_buffer[y-1][x-1] = goal;

}

int init_game()
{
    //{"___", "___", "___", (char)0}
    game_buffer = malloc(sizeof(char *) * (SIDE_LEN + 1));
    int i;
    for (i = 0;i < SIDE_LEN;i++)
    {
        game_buffer[i] =  malloc(sizeof(char) * (SIDE_LEN + 1));
        sprintf(game_buffer[i],"___");
    }
    game_buffer[i] = NULL;

    char player_symbol = PLAYER_1;
    while (1)
    {
        int x = 0, y = 0;
        
        getpos(&x,&y);
        setpos(x,y,player_symbol);
        print_board(game_buffer);

        char win_char = check_win();
        if (win_char == PLAYER_1)
        {
            printf("Player 1 wins");
            return 0;
        }
        else if (win_char == PLAYER_2)
        {
            printf("Player 2 wins");
            return 0;
        }

        
        if (player_symbol == PLAYER_1) player_symbol = PLAYER_2;
        else player_symbol = PLAYER_1;

        // player_symbol ^= 23;

    }
}

int main(void)
{
    init_game();
    return 0;
}