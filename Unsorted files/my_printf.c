#include <stdio.h>
#include <stdarg.h>

int my_prinf(const char * format, ...)
{
    va_list va_data;
    va_start(va_data, format);

    char special = 0;

    for (int i = 0;format[i] != '\0';i++)
    {
        if (format[i] == '%')
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
    my_prinf("Your char is %c\n",'c');

}