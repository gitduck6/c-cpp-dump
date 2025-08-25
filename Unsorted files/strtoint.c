/*
a simple algorithm which
takes a string of numbers and 
converts them into an intiger
"10" -> 10 for example

ill take advantage of how the intigers come after 47th ascii character
48 = '0' 49 = '1' and so on...
we can (in a very basic sense) think of it as 'n' = n+48 or 'n'-48 = n

theres a function with a similar function "atoi" which is included in string.h
so my thing will be pretty pointles
*/
#include <stdio.h>
#include <string.h>

int Pow10(int exp) {
    int val = 1;
    for (int i = 0;i < exp;i++) {
        val *= 10;
    }
    return val;
}

int strToInt(const char * string) {
    int len = strlen(string);
    int returnVal = 0;
    for (int i = len - 1;i >= 0;i--) { 
        returnVal += (string[i] - '0') * Pow10(len - i - 1);// ai said to use '0' instead of 48, its so ovwer
    }
    return returnVal;
}


int main(int argc, char ** argv) {
    //char * str = "483";
    printf("%d",strToInt(argv[1]) + 2);
    return 0;
}