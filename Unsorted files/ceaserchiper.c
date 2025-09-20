//ceacerchiper.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *cChiper(char *string, int shiftval) {

char *returnStr = malloc(strlen(string) + 1);

while ((shiftval >= 13) || (shiftval <= -13)) {
    if (shiftval > 13) shiftval-= 26;
    else if (shiftval < -13) shiftval+= 26;
}
//this basically formats the shift value to a number between -13 and 13
int i = 0;
for (;string[i] != '\0';i++) {
    returnStr[i] = string[i];
    char inRange = (90 >= string[i]) && (65 <= string[i]);
    if (inRange) {
        returnStr[i] += shiftval;
        if (90 < returnStr[i]) returnStr[i] -= 26;
        else if (65 > returnStr[i]) returnStr[i] += 26;
    }

}
returnStr[i] = '\0';
return returnStr;
}

int main(void) {
    printf("%s",cChiper("hello WORLD",10));
}