#include "stdio.h"
#include "curl/curl.h"
#define DESTINATION "kitty.png"

/*
    * Okay so this program basically fetches a picture of a cat from the internet
    * and saves it into kitty.png, the code is mostly ai and i do not understand 
    * a part of it, but it is my first time actually succeeding in fetching apis
    * so i am happy about that
    * 
    * 
*/

size_t write_callback(void *ptr, size_t size, size_t nmemb, void *userdata)
{
    FILE *fp = (FILE *)userdata;
    return fwrite(ptr,size,nmemb,fp);
}

int main(void)
{
    CURL *curl;
    CURLcode res;

    // initilase curl
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl)
    {
        //open file
        FILE *fp = fopen(DESTINATION,"wb");
        if (!fp)
        {
            fprintf(stderr,"Opening the file failed.\n");
            return 1;
        }

        /*
            1.Set the url
            2.get the "https certificates" i think 
            3.lets the server know what the app is
            4.does the "write_callback" function on every chunk of data fetched
            5.makes sure to write every chunk to our file

            6.And the last line performs it all
        */
        curl_easy_setopt(curl, CURLOPT_URL,"https://placekittens.com/200/300");
        curl_easy_setopt(curl, CURLOPT_CAINFO, "curl\\cacert.pem");
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl-c-example");

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA,fp);
        res = curl_easy_perform(curl);

        //Check for errors
        if (res != CURLE_OK)
        {
            fprintf(stderr,"curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        //Clean ups ig
        curl_easy_cleanup(curl);
        fclose(fp);
    }
    curl_global_cleanup();
    return 0;
}