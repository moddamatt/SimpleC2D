# SimpleC2D
This is a simple 2D game built in C with raylib.

To build with mingw
gcc main.c -o game.exe -O1 -Wall -std=c99 -Wno-missing-braces -I include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lminmm