#include "core/core.h"
#include "input/input.h"
#include "panes/pane_panel.h"
#include "panes/pane_viewport.h"
#include "render/render.h"
#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#include "../vendored/raygui.h"

#define FNL_IMPL
#include "../vendored/FastNoiseLite.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 1280

#define BOT_PANEL_HEIGHT 128
#define BOT_PANEL_PADDING 16
#define VIS_HEIGHT SCREEN_HEIGHT - BOT_PANEL_HEIGHT

#define PAN_SPEED 8.0

#define WORLD_SIDE_LENGTH 512

int
main(void)
{
    float* worldData = NULL;

    printf("Generating world...\n");
    DVTPCreateWorld((DVTPCreateWorldParams){
        .buffer_store_ptr = &worldData,
        .sideLength = WORLD_SIDE_LENGTH
    });
    printf("World generated!");

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
    DVTPCameraZoomLevel zoomLevel = DVTP_CAMERA_ZOOM_ONE;

    bool shouldContinue = true;
    while(shouldContinue) {
        BeginDrawing();

        DVTPDrawViewport((DVTPDrawViewportParameters){
            .bounds = (Rectangle){
                .x = 0,
                .y = 0,
                .width = SCREEN_WIDTH,
                .height = VIS_HEIGHT
            },
            .camera = camera,
            .worldData = worldData,
            .worldSideLength = WORLD_SIDE_LENGTH
        });

        DVTPDrawPanel((DVTPDrawPanelParameters){
            .bounds = (Rectangle){
                .x = 0,
                .y = SCREEN_HEIGHT - BOT_PANEL_HEIGHT,
                .height = BOT_PANEL_HEIGHT,
                .width = SCREEN_WIDTH
            },
            .camera = camera,
            .padding = 20
        });

        shouldContinue = DVTPHandleInputs((DVTPHandleInputsParameters){
            .camera = &camera,
            .zoomLevel = &zoomLevel,
            .panSpeed = PAN_SPEED
        });
    }
}
