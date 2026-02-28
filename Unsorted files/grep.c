#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
    Okay, so a brief sumrary of the grep command is that it reads stdin line by line
    and returns us every line where we have the string argv[1]

    i feel like my brain is like turned off wth
    this version only works with a single line or the first line

    Okay now i added multiline support, it just needs a dynamic buffer for each line

    done, did something basic, sadly used ai a lil too much but i guess this is day 2?
*/

char *fgetds(FILE * fp)
{
    size_t size = 32;
    size_t len = 0;

    char *dbuffer = malloc(size);
    if (dbuffer == NULL)
    {
        perror("malloc");
        return NULL;
    }

    int c;
    while (((c = fgetc(fp)) != EOF) && (c != '\n'))
    {
        if ((len + 1) >= size)
        {
            size *= 2;
            char * temp = realloc(dbuffer,size);
            if (temp == NULL)
            {
                perror("realloc");
                free(dbuffer);
                return NULL;
            }
            dbuffer = temp;
        } 
        dbuffer[len] = (char)c;
        len++;
    }
    dbuffer[len] = '\0';

    if (c == EOF && len == 0) 
    {
        free(dbuffer);
        return NULL;
    }

    return dbuffer;
}

int main(int argc, char ** argv)
{
    if (argc != 2)
    {
        fprintf(stderr,"Usage: %s [target]\n",argv[0]);
        return 1;
    }

    char *line;

    while ((line = fgetds(stdin)) != NULL)
    {
        if (strstr(line,argv[1]) != NULL)
        {
            printf("%s\n",line);
        }
    }

    return 0;
}