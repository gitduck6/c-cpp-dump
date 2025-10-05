#include <stdio.h>

float bsqrt(float input) {
    float bs = input / 2;
    for (int i = 0; i != 20 ;i++) {
        if ((bs * bs) > input) bs-= input / (2 << i);
        else if ((bs * bs) < input) bs+= input / (2 << i); 
    }

    return bs;
}

int main (void) {
    printf("%f\n",bsqrt(423));
}