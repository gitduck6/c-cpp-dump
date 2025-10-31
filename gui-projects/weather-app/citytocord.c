#include "curl/curl.h"
#include "string.h"
#include "cJSON.h"

/*
    * This is the first part of the weather app i decided to code
    * it takes the name of the city and returns its longtitude and latitude 
    * (WE failing in life with this one)
    *  
*/

size_t write_callback(void *contents,size_t size, size_t nmemb,void *UNUSED)
{
    cJSON *root = cJSON_Parse(contents);
    if (root == NULL)
    {
        fprintf(stderr,"cjson failure : 1\n");
        return 0;
    }
    cJSON *results = cJSON_GetObjectItem(root,"results");
    if (results == NULL)
    {
        fprintf(stderr,"cjson failure : 2\n");
        return 0;
    }

    cJSON *firstResult = cJSON_GetArrayItem(results,0);
    if (!cJSON_IsObject(firstResult))
    {
        fprintf(stderr,"Not an object\n");
        return 1;
    }

    cJSON *lat = cJSON_GetObjectItem(firstResult, "latitude");
    cJSON *lon = cJSON_GetObjectItem(firstResult, "longitude");

    if (cJSON_IsNumber(lon) && cJSON_IsNumber(lat))
    {
        printf("%f %f\n",lat->valuedouble,lon->valuedouble);
    }
    cJSON_Delete(root);
    return size * nmemb;
}

void cityToCord(char *city)
{
    if (city == NULL) 
    {
        fprintf(stderr,"City must be a cstring\n");
        return;
    }

    int urlSize = 150;
    char *URL = malloc(urlSize * sizeof(char));
    char *URLprefix = "https://geocoding-api.open-meteo.com/v1/search?name=";
    char *URLpostfix = "&count=1";

    // "construct" the url
    strcpy(URL, URLprefix);
    strncat(URL, city, urlSize - strlen(URL) - 1);
    strncat(URL, URLpostfix, urlSize - strlen(URL) - 1);

    CURL *curl = NULL;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl != NULL)
    {
        curl_easy_setopt(curl, CURLOPT_URL,URL);
        curl_easy_setopt(curl, CURLOPT_CAINFO, "curl\\cacert.pem");
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "WAPP-test");

        curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,write_callback);
        res = curl_easy_perform(curl);

        if (res != CURLE_OK)
        {
            fprintf(stderr,"Curl failed : %s\n",curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return;

}

int main(void)
{
    printf("Hello world\n");
    cityToCord("Berlin");
    return 0;
}