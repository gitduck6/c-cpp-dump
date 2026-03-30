#include <stdio.h>

#if defined(__unix) || defined(__unix__)
    #include <dirent.h>
#elif defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
#endif


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
    * Hellooo this is me in the next day, today i added win32 support and ignored the hidden files
    * 
    *
*/

void list_dir(char * dir_name)
{
#if defined(__unix) || defined(__unix__)
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
        if (dir_entry->d_name[0] == '.') continue; //hidden file so we skip
        printf("%s\n",dir_entry->d_name);
    }

    closedir(dir);
#elif defined(_WIN32) || defined(_WIN64)

    WIN32_FIND_DATA file;
    HANDLE file_handle = NULL;
    char path[MAX_PATH];

    snprintf(path,sizeof(path),"%s\\*",dir_name); // turn  filename into filename\* to list ALL files instead of the folder itself 

    if ((file_handle = FindFirstFile(path, &file)) == INVALID_HANDLE_VALUE) 
    {
    fprintf(stderr, "Could not find specified directory!\n");
    exit(1); 
    }

    do {
    if (file.cFileName[0] == '.') continue;
    printf("%s\n", file.cFileName);
    } 
    while (FindNextFile(file_handle, &file));

    FindClose(file_handle);

#endif
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
