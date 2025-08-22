/*cat utility clone*/

#include "stdio.h"
#include "stdlib.h"

int main(int argc,char **argv) {

    if (argc < 2) {
        fprintf(stderr,"Usage: %s [file1] [file2] ...\n",argv[0]);
        return 1;
    }

    for (int i = 1;i<argc;i++) {

        FILE * fp = fopen(argv[i],"r");
        if (!fp) {
            //fprintf(stderr,"Unable to open the file %s",argv[i]); // we might not want an error message HERE
            continue;
        }

        for (int c;(c = fgetc(fp)) != EOF;) {
            fputc(c,stdout);

        }
        fclose(fp);
    }

    return 0;
}