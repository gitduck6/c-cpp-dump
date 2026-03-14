#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    * a poorly made http parser i definitly need to improve
    * for example manage the memory better
    *
*/

typedef struct
{
    char * method;
    char * target;
    char * raw;
}
hRequest;

hRequest initRequest(char *rawRequest)
{
    hRequest request;
    memset(&request,'\0',sizeof(hRequest));

    request.raw = rawRequest;
    
    int i;
    request.method = malloc(32);
    request.target = malloc(32);


    for (i = 0;(rawRequest[i] != 0) && (rawRequest[i] != ' ');i++)
    {
        request.method[i] = rawRequest[i];
    }
    request.method[i] = '\0';
    i++;
    int j = i;
       
    for (;(rawRequest[i] != '\0') && (rawRequest[i] != ' ');i++)
    {
        request.target[i-j] = rawRequest[i];
    }
    request.target[i-j] = '\0';

    return request;
    
}

int main(void)
{
    char req[] =
    "GET /index.html HTTP/1.1\r\n"
    "Host: www.example.com\r\n"
    "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64)\r\n"
    "Accept-Language: en-US,en;q=0.5\r\n"
    "Connection: keep-alive\r\n\r\n";

    hRequest test = initRequest(req);

    printf("%s %s",test.target,test.method);

    return 0;
}
