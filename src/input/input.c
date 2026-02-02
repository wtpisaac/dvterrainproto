#include "input.h"
#include "raylib.h"

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

    float modifiedPanSpeed = DVTPPanSpeedMultiplierForZoomLevel(
        *params.zoomLevel
    ) * params.panSpeed;

    if(IsKeyDown(KEY_UP)) {
        params.camera->target.y -= modifiedPanSpeed;
    }
    if(IsKeyDown(KEY_DOWN)) {
        params.camera->target.y += modifiedPanSpeed;
    }
    if(IsKeyDown(KEY_LEFT)) {
        params.camera->target.x -= modifiedPanSpeed;
    }
    if(IsKeyDown(KEY_RIGHT)) {
        params.camera->target.x += modifiedPanSpeed;
    }

    if(IsKeyPressed(KEY_EQUAL)) {
        *params.zoomLevel = zoomIn(
            *params.zoomLevel
        );
        params.camera->zoom = DVTPRaylibCameraZoomForZoomLevel(
            *params.zoomLevel
        );
    }
    if(IsKeyPressed(KEY_MINUS)) {
        *params.zoomLevel = zoomOut(
            *params.zoomLevel
        );
        params.camera->zoom = DVTPRaylibCameraZoomForZoomLevel(
            *params.zoomLevel
        );
    }

    return true;
}

float
DVTPPanSpeedMultiplierForZoomLevel(
    DVTPCameraZoomLevel zoomLevel
) {
    switch(zoomLevel) {
        case DVTP_CAMERA_ZOOM_HALF_ONE_TENTH:
            return 20.0;
        case DVTP_CAMERA_ZOOM_ONE_TENTH:
            return 10.0;
        case DVTP_CAMERA_ZOOM_ONE_QUARTER:
            return 4.0;
        case DVTP_CAMERA_ZOOM_ONE_HALF:
            return 2.0;
        case DVTP_CAMERA_ZOOM_ONE:
            return 1.0;
        case DVTP_CAMERA_ZOOM_TWO:
            return 0.5;
        case DVTP_CAMERA_ZOOM_FOUR:
            return 0.25;
    }
}
