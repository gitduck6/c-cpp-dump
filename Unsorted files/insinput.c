#include <stdio.h>
#if defined(__WIN32)
    #include <conio.h>

#else
    #include <unistd.h>
    #include <termios.h>
char getch(void)
{
    struct termios oldattr, newattr;
    char ch;

    tcgetattr(STDIN_FILENO,&oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO,TCSANOW,&newattr);
    ch = getchar();
    tcsetattr(STDIN_FILENO,TCSANOW,&oldattr);
    return ch;
}
#endif
/*
    * instant input in the windows OS
    *
    * Now i will try toi make it "unix portable" i guess
    * CORRECTION : Me and my bestfriend chatgpt
    * Also testing might be faulty since i myself am not on a unixlike system
    * 
    * damn its actually almost slightly not too complicated, just a little tho
*/

int main(void)
{
    char ch = 0;

    while (1)
    {
        ch = getch();

        printf("You pressed char:%d\n",ch);

        if (ch == 'q') break;
    }
    return 0;
}