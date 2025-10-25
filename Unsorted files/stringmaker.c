//stringmaker.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    * This is basically a string system, similar to my "studman.c" but with strings
    * i feel like my ability has gotten alot worse, since i stopped coding in c
    * i kinda stopped trying after realising C is kinda obsolete and i should learn a new language
    * but to be fair that makes me no different than me when i kept "language hopping"
    * so i will try my best to "post" atleast once a week
    * Even is C might actually be obsolete, this is just a hobby to learn about "computing" on a lower level
    * 
    * C is a veri goated language, SO IS THE READER BTW :D
    * ur not a programming language tho i hope
    * 
    * 
    * after coding the most part, i realize how much i missed this language
    * EVEN THO it has only been a week and it made me disregard all my homework
    * 
    * C is almost 40 years older than me but its still my favorite for some reason
*/

char **strArray = NULL;
size_t stringCount = 0;

void mkStr(const char* str)
{
    void *temp = NULL;
    if (stringCount <= 0)
    {
        temp = malloc(sizeof(char*) * (stringCount + 2));
        if (temp == NULL)
        {
            fprintf(stderr,"Mallocation failure\n");
            return;
        }

        strArray = (char **)temp;
    }
    else if (stringCount > 0)
    {
        temp = realloc(strArray,sizeof(char*) * (stringCount + 2));
        if (temp == NULL)
        {
            fprintf(stderr,"Mallocation failure\n");
            return;
        }
        
        strArray = (char **)temp;
    }
    temp = malloc(strlen(str) + 1);
    if (temp == NULL)
    {
        fprintf(stderr,"Mallocation failure\n");
        return;
    }
    strArray[stringCount] = (char *)temp;
    strArray[stringCount + 1] = NULL; // Null terminate the array for the ease of iterating
    strcpy(strArray[stringCount],str);
    stringCount++;
}

void strList(void)
{
    for (int i = 0;strArray[i] != NULL;i++)
    {
        printf("[%d] : %s\n",i,strArray[i]);
    }
}

void clearFile(const char * filename)
{
    FILE * ftc = fopen(filename,"w");
    fclose(ftc);

}

void saveToFile(const char* filename)
{
    clearFile(filename);
    FILE *fp = fopen(filename,"ab");
    if (fp == NULL)
    {   
        fprintf(stderr,"Failed to open file.");
        return;
    }
    for (int i = 0; strArray[i] != NULL;i++)
    {
        fwrite(strArray[i],strlen(strArray[i]),sizeof(char),fp);
        fputc('\n',fp);
    }
}

void loadFromFile(const char* filename)
{
    FILE *fp = fopen(filename,"rb");
    char buffer[256] = {0};

    while(fgets(buffer,sizeof(buffer),fp) != NULL)
    {
        mkStr(buffer);
    }
}
int main(void)
{
    loadFromFile("test.txt");

    mkStr("Hello world!");
    mkStr("AASDASD hello");
    mkStr("I am string #3 or 2 depending on the context");

    saveToFile("test.txt");

    strList();

    return 0;
}