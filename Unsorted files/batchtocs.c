#include <stdio.h> 
#include <stdlib.h>
#define DEFAULT_OUTPUT "output.c"

/*
    * a program that takes a generic script file and turns it into C source code
    *
    * i have a simple algorithm in mind, read line by line and turn it into system("command")'s 
    * or something along those lines 
    * 
    * So my output isnt exactly how i want it, but this is only a windows issue
    * newlines in windows are actually /r/n, since im modifying them in binary mode
    * just removing the "b" from fopen was apparently sufficient
*/

char *readLn(FILE *fHandle)
{
    char ch = fgetc(fHandle);

    if (ch == EOF) return NULL;
    ungetc(ch,fHandle);

    size_t len = 0;
    size_t size = 32;
    char *buffer = malloc(size * sizeof(char));
    if (buffer == NULL) return NULL;


    while ( ((ch = fgetc(fHandle)) != EOF ) && (ch != '\n') )
    {
        buffer[len] = ch;
        len++;
        if (size <= len)
        {
            size *= 2;
            char *temp = realloc(buffer,size);
            if (temp == NULL) return NULL;
            buffer = temp;
        }
    }
    buffer[len] = 0; // NULL terminate

    return buffer;
}


int main(int argc, char **argv)
{
    char *input = NULL;
    char *output = DEFAULT_OUTPUT;
    if (argc <= 1)
    {
        fprintf(stderr,"Usage: %s [input] [output]\n",argv[0]);
        return 1;
    }
    input = argv[1];
    if (argv[2] != NULL) output =  argv[2];

    FILE *clearoutHandle = fopen(output,"wb");
    if (clearoutHandle == NULL)
    {
        fprintf(stderr,"Error clearing the file.\n");
        return 1;
    }
    fclose(clearoutHandle);


    FILE *inputHandle = fopen(input,"r");
    FILE *outputHandle = fopen(output,"a");
    
    fprintf(outputHandle,"#include <stdlib.h>\n\n");
    fprintf(outputHandle,"int main(void){\n");

    char *line = NULL;
    while ((line = readLn(inputHandle)) != NULL)
    {
        fprintf(outputHandle,"\tsystem(\"%s\");\n",line);
    }

    fprintf(outputHandle,"}\n");  

    fclose(inputHandle);
    fclose(outputHandle);
    return 0;
}