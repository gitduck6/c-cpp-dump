#include <stdio.h>
#include <string.h>

/*
    * This c program is a fun little utility to evaluate the "compatability" chance of 2 strings,
    * presumabily names, presumabily of people.
    * 
    * My current idea is to always return the same value  for 2 different names
    * and a little "goal" i currently have is to make my own "randomness function"
    * 
    * my idea of this randomness is inspired by a thing i saw some time ago
    * the main process was to add c*(2^n) for every nth index of our strings (c being the value of every character), then sum OR multiply the answers
    * after all this find its modul from a division to 100, and thats your "compatability chance"
    * 
    * while yes, this might cause buffer overflows we will try to use them for our advantage
    * since theyre somewhat predictable. e.g.: UINT_MAX + 1 = 0
    * i should mention that we will use unsigned integers
    * 
    * also i kinda missed day 4 didnt i?
    * 
    * ima go with multiplication, since its a little more "chaotic"
    * i tried multiplication but the values were coming out to be often too high
    * this seems to be less of an issue with addition
    * 
    * idk why im not a mathematician 
*/

int main(void)
{
    int compatability;

    char person1[32];
    char person2[32];

    unsigned int randn1 = 0;
    unsigned int randn2 = 0;

    printf("Please enter the name of the first person!\n");
    fgets(person1,sizeof(person1) - 1,stdin);

    printf("Please enter the name of the second person!\n");
    fgets(person2,sizeof(person2) - 1,stdin);
    
    person1[strcspn(person1,"\n")] = '\0';
    person2[strcspn(person2,"\n")] = '\0';


    for (int i = 0;person1[i] != '\0';i++)
    {
        randn1 += (person1[i] * (1 << i));
    }
    for (int i = 0;person2[i] != '\0';i++)
    {
        randn2 += (person2[i] * (1 << i));
    }
    
    compatability = (randn1+randn2) % 100;
    printf("Compatability between %s and %s is %d%%\n",person1,person2,compatability);
}