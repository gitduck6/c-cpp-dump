#include <math.h>
#include <stdio.h>
#include <stdlib.h>
/*
    * Im just leetcodin yall, and thought why not post it(my best friend ai helped)
*/

char isNoZero(int c)
{
    if (c == 0) return 0;

    while (c > 0)
    {
        if (c % 10 == 0)
            return 0;

        c /= 10;
    }

    return 1;
}

int* getNoZeroIntegers(int n, int* returnSize) {
    int *array = malloc(sizeof(int) * 2);
    for (int i = 1; i < n;i++)
    {
        if (!isNoZero(i)) continue;
        if (isNoZero(n - i))
        {
            array[0] = n - i;
            array[1] = i;
            return array;

        }
    }
    printf("%d + %d = %d\n",array[0],array[1],n);
    return array;
}



int main(void)
{

    int *array = getNoZeroIntegers(100,NULL);
    printf("%d + %d\n",array[0],array[1]);

    
}