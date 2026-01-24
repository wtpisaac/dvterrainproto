#include "raylib.h"
#include <stdint.h>
#ifndef DVTP_RENDER_H
#define DVTP_RENDER_H 1

typedef enum DVTPCameraZoomLevel {
    DVTP_CAMERA_ZOOM_ONE_TENTH,
    DVTP_CAMERA_ZOOM_ONE_QUARTER,
    DVTP_CAMERA_ZOOM_ONE_HALF,
    DVTP_CAMERA_ZOOM_ONE,
    DVTP_CAMERA_ZOOM_TWO,
    DVTP_CAMERA_ZOOM_FOUR
} DVTPCameraZoomLevel;

float
DVTPRaylibCameraZoomForZoomLevel(
    DVTPCameraZoomLevel zoomLevel
);

DVTPCameraZoomLevel
zoomIn(
    DVTPCameraZoomLevel currentZoom
);

DVTPCameraZoomLevel
zoomOut(
    DVTPCameraZoomLevel currentZoom
);

Texture2D DVTPGenerateWorldTexture(float *worldData,
                               uint16_t worldSideLength);

#endif