#gcc main.c -o https_get -I curl\include -L curl\lib -lcurl -lssl -lcrypto -lws2_32 -lwldap32

# Compiler and flags
CC := gcc
CFLAGS := -Icurl/include
LDFLAGS := -Lcurl/lib -lcurl -lssl -lcrypto -lws2_32 -lwldap32

# Sources, objects, and target
SOURCES := apihandler.c cJSON.c
OBJECTS := $(SOURCES:.c=.o)
TARGET := api-app

# Default rule
all: $(TARGET)

# Link target
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

# Compile .c → .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	del /F /Q $(OBJECTS) $(TARGET)

# Phony targets (not actual files)
.PHONY: all clean


#As you can see this was made by ai lol
#but ill try my best to understand it 
