CC = gcc
FLAGS = -I ../include -L ../lib -lraylib -lopengl32 -lgdi32 -lwinmm
SOURCES = main.c viewpointdraw.c

test: $(SOURCES)
	@echo SourceS: $(SOURCES)
	$(CC) -o $@ $(SOURCES) $(FLAGS)

run: test
	./test