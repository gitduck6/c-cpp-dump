#include <stdio.h>
#include <stdarg.h>

/*
    * minimal reimplementation of the printf stdio function for fun:
    *
    * This is actually alot simpler than i thougt and im very happy for that
    * we simply go through the array when we see percentage sign
    * (which is what format specifiers start with - %c %d etc)
    * then take the next character and act accordingly
    * for example treat the format argumetn thingy as a character in case of %c
    * 
    * By the way, these are called varadaic functions and this was my first time working with them
    * so the code might be a little messy 
    * 
    * currently theres only %c and %%, ill try to add hex now
    * 
    *
*/

int my_prinf(const char * format, ...)
{
    va_list va_data;
    va_start(va_data, format);

    char special = 0;

    for (int i = 0;format[i] != '\0';i++)
    {
        if ((!special) && (format[i] == '%'))
        {
            special = 1;
            continue;
        }

        if (special)
        {
            special = 0;
            /*
                * This is where we treat cases of special format specifiers (e.g. %c)
                * ill first implement characters since that seems the simplest
            */
            switch (format[i])
            {
            case 'c':
                putc(va_arg(va_data,int),stdout);
                break;
            case '%':
                putc('%',stdout);
                break;
            
            default:
                break;
            }
        }
        else 
        {
            putc(format[i],stdout);
        }


    }

    va_end(va_data);
}

int main(void)
{
    my_prinf("Your char %%is %c\n",'c');

}