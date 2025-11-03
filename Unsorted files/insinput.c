#include <stdio.h>
#include <conio.h>
/*
    * instant input in the windows OS
    * 
*/

int main(void)
{
    char ch = 0;

    while (1)
    {
        ch = getch();

        printf("You pressed char:%d\n",ch);

        if (ch == 'q') break;
    }
    return 0;
}