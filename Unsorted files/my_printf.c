#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

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
    * 
    * ANYWAYS hello again dear reader, today i plan to add decimals
    * my idea for this is to keep printing the moduluses of the number by large powers of 10 up untill 10^1
    * despite how confusing my wording was the algorithm is pretty simple, we just have to look for this 
    * "large power of 10"
    * my initial idea was to hardcode the closest power of 10 to the intiger limit 
    * but think of a method to understandably obtain it
    * so a beter method is to just find the closest power of 10 to the input intiger 
    * and by closest idk if its the closest larger or closest smaller intiger so ill go with larger just to be sure
    * too lazy to imagine it 
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
            {
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
            }
            case 'X':
            {
                char *hexboard = "0123456789ABCDEF";
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
            }
            case 'd':
                int num = va_arg(va_data,int);
                if (num < 0)
                {
                    putc('-',stdout);
                    num = -num;
                }
                int upper_p10 = 1;

                while ((num / upper_p10) >= 10)
                    upper_p10 *=10;
                
                while (upper_p10 > 0)
                {
                    putc((num/upper_p10) + '0',stdout);
                    num %= upper_p10;
                    upper_p10 /= 10;
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
    my_prinf("Your hex is %x\n",160);
    my_prinf("My hex is %X\n",1600);
    my_prinf("Your decimal is %d\n",1234);
    my_prinf("The biggest decimal is %d\n",INT_MAX);
    my_prinf("The smallest decimal is %d\n",-INT_MAX);





}