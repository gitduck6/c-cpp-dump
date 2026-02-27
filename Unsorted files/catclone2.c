#include <stdio.h>

/*
    * i think i would like to come back to this, i will try to remake a util everyday
    * that would make this day 1?
    * and i think my goal for now is to make a chat server, "THE BIG GOAL" in a way
    * 
    * but i do not intend to stop there ofc :)
    *
*/
int main(int argc, char ** argv)
{

    // Goes through every index of argv from 1 till argc-1
    for (int i = 1;i < argc;i++)
    {
        
        int c;
        FILE * fp = fopen(argv[i],"r");
        if (fp == NULL)
        {
            perror("file");
            return 1;
        }

        while ((c = fgetc(fp)) != EOF)
        {
            fputc((char)c,stdout);
        }

    }
    putchar('\n');
    return 0;
}