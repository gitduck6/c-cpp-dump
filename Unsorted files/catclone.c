/*cat utility clone*/

#include "stdio.h"
#include "stdlib.h"
//you can use both <> and "" (usually used if the header is in this directory)

int main(int argc,char **argv) {
    /*argc is the amount of inputs. the commands name also counts as a parameter, therefore it will always be atleast 1.
    argv is basically a string array, holding each parapeter in the streak format.*/

    if (argc < 2) {
        fprintf(stderr,"Usage: %s [file1] [file2] ...\n",argv[0]);
        return 1;
    }
    /*this part basically stops the command if you have no parameters aside from the command itself*/

    for (int i = 1;i<argc;i++) {

        FILE * fp = fopen(argv[i],"r"); //open the 'i'th parameter with the 'read' option
        if (!fp) {
            //fprintf(stderr,"Unable to open the file %s",argv[i]); // we might not want an error message HERE
            continue;//if the file isnt found, go to the next file
        }

        for (int c;(c = fgetc(fp)) != EOF;) {
            fputc(c,stdout);       
        }
        /*
            This part might seem a little confusing at first.
        the initalization part declares a char variable which will hold our letters and then we will use the variable to print the letters.  
        in the condition part we also set c to fgetc(fp), if its not EOF(end of file) we continue
        fgetc gives u the Nth element of a file the Nth time you use it, so essentially the first time u call it u will get the 1st letter,
        the second in the second and so on.
        the contents of the loop is very simple, fputc just prints a char variable to a stream so, the character C goes to standart output.
        this loop continues untill we have every letter of every file, tho it is a bit slow.

        PS: i might experiment with a version which prints file by file or something.
        */

        fclose(fp);//close each file after the printing
    }

    return 0; //safely exit
}