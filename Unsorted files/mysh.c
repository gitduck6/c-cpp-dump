//mysh.c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#define CHUNK_SIZE 16

/*
    * yet another mini project that seemed interesting
    * i think it would be interesting to use this "docboard" as kind of a little blog or diary
    * or idk
    * 
*/
char *read_line(FILE * Handle)
{
    size_t len = 0;
    size_t size = 32;
    char *buffer = malloc(sizeof(char) * size);

    char c;
    while ( ( (c = fgetc(Handle) ) != '\n') && (c != EOF))
    {
        buffer[len] = c;
        len++;
        if (size <= len)
        {
            size *= 2;
            char *temp = realloc(buffer,size);
            if (!temp) return NULL;
            buffer = temp;
        }
    }
    buffer[len] = 0;
    return buffer;
}
/*
typedef struct buffer
{
    char *string;
    int size;
} 
Buffer;

void InitBuffer(Buffer *buffer)
{
    char *temp = malloc(sizeof(char) * CHUNK_SIZE);
    if (temp == NULL)
    {
        fprintf(stderr,"Memory allocation failiure\n");
        return;
    }
    buffer->string = temp;
    buffer->size = CHUNK_SIZE;
}


void enlargeBuffer(Buffer *buffer)
{
    buffer->size += CHUNK_SIZE;
    char *temp  = realloc(buffer->string,sizeof(char) * buffer->size);
    if (temp == NULL)
    {
        fprintf(stderr,"Memory allocation failiure\n");
        buffer->size -= CHUNK_SIZE;
        return;
    }
    buffer->string = temp;
}
*/
int main(void)
{
    char * buffer;
    //InitBuffer(&buffer);

    while (1) {
        printf("mysh>>");
        fflush(stdout);
        //fgets(buffer.string,buffer.size,stdin);
        buffer = read_line(stdin);

        if (!strcmp(buffer,"exit")) break;

        system(buffer);
    }

    free(buffer);
    return EXIT_SUCCESS;
}