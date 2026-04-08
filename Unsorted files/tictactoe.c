#include <stdio.h>
#include <stdlib.h>

/*
    * Arrays are usually confusing to work with, i only use them since theyre easy to work with
    * you just do array[] and boom u got a functional array.
    * im not sure if its hard or im just not used to it
    * also i hate how theres no clear distrinction between arrays and pointers(atleast to my mind)
*/


char **game_buffer;

void print_board(char **buffer)
{
    for (int i = 0;i < 3;i++)
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

    while (1)
    {
        int x = 0, y = 0;

        getpos(&x,&y);
        setpos(x,y,'+');
        print_board(game_buffer);
        
    }
}

int main(void)
{
    init_game();
    return 0;
}