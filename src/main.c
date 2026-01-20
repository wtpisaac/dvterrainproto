#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#include "../vendored/raygui.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

#define BOT_PANEL_HEIGHT 128
#define BOT_PANEL_PADDING 16
#define VIS_HEIGHT SCREEN_HEIGHT - BOT_PANEL_HEIGHT

#define PAN_SPEED 2.0

int
main(void)
{
    InitWindow(
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        "dvterrainproto"
    );
    SetTargetFPS(90);

    // Create 2D camera
    Camera2D camera = {
        .offset = {
            SCREEN_WIDTH / 2.0,
            SCREEN_HEIGHT / 2.0
        },
        .target = {
            0.0,
            0.0
        },
        .zoom = 1.0f
    };

    while(true) {
        BeginDrawing();

        BeginScissorMode(
            0,
            0,
            SCREEN_WIDTH,
            VIS_HEIGHT
        );

        BeginMode2D(camera);

        ClearBackground(GREEN);
        DrawRectangle(
            0.0,
            0.0, 
            20, 
            20, 
            (Color){
                0,
                0,
                0,
                255
            }
        );

        EndMode2D();

        EndScissorMode();

        BeginScissorMode(
            0, 
            SCREEN_HEIGHT - BOT_PANEL_HEIGHT, 
            SCREEN_WIDTH, 
            BOT_PANEL_HEIGHT
        );

        ClearBackground(GetColor(
            GuiGetStyle(DEFAULT, BACKGROUND_COLOR)
        ));

        GuiGroupBox(
            (Rectangle){
                0,
                (SCREEN_HEIGHT - BOT_PANEL_HEIGHT) + BOT_PANEL_PADDING,
                SCREEN_WIDTH,
                BOT_PANEL_HEIGHT - BOT_PANEL_PADDING
            },
            "dvterrainproto"
        );

        EndScissorMode();

        EndDrawing();

        if(
            WindowShouldClose() ||
            IsKeyPressed(KEY_ESCAPE)) {
            CloseWindow();
            break;
        }

        if(IsKeyDown(KEY_UP)) {
            camera.target.y -= PAN_SPEED;
        }
        if(IsKeyDown(KEY_DOWN)) {
            camera.target.y += PAN_SPEED;
        }
        if(IsKeyDown(KEY_LEFT)) {
            camera.target.x -= PAN_SPEED;
        }
        if(IsKeyDown(KEY_RIGHT)) {
            camera.target.x += PAN_SPEED;
        }

        camera.zoom += 0.25 * GetMouseWheelMove();
        if(camera.zoom < 0.25f) {
            camera.zoom = 0.25f;
        }
        if(camera.zoom > 4.0) {
            camera.zoom = 4.0f;
        }
    }
}
