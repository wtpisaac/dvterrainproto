#ifndef DVTP_PANE_VIEWPORT_H
#define DVTP_PANE_VIEWPORT_H

#include <raylib.h>
#include <stdint.h>

#include "../render/render.h"

typedef struct DVTPDrawViewportParameters {
    Rectangle bounds;
    Camera2D camera;
    DVTPCameraZoomLevel zoomLevel;
    Texture2D overworldTex;
} DVTPDrawViewportParameters;

void
DVTPDrawViewport(
    DVTPDrawViewportParameters params
);

#endif
