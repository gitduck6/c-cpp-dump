#include <stdio.h>
#include <stdlib.h>


/*
    * a program that can find the greatest common divisor(GCD)
    * and the smallest common divided(SCD) of any 2 numbers
    * I made the second one's name up, but im pretty sure it exists in math too
*/

int GCD(const int x,const int y)
{
    //Greatest common divisor
    if (x == y) return x;

    int small = (x < y) ? x : y ;
    
    int gcd = 1;
    for (int i = 1;i <= small ;i++) 
    {
        if (((x % i) == 0 ) && (y % i) == 0)
        {
            gcd = i;
        }
    }
    return gcd;
}

int SCD(const int x, const int y)
{
    int scd = x * y;

    for (int i = 1; i <= scd;i++)
    {
        if ((((scd / i) % x) == 0) && (((scd / i) % y) == 0))
        {
            scd = x * y / i;
        }
    }
    return scd;
}
/*
    * Okay the both of the algorithms are very inefficient,
    * being ATLEAST O(n), while ai said it could be O(log N) with some euclid algo
    * but id rather post my own algorithm
    *
*/

int main(void)
{
    printf("%d\n",SCD(1,15));
    printf("%d\n",SCD(1,213));
    printf("%d\n",SCD(222,12));
    printf("%d\n",SCD(12,32));

    printf("%d\n",GCD(10,15));
    printf("%d\n",GCD(22,15));
    printf("%d\n",GCD(1,1));
    printf("%d\n",GCD(8,4));
    printf("%d\n",GCD(106,212));

    return 0;
}