/*
making a student managing tool, using structs. 
i want this to be a little more long  term than others projects of mine.
objectives:
    Utilize structs [done]
    Student definer [done]
    Student look up [done]
    Modify student data [done]
    A full cli app []
maybes:
    save to non voliatile memory []
    Compare students []

    Notes: damn 130 lines already (90% of them are comments lmao)
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

char *lowCase(char *input) {
    if (!input) return NULL;

    for (int i = 0;input[i] != '\0';i++) {
        if ((input[i] <= 'Z') && (input[i] >= 'A')) {
            input[i]  += 32;
        }
    }
    return input;
}
// after commiting i realize now this function was not used i think - 8/29/25

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

void studLookup(int studID) {
    struct Student currentStud = stdlist[studID];
    printf("UserID: %d\nName: %s\nAge: %d\nGPA: %.2f\n",studID,currentStud.name,currentStud.age,currentStud.gpa);
}

void modAttr(char *attr,int studID) {
    /*ill aim to make thing function into a sort of an attribute modifier hence the name
    it will take 2 arguments the attribute to modify, and whichever student to modify.
    */

    if (studID >= studn) {
        perror("Student with the ID doesnt exist.\n");
        return;
    }

    if (!strcmp(attr,"gpa")) {
        printf("Please enter the new gpa value:\n");
        scanf("%f",&stdlist[studID].gpa);
    }
    else if (!strcmp(attr,"age")) {
        printf("Please enter the new age value:\n");
        scanf("%d",&stdlist[studID].age);
    }
    else if (!strcmp(attr,"name")) {
        printf("Please enter the new name value:\n");
        fgets(stdlist[studID].name,sizeof(stdlist[studID].name),stdin);       
        
        //I dont like how fgets adds a newline at the end of our silly little return value gimme a sec

        size_t len = strlen(stdlist[studID].name);
        if (stdlist[studID].name[len-1] == '\n') stdlist[studID].name[len-1] = '\0';

        // there we go, later ill try to add something that keeps asking for a value untill it isnt empty or invalid
        // (giving a character when asking for an intiger for example)
    }
    return;

}

char **inputParser (char * string){ 
    char inQuote = 0;
    char last = 0; // if the last letter was ' ' - space
    int len = strlen(string);
    int extraLen = 0;

    for (int i = 0;i < len;i++) {
        if (string[i] == '"') {
            inQuote = !inQuote;
            if (!inQuote) extraLen--;
        }
        if (!inQuote) {
            if (string[i] == ' ') {
                last = 1;
                break;
            }
            else if (last == 1){

            };
        }   
    }
}//THIS SHIT IS SO FUCKING HARD WTFFFF

int main(int argc, char ** argv) {
    int running = 1;
    char *input = malloc(100);
    printf("Welcome to student manager.\n");
    while (running) {
        printf("> ");
        
    }

    free(stdlist);
    return 0;
}
