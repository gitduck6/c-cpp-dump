//parser.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//BROADPOAWDPOAWAD TS SO HARD I GIVE UP, ill do something else for now
// ( ts is like a second part to my stdman.c)
// ALSO sorry for being a lil inactive
// ill stick to simpler stuf for now
// ima try making a very simple and incapable version, ive been busy sorry

// this version will just take a string like "Hello World" and print it as "Hello\nWorld"

// OMGAS DAPOSDASOPDASODASPOd kill me
// i am not parsing anytime soon again

// // BTW IM DOING A NEW thing - no ai for a week (things like chatgpt specificly)
// okay hello parser, ill try again...
// THE ALGORITHM WILL BE LKIKE TS:
// we iterate through our string untill ( c =! '\0') - the current character isnt a null terminator
// if we are at a space... Man ima write ts after the coding part 

// okay so im doinhg somehting, i js dont know what. i miss chatgpt bro...

char *cleanf(const char *string) {
    // this is from the space1er.c file, ill modify it a bit
    if (string == NULL) return NULL;
    int last = 1;
    int index = 0;
    char *returnString = malloc(strlen(string));
    if (returnString == NULL) {
        perror("Memory allocation failiure\n");
        return NULL;
    }

    for (int i = 0; string[i] != '\0'  ;i++) {
        if (isspace(string[i])) {
            if (!last) {
            //fputc(string[i],stdout);
            returnString[index++] = string[i];
            //index++;
            }
            last = 1;
        }
        else {
            //fputc(string[i],stdout);
            returnString[index++] = string[i];            
            //index++;
            last = 0;
        }
    }
    if (returnString[index - 1] == ' ') {
        returnString[index - 1] = '\0';     
    }
    else {
    returnString[index] = '\0';     
    } 

    return returnString;      
    //fputc('\n',stdout);
}

char **Parse(char string[]) {
    strcpy(string, cleanf(string)); // i believe the issue is here..?
    int words = 0;
    int index = 0;
    int lastSpace = 0;
    int currentWord = 0;
    int currentLen;
    for (int i = 0;string[i] != '\0';i++) {
        if (isspace(string[i])){
            words++;
        }
    }
    char **parsedStrings = malloc(sizeof(char *) * words); // an array of strings heh
    if (parsedStrings == NULL) {
        perror("Memory allocation failiure\n");
        return NULL;
    }
    for (int i = 0;string[i] != '\0';i++) {
        if (isspace(string[i])) {
            currentLen = i - lastSpace;
            lastSpace = i;
            parsedStrings[currentWord] = malloc(currentLen * sizeof(char));
            if (parsedStrings[currentWord] == NULL) {
                perror("Memory allocation failiure\n");
                return NULL;
            }
            currentWord++;
        }
        index = i - lastSpace;
        parsedStrings[currentWord][index] = string[i];

    }

    return parsedStrings;

}

int main(void) {
    printf("%s\n",cleanf("  Hello    WOrlds 12 22  "));
    printf("%s\n",cleanf("hi"));

    return 0;
}

// PS before publication:
/*
    i am still trying to get this to work but it might take a while
    im kinda inactive sry
*/