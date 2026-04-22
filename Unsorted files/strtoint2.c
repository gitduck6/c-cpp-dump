
#include <stdio.h>

/*
    * Took me like more than an hour till i figured out there was a missing semi-colon
    * im such an idiot
*/


int my_atoi(const char *nptr){

    int value = 0;
    int len;
    for (len = 0;nptr[len] != '\0';len++);

    for (int i = 0;i < len;i++)
    {
        if (('0' <= nptr[i]) && ('9' >= nptr[i]))
        {
            value = (value * 10) + (nptr[i] - '0');
        }
        else break;
    }


    return value;
}

int main(void)
{
    char *arr = "136";
    int my_int = my_atoi(arr);
    printf("%d",my_int);
    return 0;
}
