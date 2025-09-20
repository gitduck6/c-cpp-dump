//ceacerchiper.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *cChiper(char *string, int shiftval) {
    if (string == NULL) {
        perror("string cannot be NULL\n");
        return NULL;
    }
    char *returnStr = malloc(strlen(string) + 1);

    while ((shiftval >= 13) || (shiftval <= -13)) {
        if (shiftval > 13) shiftval-= 26;
        else if (shiftval < -13) shiftval+= 26;
    }
    //this basically formats the shift value to a number between -13 and 13
    // looking back i have no idea why it wasnt 0-25
    int i = 0;
    for (;string[i] != '\0';i++) {
        returnStr[i] = string[i];
        char inRange = 0;
        if ((string[i] >= 'a') && (string[i] <= 'z')) inRange = 1;
        else if (('Z' >= string[i]) && ('A' <= string[i])) inRange = 2;
        // 0 will mean its NOT in range, 1 will mean its lowcase 2 will be uppcase

        if (inRange == 2) {
            returnStr[i] += shiftval;
            if ('Z' < returnStr[i]) returnStr[i] -= 26;
            else if ('A' > returnStr[i]) returnStr[i] += 26;
        }
        else if (inRange == 1) {
            returnStr[i] += shiftval;
            if ('z' < returnStr[i]) returnStr[i] -= 26;
            else if ('a' > returnStr[i]) returnStr[i] += 26;
        }

    }
    returnStr[i] = '\0';
    return returnStr;
}

int main(void) {
    int shiftval;
    char *string;
    printf("Please enter a string...\n");
    scanf("%s",string);

    printf("Please enter the shift value...\n");
    scanf("%d",&shiftval);

    printf("The ceaser cipher of your string with %d shift value is\n",shiftval);
    printf("%s",cChiper(string,shiftval));
    return 0;
}

/*
NOTES:
so when i was testing it this happend.
**
Please enter a string...
Hello Chromiumialiatinquajo
Please enter the shift value...
The ceaser cipher of your string with 504 shift value is
Rovvy
**
i dont know how that happend tho:sob:

okay so it happend again? but with 410 now

Okay it seems it happens due to spaces
but i dont remmember touching spaces in any unusual way

*/