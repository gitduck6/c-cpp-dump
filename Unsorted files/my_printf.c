#include <stdio.h>
#include <stdarg.h>

#define NIBBLE_BITS      4
#define INTIGER_BITS     sizeof(int) * 8


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
    * Hello! today i added hexadecimal format specifiers, but it prints with excessive zeros
    * example: 00000064 instead of 64, a simple fix for this would be a variable indicating if a
    * non-zero has appeared up to this point in the iteration while printing those zeros
    * if this variable is true then print the character, if not (and this is just an excess zero in the start)
    * then just dont print it!
    * i hope it made sense i guess :sob:
    * 
    * IT WORKS :) lemme add larger hexes tho (%X)
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
            case 'x':
                char *hexboard = "0123456789abcdef";
                int num = va_arg(va_data,int);
                char non_zero_occured = 0;
                for (int i = (INTIGER_BITS - NIBBLE_BITS);i >= 0;i-=NIBBLE_BITS)
                {
                    char nibble = (num >> i) & 0xf;
                    if ((nibble == 0) && (!non_zero_occured))
                        continue;
                    else 
                    {
                        non_zero_occured = 1;
                        putc(hexboard[nibble],stdout);
                    }
                }
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
    my_prinf("Your char is %c\n",'c');
    my_prinf("Your hex is %x",1600);

}