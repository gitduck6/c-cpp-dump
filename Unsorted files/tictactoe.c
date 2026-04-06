#include <stdio.h>


int init_game()
{
    char ttt_buffer[3][3] = {0};


    while (1)
    {
        char position[2];

        while (1) 
        {
        printf("Please enter the X position of your move 1-3:\n");
        scanf("%d",position);

        if ((*position > 3) || (*position < 1))
            continue;
        else
            break;
        }

        while (1) 
        {
        printf("Please enter the Y position of your move 1-3:\n");
        scanf("%d",position + 1);

        if ((*(position + 1) > 3) || (*(position + 1) < 1))
            continue;
        else
            break;
        }

        printf("%d %d\n",position[0],position[1]);
    }
}

int main(void)
{
    init_game();
    return 0;
}