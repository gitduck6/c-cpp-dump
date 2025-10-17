CC = gcc
FLAGS = -I ../include -L ../lib -lraylib -lopengl32 -lgdi32 -lwinmm
SOURCE = main.c

test: $(SOURCE)
	@echo Source: $(SOURCE)
	$(CC) -o $@ $(SOURCE) $(FLAGS)

run: test
	./test