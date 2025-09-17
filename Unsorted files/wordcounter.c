//wordcounter.c
#include <stdio.h>



int main (int argc, char **argv) {

FILE *fp = fopen(argv[1],"rb");
int last = 1;

char c;
int counter = 0;
while ((c = fgetc(fp)) != EOF) {

	if (last && (c != '0')) counter++;	

	if (c == ' ') last = 1;
	else last = 0;	
}



printf("%d",counter);
fclose(fp);
return 0;
}
// also made in the car