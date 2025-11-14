#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
    * a program that takes a string and a string array,
    * then return an array of intiger holding the index of
    * every string in the array that starts with the input string
    * 
    * Okay so i remade a minimal version will try to document
    *
*/

int *search(char **strArr,const char *target)
{
    int *indices = NULL;
    size_t indicesLen = 0;

    for (int i = 0;strArr[i] != NULL;i++)
    {
        int j;
        for (j = 0;target[j] != '\0';j++)
        {
            if (strArr[i][j] != target[j]) break;
        }
        if (target[j] == '\0')
        {
            indices = realloc(indices,sizeof(int) * (indicesLen+2));
            indices[indicesLen] = i;
            indicesLen++;
        }
    }
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
        printf("%dth index has %s\n",indices[i],word);
    }
}