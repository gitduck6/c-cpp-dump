#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    * a poorly made http parser i definitly need to improve
    * for example manage the memory better
    * 
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

char * getHeader(hRequest hRequest, char * header)
{

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

    printf("%s %s\n",test.target,test.method);

    return 0;
}
