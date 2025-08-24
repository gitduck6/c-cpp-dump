#include <stdio.h>
#include <string.h>
/*a program that writes "i am the Nth line" to every line, N being the lines index*/

int isSame(char * str1, char * str2) {
    int len;
    if ((len = strlen(str1)) != strlen(str2)) {
        return 0;
    }
    for (int i = 0;i < len;i++){
        if (str1[i] != str2[i]) {
            return 0;
        }
    }
    return 1;
}

int main(int argv, char **argc) {
    #ifdef CLEAR
    FILE * fp1 = fopen("myfile","wb");
    fclose(fp1); 
    printf("HEY vrooo u used  -DCLEAR :D");
    #endif
    /* These 3 lines clear the file, i forgot why i made this part :sob:
    this part will only run if you do it with the -DCLEAR option i think (i am NOT checking tho)
    ok maybe ill check bro if u insist
    i had to use a different var name cos like redefinition wasnt the compilers best recieved thing uhhh
    okay it worked, never use it tho pls =(
    okay actually use it, its handy sometimes, would be better if u could to it post compilation
    */

    if (isSame(argc[1],"clear")) {
    FILE * fp2 = fopen("myfile","wb");
    fclose(fp2); 
    printf("HEY vrooo u used the clear parameter :)");
    }


    int height;
    scanf("%d",&height);

    FILE * fp = fopen("myfile","ab");

    for (int i = 0;i < height;i++) {
        char arr[30];
        sprintf(arr,"I am the line number %d\n",i + 1);
        fwrite(arr,sizeof(char),strlen(arr),fp);
    }
    fclose(fp);

    return 0;
}