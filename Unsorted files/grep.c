#include <stdio.h>
#include <string.h>

/*
    Okay, so a brief sumrary of the grep command is that it reads stdin line by line
    and returns us every line where we have the string argv[1]

    i feel like my brain is like turned off wth
    this version only works with a single line or the first line

    Okay now i added multiline support, it just needs a dynamic buffer for each line
*/

int main(int argc, char ** argv)
{
    if (argc != 2)
    {
        fprintf(stderr,"Usage: %s [target]\n",argv[0]);
        return 1;
    }

    char line[200] = {0};

    while (fgets(line,sizeof(line),stdin) != NULL)
    {
        if (strstr(line,argv[1]) != NULL)
        {
            printf("%s",line);
        }
    }

    return 0;
}