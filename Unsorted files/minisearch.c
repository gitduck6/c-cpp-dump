#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
    * a program that takes a string and a string array,
    * then return an array of intiger holding the index of
    * every string in the array that starts with the input string
    *
*/

int *search(char **strArr,const char *target)
{
    int *indices = NULL;
    size_t indicesLen = 0;

    char hasTarget = 0;

    for (int i = 0;strArr[i] != NULL;i++)
    {
         hasTarget = 0;

        for (int j = 0;strArr[i][j] != '\0';j++)
        {
            if ((strArr[i][j] == target[j]))
            {
                hasTarget = 1;
                
            } else if (target[j] != '\0')
            {
                hasTarget = 0;
                break;
            }
        }
        if (hasTarget) 
        {
            indicesLen++;
            indices = realloc(indices,indicesLen * sizeof(int));
            indices[indicesLen - 1] = i;
        }
    }
    indices = realloc(indices,(indicesLen + 1) * sizeof(int));
    indices[indicesLen] = -1;
    return indices;
}

int main(void)
{
    char *temp[] = {"corns","thorn","cornfield",NULL};

    char **array = temp;


    char word[] = "cor";

    int *indices = search(array,word);
    for (int i = 0;indices[i] != -1;i++)
    {
        printf("%dth index :%d\n",i,indices[i]);
    }
}