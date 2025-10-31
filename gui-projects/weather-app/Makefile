#gcc main.c -o https_get -I curl\include -L curl\lib -lcurl -lssl -lcrypto -lws2_32 -lwldap32

CC = gcc
SOURCE = citytocord.c
CFLAGS = -I curl\include -L curl\lib -lcurl -lssl -lcrypto -lws2_32 -lwldap32
TARGET = api-app

$(TARGET): $(SOURCE)
	$(CC) $(SOURCE) -o $(TARGET) $(CFLAGS)
