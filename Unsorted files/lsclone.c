#include <stdio.h>
#include <dirent.h>

int main(int argc, char** argv) {

    if (argc != 2)
    {
        fprintf(stderr,"usage: %s [directory_name]",argv[0]);
        return 1;
    }

    DIR *dir; 
    struct dirent *dir_entry; 

    dir = opendir(argv[1]);

    if (dir == NULL)
    {
        fprintf(stderr,"Could not open directory");
        return 2;
    }

    while ((dir_entry = readdir(dir)) != NULL)
    {
        printf("%s\n",dir_entry->d_name);
    }

    closedir(dir);

    return 0;

}
