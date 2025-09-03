//parser.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **Parser(char *string){
    int stringNum = 1;
    int stringLen = 0;
    int currentLen = 0;
    int last = 0;
    
    int len = strlen(string);
    for (int i = 0;i < len;i++){
        if (string[i] == ' ') {
            if (!last) stringNum++;  
            last = 1;
        } 
        else {
            last = 0;
            currentLen++;
            if (currentLen > stringLen) stringLen = currentLen;
        } 
    }
    char *Strarray = malloc(stringNum * stringLen * sizeof(char));
//BROADPOAWDPOAWAD TS SO HARD I GIVE UP, ill do something else for now
//( ts is like a second part to my stdman.c)
// ALSO sorry for being a lil inactive
// ill stick to simpler stuf for now
}

int main(void) {

}