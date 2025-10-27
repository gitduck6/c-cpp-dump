//mysh.c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
    * yet another mini project that seemed interesting
    * i think it would be interesting to use this "docboard" as kind of a little blog or diary
    * or idk
    * 
*/

int main(void)
{
    char buffer[256] = {0};
    char running = 1;

    while (running) {
        printf("mysh>>");
        fflush(stdout);
        fgets(buffer,sizeof(buffer),stdin);

        if (!strcmp(buffer,"exit\n")) break;

        system(buffer);
    }
    return EXIT_SUCCESS;
}