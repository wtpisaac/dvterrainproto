#include <raylib.h>

int
main(void)
{
    InitWindow(
        1280,
        720,
        "dvterrainproto"
    );
    SetTargetFPS(90);

    while(true) {
        BeginDrawing();

        ClearBackground(GREEN);

        EndDrawing();

        if(
            WindowShouldClose() ||
            IsKeyPressed(KEY_ESCAPE)) {
            CloseWindow();
            break;
        }
    }
}
