//progbar.c
#include <stdio.h>
#include <stdlib.h>

#if defined(_WIN32) || defined(_WIN64)
	#include <windows.h> 
	//time for windows systems
#elif defined(__unix__) || defined(__unix) || ( defined(__APPLE__) && defined(__MACH__) )
	#include <unistd.h>
	//time for unix systems
#endif
#define LIM 20

void portWait(int secs) {
#if defined(_WIN32) || defined(_WIN64)
	Sleep(1000 * secs);
	// time for windows systems
#elif defined(__unix__) || defined(__unix) || ( defined(__APPLE__) && defined(__MACH__) )
	sleep(secs);
	// time for unix systems
#endif
// These # conditionals are called "preprocessor directive"
// Theyre handled durng compilation i think
// due to this they were not willing to work with variables
}

void printState(double ratio){
	fputc('[',stdout);

	for (double i = 1;i<(LIM+1);i++){
		if ((i/LIM) <= ratio)
			fputc('=', stdout);
		else 
			fputc('-', stdout);
	}
	printf("] - %.1f %%",ratio * 100);
	// closes the square bracket prints the ratio as a %
}

int main(int argc, char **argv){
	if(argv[1] == NULL) {
		fprintf(stderr,"Usage: %s [time]\n",argv[0]);
		return 1;
	}
	int dur = atoi(argv[1]);
	int timer = 0;
	fflush(stdout);

	while(timer <= dur){
		printState((double)timer/dur);
		fflush(stdout);
		portWait(1);
		printf("\r\033[K");
		//fflush(stdout);
		timer++;
	}
	// fflush sends your message directly to the output handle (stdout in this case)
	// your every print statement, fwrite, or anything alike will keep the message that needs to be printed in a buffer
	// and this buffer is only "flushed" when theres a newline OR you fflush() it manually
	printf("Program done running. \n");
	return 0;
}


//i made this on my phone while we were on w car ride
//idk i was js bored