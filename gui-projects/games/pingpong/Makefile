SOURCE ?= ppt-v1.c
# you can change the version to 2 by adding SOURCE=ppt-v2.c to ur make command
# make run SOURCE=ppt-v2.c
# also ?= lets us override the variable
CC = gcc
FLAGS = -I ../include -L ../lib -lraylib -lopengl32 -lgdi32 -lwinmm
# also add -mwindows if you dont want a console app

test: $(SOURCE)
	@echo Version: $(SOURCE)
	$(CC) -o test $(SOURCE) $(FLAGS)

run: test
	./test