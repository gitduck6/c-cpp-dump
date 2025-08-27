/*
making a student managing tool, using structs. 
i want this to be a little more long  term than others projects of mine.
objectives:
    utilize structs [done]
    Student definer [done]
    student look up []
    update students
maybes:
    save to non voliatile memory []
    Compare students []
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 50

struct Student
{
    char name[MAXLEN + 1];
    int age;
    float gpa;
    int id;
};

struct Student * stdlist = NULL;
int studn = 0;

void createStud(const char * name,int age,float gpa) {
    studn++;

    if (strlen(name) > MAXLEN) {
        perror("The given name is too long (50 characters max.)\n");
        studn--;
        return;
    }
    if (stdlist == NULL) {
        stdlist = malloc(sizeof(struct Student));
        if (stdlist == NULL) {
            studn--;
            perror("Memory allocation failuire\n");
            return;
        }
    } else {
        struct Student * temp = realloc(stdlist,(studn) * sizeof(struct Student));
        if (temp != NULL) {
            stdlist = temp;
            //free(temp); destroys our data ;o; DONT DO IT (took me some time to realize)
        } else {
            //error handling
            studn--;
            perror("Memory allocation failuire\n");
            return;

        }
    }
    //Now that the memory allocation part is over, ill set the values
    //stdlist[studn - 1].name = name; - THIS IS WRONG (apparently u must use strcpy to define arrays :P)
    strcpy(stdlist[studn - 1].name, name); // just sets our input array into the uhh heap
    stdlist[studn - 1].age = age;
    stdlist[studn - 1].gpa = gpa;
    stdlist[studn - 1].id = studn - 1;
    return;
}   

void printInfo(int studID) {
    struct Student currentStud = stdlist[studID];
    printf("UserID: %d\nName: %s\nAge: %d\nGPA: %.2f\n",studID,currentStud.name,currentStud.age,currentStud.gpa);
}

int main(int argc, char ** argv) {
    /*struct Student s1;
    scanf("stddef %s %d %f",s1.name,&s1.age,&s1.gpa); - "legacy" code idk :sob:
    */
    createStud("Red",21,6.7);
    createStud("Jimdy",19,3.5);
    printf("%s is %d years old and his/her gpa is %.2f\n",stdlist[1].name,stdlist[1].age,stdlist[1].gpa);
    //printf("%d",sizeof(struct Student));
    printInfo(1);
    free(stdlist);
    return 0;
}
