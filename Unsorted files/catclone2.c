#include <stdio.h>

int main(int argc, char ** argv)
{
    int c;
    FILE * fp = fopen(argv[1],"r");
    if (fp == NULL)
    {
        perror("file");
        return 1;
    }

    while ((c = fgetc(fp)) != EOF)
    {
        fputc((char)c,stdout);
    }
    return 0;
}