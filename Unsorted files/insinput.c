#include <stdio.h>
#if defined(__WIN32) || defined(_WIN32)
    #include <conio.h>

#else
// basically, if we arent in windows do these:
    #include <unistd.h>
    #include <termios.h>
char getch(void)
{
    // the variables:
    struct termios oldattr, newattr; //to store the new and original "config files"
    char ch; // what we'll return

    tcgetattr(STDIN_FILENO,&oldattr);// get the config thing of stdin and store it in oldattr
    newattr = oldattr;
    newattr.c_lflag &= ~(ECHO | ICANON);
    /*
        * bitwise operator magic ~ is the NOT operator
        * so 1010 turns into 0101, or something like that, then & turns off those bits
        * turning off ECHO stops characters we type from being seen
        * while ICANON makes the characters get inputted instantly, without a NEWLINE
    */
    tcsetattr(STDIN_FILENO,TCSANOW,&newattr); //sets the new attribute
    ch = getchar();// getchar's with the new configuration
    tcsetattr(STDIN_FILENO,TCSANOW,&oldattr);// goes back to the previous config
    return ch;//returns our char
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
    * 
    * ima try to explain now
    * SO conio does what i want with getch, but the problem is that its only in windows
    * therefore you gotta make ur own getch for unix, which introduces things ive neverseen
    * such as the termios header
    * 
    * Okay so it works in an ubuntu vm i hope it works everywhere else too
    * 
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