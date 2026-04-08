#include <stdio.h>

char ttt_buffer[4][4] = {"___", "___", "___", (char)0};

void print_board(char buffer[4][4])
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
        scanf("%d",x);

        if ((*x > 3) || (*x < 1))
            continue;
        else
            break;
        }

        while (1) 
        {
        printf("Please enter the Y position of your move 1-3:\n");
        scanf("%d",y);

        if ((*y > 3) || (*y < 1))
            continue;
        else
            break;
        }
}

void setpos(int x, int y, char goal)
{
    ttt_buffer[x-1][y-1] = goal;

}

int init_game()
{

    while (1)
    {
        int x = 0, y = 0;

        getpos(&x,&y);
        setpos(x,y,'+');
        print_board(ttt_buffer);
        
    }
}

int main(void)
{
    init_game();
    return 0;
}