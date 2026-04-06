#include <stdio.h>

void print_board(char buffer[4][4])
{
    for (int i = 0;i < 3;i++)
    {
        printf("%s\n",buffer[i]);
    }
}

int init_game()
{
    char ttt_buffer[4][4] = {"   ", "   ", "   ", (char)0};


    while (1)
    {
        int x = 0, y = 0;

        while (1) 
        {
        printf("Please enter the X position of your move 1-3:\n");
        scanf("%d",&x);

        if ((x > 3) || (x < 1))
            continue;
        else
            break;
        }

        while (1) 
        {
        printf("Please enter the Y position of your move 1-3:\n");
        scanf("%d",&y);

        if ((y > 3) || (y < 1))
            continue;
        else
            break;
        }

        ttt_buffer[x-1][y-1] = 'x';
        print_board(ttt_buffer);
        
    }
}

int main(void)
{
    init_game();
    return 0;
}