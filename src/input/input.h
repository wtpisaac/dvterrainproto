#ifndef DVTP_INPUT_H
#define DVTP_INPUT_H

#include <raylib.h>

#include "../render/render.h"

typedef struct DVTPHandleInputsParameters {
    Camera2D* camera;
    DVTPCameraZoomLevel* zoomLevel;
    float panSpeed;
} DVTPHandleInputsParameters;

bool
DVTPHandleInputs(
    DVTPHandleInputsParameters params
);

float
DVTPPanSpeedMultiplierForZoomLevel(
    DVTPCameraZoomLevel zoomLevel
);

#endif
