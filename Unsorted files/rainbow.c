#include <stdio.h>

#define COLOR "\e[%d;%dm"
#define RESET "\e[0m"


/*
    * In the COLOR definition
    * the first number represents the "effect" of the following string (boldness, underline etc)
    * while the second one is a number from 31 to 36 representing color
    * e.g.: \e[0;31m
    *
    * By the way, RESET stops the color/effect
    * 
    * if this was day 3 it was very unproductive
    * 
*/

int main(void)
{
    for (int i = 31;i <= 36;i++)
    {
        printf(COLOR "Hello world!\n" RESET,0,i);
    }
    return 0;
}