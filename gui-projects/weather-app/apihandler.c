#include "curl/curl.h"
#include "string.h"
#include "cJSON.h"
#include "apihandler.h"

/*
    * This is the first part of the weather app i decided to code
    * it takes the name of the city and returns its longtitude and latitude 
    * (WE failing in life with this one)
    *  
*/

static Cord location;


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
        cJSON_Delete(root);
        return 0;
    }

    cJSON *firstResult = cJSON_GetArrayItem(results,0);
    if (!cJSON_IsObject(firstResult))
    {
        fprintf(stderr,"Not an object\n");
        cJSON_Delete(root);
        return 1;
    }

    cJSON *lat = cJSON_GetObjectItem(firstResult, "latitude");
    cJSON *lon = cJSON_GetObjectItem(firstResult, "longitude");

    if (cJSON_IsNumber(lon) && cJSON_IsNumber(lat))
    {
        //printf("%f %f\n",lat->valuedouble,lon->valuedouble);
        location.lat = (float)lat->valuedouble;
        location.lon = (float)lon->valuedouble;

    }
    cJSON_Delete(root);
    return size * nmemb;
}

size_t weather_callback(void *contents,size_t size, size_t nmemb,void *UNUSED)
{
    fwrite(contents,size,nmemb,stdout);
    return size * nmemb;
}

Cord cityToCord(char *city)
{
    if (city == NULL) 
    {
        fprintf(stderr,"City must be a cstring\n");
        return (Cord){0,0};
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
        curl_easy_setopt(curl, CURLOPT_CAINFO, "curl/cacert.pem");
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "WAPP-test");

        curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,write_callback);
        res = curl_easy_perform(curl);

        if (res != CURLE_OK)
        {
            fprintf(stderr,"Curl failed : %s\n",curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            return (Cord){0,0};

        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return location;

}

float getWeather(void)
{
    //https://api.open-meteo.com/v1/forecast?latitude=0&longitude=0&hourly=temperature_2m&current=rain,snowfall,showers
    //Constructing the api URL
    char strLong[16];
    char strLat[16];
    snprintf(strLat,sizeof(strLat),"%f",location.lat);
    snprintf(strLong,sizeof(strLong),"%f",location.lon);
    char URL[256] = "https://api.open-meteo.com/v1/forecast?latitude=";
    strcat(URL,strLat);
    strcat(URL,"&longitude=");
    strcat(URL,strLong);
    strcat(URL,"&hourly=temperature_2m&current=rain,snowfall,showers");

    CURL *curl = NULL;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl != NULL)
    {
        curl_easy_setopt(curl, CURLOPT_URL,URL);
        curl_easy_setopt(curl, CURLOPT_CAINFO, "curl\\cacert.pem");
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "WAPP-test");

        curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,weather_callback);
        res = curl_easy_perform(curl);

        if (res != CURLE_OK)
        {
            fprintf(stderr,"Curl failed : %s\n",curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            return 0;

        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();

}

int main(void)
{
    
    cityToCord("Berlin");
    //printf("LATITUDE IS %f %f\n",location.lat,location.lon);
    getWeather();
    return 0;
}