#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

char *consantrate(char *string1, char *string2) {
    int len = strlen(string1) + strlen(string2) + 1;
    char *combination = malloc(len);
    if (!combination) {
        perror("Memory allocation error\n");
        return NULL;
    }

    strcpy(combination,string1);
    strcpy(combination + strlen(string1),string2);

    return combination;

    // so after making ts guy i forget what he was for. damn
    // OH YEAH, the api link + the api key (maybe more in the later advanced stages)
}

int main (void) {
    CURL *curl = curl_easy_init();
    char *URL = "https://api.openweathermap.org/data/2.5/weather?lat=44.34&lon=10.99&appid=";
    if (!curl) {
        perror("Initilazing cURL failed.\n");
        return 1;
    }

    const char *filename = "weather-API.txt";
    // drop ur api key in a file called "weather-API.txt" or rename the file here for your needs

    FILE *fp = fopen(filename,"rb"); 
    if (!fp) {
        perror("Reading the file failed\n");
        return 0;
    }

    fseek(fp,0,SEEK_END); 
    long filesize = ftell(fp);
    rewind(fp);
    // the first of the 3 lines goees to the last byte, the second fetches the current position
    // and rewind takes our "cursor" back to the first biyte

    char *buffer = malloc(filesize + 1);
    if (!buffer) {
        perror("Memory allocation error");
    }

    int index = 0;
    for (int c;(c = fgetc(fp)) != EOF;index++) {
        buffer[index] = c;
    }
    buffer[filesize] = '\0';

    printf("%ld\n",filesize);
    printf("%s\n",buffer);

    free(buffer);
    fclose(fp);
    return 0;
}

// Okay uhh im back i give up on this code for now :O