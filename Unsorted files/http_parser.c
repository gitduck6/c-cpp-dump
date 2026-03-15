#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    * a poorly made http parser i definitly need to improve
    * for example manage the memory better
    * 
    * Okay this works for now but it is VERY unreadable and dangerous
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
    
    int i,j;

    size_t msize = 32;
    request.method = malloc(msize);

    size_t tsize = 32;
    request.target = malloc(tsize);


    for (i = 0;(rawRequest[i] != '\0') && (rawRequest[i] != ' ');i++)
    {
        request.method[i] = rawRequest[i];
        if ((i+1) >= msize)
        {
            msize *=2;
            char * temp = realloc(request.method,msize);
            if (temp == NULL)
            {
                perror("malloc");
                return (hRequest){0};

            }
            request.method = temp;
        }
    }
    request.method[i] = '\0';
    i++;
    j = i;
       
    for (;(rawRequest[i] != '\0') && (rawRequest[i] != ' ');i++)
    {
        request.target[i-j] = rawRequest[i];
        if ((i-j+1) >= tsize)
        {
            tsize *=2;
            char * temp = realloc(request.target,tsize);
            if (temp == NULL)
            {
                perror("malloc");
                return (hRequest){0};
            }
            request.method = temp;
        }
    }
    request.target[i-j] = '\0';

    return request;
    
}

char * getHeader(hRequest request, char * header)
{
    char * headerStart = strstr(request.raw,header);
    
    if (headerStart == NULL)
    //"Header does not exist";
    {
        return NULL;
    }
    
    
    headerStart = strstr(headerStart,":") + 1;
    
    char * HeaderEnd = strstr(headerStart,"\r\n");
    if (HeaderEnd < headerStart)
    //"Header not denoted properly";
    {
        return NULL;
    }
    
    
    size_t headerSize = 32;
    char * headerValue = malloc(headerSize);
    if (headerValue == NULL)
    {
        perror("malloc");
        return NULL;
    }
    
    int i;
    for (i = 0;(headerStart + i) < HeaderEnd;i++)
    {
        headerValue[i] = headerStart[i];
        if ((i+1) >= headerSize)
        {
            headerSize *= 2;
            char *temp = realloc(headerValue,headerSize);
            if (temp == NULL)
            {
                free(headerValue);
                perror("malloc");
                return NULL;

            }
            headerValue = temp;
        }
    }
    headerValue[i] = '\0';
        
    return headerValue;

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
    char * Host = getHeader(test,"Host");

    printf("%s %s %s\n",test.target,test.method,Host);

    return 0;
}
