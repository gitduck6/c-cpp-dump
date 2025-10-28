//dynamicbuffer.c
#include <stdio.h>
#include <stdlib.h>

/*
    * A dynamical buffer that changes it's size based on the length of the input
    * with a regular fgets function we can only get the first N characters of a string to a buffer,
    * since its C (idk lmao)
    * also im making this for the "mysh.c" program 
    * 
    * Okay so i had to use a little ai for this piece of code
    * But id say its quite simple actually
    * what it essentially does is:
    *   1. allocate a small buffer
    *   2. read chararcter by character untill a newline or end of file
    *   3. set the read characters to the buffer and increase the "length" variable
    *   4. if the length is now larger or equal to the actuall buffer size then double the buffer size
    *   5. at the end, just add the null terminator to turn it to a legal Cstring
    * also i first intended to just read from stdin but it seems like
    * it can also read this way from any readable file
    * JUST AN ASSUMPTION (i did not test files)
*/

char * readLine(FILE * fileHandle)
{
    size_t bSize = 32;
    size_t length = 0;
    char *buffer = malloc(bSize * sizeof(char));
    if (!buffer) return NULL;

    char c;
    while (((c = fgetc(fileHandle)) != '\n') && (c != EOF))
    {
        buffer[length] = c;
        length++;

        if (bSize <= length)
        {
            bSize *= 2;
            char *newBuff = realloc(buffer,bSize);
            if (!newBuff)
            {
                free(buffer);
                return NULL;
            }
            buffer = newBuff;
        }
    }
    buffer[length] = '\0';
    return buffer;
}

int main(void)
{
    char *string = readLine(stdin);
    printf("%s",string);
}