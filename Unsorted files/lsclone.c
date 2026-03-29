#include <stdio.h>
#include <dirent.h>

int main(void) {
    DIR *dir; 
    struct dirent *dir_entry; 

    dir = opendir(".");

    if (dir == NULL)
    {
        fprintf(stderr,"Could not open directory");
        return 1;
    }

    while ((dir_entry = readdir(dir)) != NULL)
    {
        printf("%s\n",dir_entry->d_name);
    }

    closedir(dir);

    return 0;

}
