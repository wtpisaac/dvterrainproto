#include "input.h"

bool
DVTPHandleInputs(
    DVTPHandleInputsParameters params
) {
    if(
        WindowShouldClose() ||
        IsKeyPressed(KEY_ESCAPE)) {
        CloseWindow();
        return false;
    }

    if(IsKeyDown(KEY_UP)) {
        params.camera->target.y -= params.panSpeed;
    }
    if(IsKeyDown(KEY_DOWN)) {
        params.camera->target.y += params.panSpeed;
    }
    if(IsKeyDown(KEY_LEFT)) {
        params.camera->target.x -= params.panSpeed;
    }
    if(IsKeyDown(KEY_RIGHT)) {
        params.camera->target.x += params.panSpeed;
    }

    params.camera->zoom += 0.25 * GetMouseWheelMove();
    if(params.camera->zoom < 0.25f) {
        params.camera->zoom = 0.25f;
    }
    if(params.camera->zoom > 4.0) {
        params.camera->zoom = 4.0f;
    }
    return true;
}