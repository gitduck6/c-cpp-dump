// space1er.c
// Basically turns multiple spaces into one
// such as "Hello    World" turns into "Hello World"
#include <stdio.h>

void cleanPrint(char *string) {
    if (string == NULL) return;
    int last = 0;

    for (int i = 0; string[i] != '\0'  ;i++) {
        if (string[i] == ' ') {
            if (!last) {
            fputc(string[i],stdout);
            }
            last = 1;
        }
        else {
            fputc(string[i],stdout);
            last = 0;
        }
    }
    fputc('\n',stdout);
}

int main(void) {
    cleanPrint("    HELLO    GALACTICA  1123   ");
    return 1;
}

// ima try to get back on track by posting random useless stuff like this for now :3 git ass