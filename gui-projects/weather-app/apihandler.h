#pragma once
#include <stdio.h>

typedef struct 
{
    float lon;
    float lat;
} Cord;

size_t write_callback(void *contents,size_t size, size_t nmemb,void *UNUSED);
Cord cityToCord(char *city);