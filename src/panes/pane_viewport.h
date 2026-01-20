#ifndef DVTP_PANE_VIEWPORT_H
#define DVTP_PANE_VIEWPORT_H

#include <raylib.h>
#include <stdint.h>

typedef struct DVTPDrawViewportParameters {
    Rectangle bounds;
    Camera2D camera;
    float* worldData;
    uint16_t worldSideLength;
} DVTPDrawViewportParameters;

void
DVTPDrawViewport(
    DVTPDrawViewportParameters params
);

#endif
