# This command is how you compile it for WINDOWS
gcc -o simple test.c -Iraylib/include -Lraylib/lib -lraylib -lopengl32 -lgdi32 -lwinmm
# Here are the other operating systems:

# linux
gcc -o simple test.c -Iraylib/include -Lraylib/lib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# macos
gcc -o simple test.c -Iraylib/include -Lraylib/lib -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo -lm

# PS :
# wait i just realized, i those raylib files will only run on windows
# :sob: anyway mmmm ill try to do it for others later
# took me like 6-7 seconds heh... (all day wasted lmao)
