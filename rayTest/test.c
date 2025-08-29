#include "raylib.h"
int main() {
    // Initialize the window
    InitWindow(600, 400, "My First Raylib Program");

    // Set the target frames per second
    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Start drawing
        BeginDrawing();

        ClearBackground(RAYWHITE); // Clear the screen

        DrawText("Hello, Raylib!", 350, 280, 20, LIGHTGRAY); // Draw some text

        // Finish drawing
        EndDrawing();
    }

    // Close the window and cleanup
    CloseWindow();

    return 0;
} 
//This is just ai made placeholder code to ykk check if managed to set up raylib