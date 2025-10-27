//mysh.c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define INITIALSIZE 256

/*
    * yet another mini project that seemed interesting
    * i think it would be interesting to use this "docboard" as kind of a little blog or diary
    * or idk
    * 
*/

typedef struct buffer
{
    char *string;
    int size;
} 
Buffer;

void InitBuffer(Buffer *buffer)
{
    buffer->string = malloc(sizeof(char) * INITIALSIZE);
    buffer->size = INITIALSIZE;
}

int main(void)
{

    Buffer inbuffer;
    InitBuffer(&inbuffer);
    char running = 1;

    while (running) {
        printf("mysh>>");
        fflush(stdout);
        fgets(inbuffer.string,inbuffer.size,stdin);

        if (!strcmp(inbuffer.string,"exit\n")) break;

        system(inbuffer.string);
    }
    return EXIT_SUCCESS;
}