#include <stdio.h>
#include <dirent.h>

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
        list_dir(argv[i]);
    }

    return 0;
}
