#include <stdio.h>
#include <stdlib.h>

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
        printf("Please enter the X position of your move 1-3:\n");
        while (scanf("%d",x) != 1)
        {
            printf("Invalid input.\n");
            while (getchar() != '\n');
        }

        if ((*x > 3) || (*x < 1))
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

        if ((*y > 3) || (*y < 1))
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
    game_buffer = malloc(sizeof(char *) * 4);
    int i;
    for (i = 0;i < 3;i++)
    {
        game_buffer[i] =  malloc(sizeof(char) * 4);
        sprintf(game_buffer[i],"___");
    }
    game_buffer[i] = NULL;

    char player_symbol = 'x';
    while (1)
    {
        int x = 0, y = 0;
        
        getpos(&x,&y);
        setpos(x,y,player_symbol);
        print_board(game_buffer);
        
        if (player_symbol == 'x') player_symbol = 'o';
        else player_symbol = 'x';

        // player_symbol ^= 23;

    }
}

int main(void)
{
    init_game();
    return 0;
}