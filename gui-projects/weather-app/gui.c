#include "raylib.h"
#include "curl/curl.h"

int main(void) {
    InitWindow(800, 450, "Minimal Raylib Window"); // Create window
    while (!WindowShouldClose()) {                  // Run until user closes window
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }
    CloseWindow();                                  // Cleanup
    return 0;
}
