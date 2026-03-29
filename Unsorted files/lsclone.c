#include <stdio.h>
#include <dirent.h>

/*
    * Hello, this was just a quick "reimplementation" of the well-known ls shell utility
    * i barely code anymore, and i notice how much my skills have worsened
    * i hope i can fix it :)
    * 
    * anyway for now this program works only in unix-like systems
    * i tried to add something with win32 ifdefs but some ls alternative i found on microsofts website was too complex
    * so i just gave up on that
    * atleast for today
    * 
    * the basic algorithm:
    * if there are no arguments (excluding argv[0]), list the current directory (".")
    * for every argument, you list that argument,
    * and if the amount of arguments is larger than 1 (again excluding the programs name)
    * you print the name of the file before listing
    *
*/

void list_dir(char * dir_name)
{
    DIR *dir; 
    struct dirent *dir_entry; 
    dir = opendir(dir_name);

    if (dir == NULL)
    {
        fprintf(stderr,"Could not open directory '%s'\n",dir_name);
        return;
    }

    while ((dir_entry = readdir(dir)) != NULL)
    {
        printf("%s\n",dir_entry->d_name);
    }

    closedir(dir);
}

int main(int argc, char** argv) 
{
    if (argc == 1) list_dir(".");

    for (int i = 1;i < argc;i++)
    {
        if (argc > 2) printf("%s:\n",argv[i]);
        list_dir(argv[i]);
    }

    return 0;
}
