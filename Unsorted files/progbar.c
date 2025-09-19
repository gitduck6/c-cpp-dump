//progbar.c
#include <stdio.h>
#include <stdlib.h>

#if defined(_WIN32) || defined(_WIN64)
	#include <windows.h> 
	char os_type = 0;
	//time for windows systems
#elif defined(__unix__) || defined(__unix) || defined(__APPLE__) && defined(__MACH__)
	#include <unistd.h>
	char os_type = 1;

	//time for unix systems
#else 
	#include <time.h>
	char os_type = 2;
	//the more portable but inefficent one for unsupported systems
#endif
/* 
the os_type variable is just so i can know the operating system later
	windows - 0
	unix - 1
	other - 2
*/
#define LIM 20

void portWait(int secs) {
	switch (os_type)
	{
	case 0:
		Sleep(1000*secs);
		break;
	case 1:
		sleep(secs);
		break;
	case 2:
		clock_t start_time = clock();
		while ((double)(clock() - start_time) / CLOCKS_PER_SEC < secs);
		break;
	default:
		break;
	}
}

void printState(double ratio){
	fputc('[',stdout);

	for (double i = 1;i<(LIM+1);i++){
		if ((i/LIM) <= ratio)
			fputc('=', stdout);
		else 
			fputc('-', stdout);
	}
	fputc(']',stdout);
	//fputc('\n', stdout);

}

int main(int argc, char **argv){
	if(argv[1] == NULL) {
		fprintf(stderr,"Usage: %s [time]\n",argv[0]);
		return 1;
	}
	int dur = atoi(argv[1]) - 1;
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
	printf("Program done running. \n");
	return 0;
}
//i made this on my phone while we were on w car ride
//idk i was js bored