#include <stdio.h>

/*
    * i want this to be a simple program to read flag arguments
    * examples: doing "ls -la" and "ls -l -a" returns the same thing
    * this is because in both of them have only the flags(options) a and l enabled
    * 
    * also some programs have flags that ARENT single characters
    * example: "ls --all" this would enable the flag "all" rather than a,l, and l (pretend the l's arent repeating)
    * i hope you get what im trying to say
    * 
    * rightnow it works with single characrters just needs the "--all"
    * ok everything is as i wanted, but theres still so much to expand on
    * 
    * Heres the overview of the algorithm:
    * go through each argument 
    *   if the argument DOESNT start with a dash skip the whole argument (its not a flag)
    *   then iterate through the characters of the argument cstring, 
    *   if this is the second character and the current character is a dash (just like the first one)
    *   return the part of the string after the dashes IF there is anything after the second dash
    *
*/


int main(int argc,char **argv)
{
    if (argc <= 1)
    {
        printf("No arguments are present");
        return 0;
    }

    for (int i = 1;argv[i] != NULL;i++)
    {
        if (argv[i][0] != '-') continue;
        for (int j = 1;argv[i][j] != '\0';j++)
        {
            if (j == 1)
            {
                if ((argv[i][j] == '-') && (argv[i][j + 1] != '\0'))
                {
                    printf("multi-character flag %s is enabled\n",argv[i] + j + 1);
                    break;
                }
            }
            printf("single-character flag %c is enabled\n",argv[i][j]);
        }
    }
    return 0;
}