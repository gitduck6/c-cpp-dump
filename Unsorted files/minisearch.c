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
    // an array of indices that have our target string
    size_t indicesLen = 0; 
    // its length

    // iterate through every word
    for (int i = 0;strArr[i] != NULL;i++) 
    {
        int j;
        // declate outside the loop so we can access it in a sec
        for (j = 0;target[j] != '\0';j++)
        {   
            // if the jth letter of the word isnt the same as the target, move on
            if (strArr[i][j] != target[j]) break; 
        }
        // if we ARE at the end, and we did not "break" out of the previous loop then store the index in the array
        if (target[j] == '\0') 
        {
            // allocate memory, and set values here v
            indices = realloc(indices,sizeof(int) * (indicesLen+2)); 
            indices[indicesLen] = i;
            indicesLen++;
        }
    }
    // basically null termination but with -1 since any item could actually be a 0
    // null terminations are more popular in strings
    indices[indicesLen] = -1;
    return indices;

}

int main(void)
{
    char *temp[] = {"corns","thorn","cornfield",NULL};
    // our null terminated arraay of character arrays

    char **array = temp; // expects a char** so we give it thatt


    char word[] = "cor";

    int *indices = search(array,word);

    // loop through our indices untill we get to our terminator (-1)
    for (int i = 0;indices[i] != -1;i++)
    {
        printf("%dth index has %s\n",indices[i],word);
    }
    
    free(indices);
}