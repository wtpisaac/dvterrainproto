#ifndef DVTP_PANE_VIEWPORT_H
#define DVTP_PANE_VIEWPORT_H

#include <raylib.h>

typedef struct DVTPDrawViewportParameters {
    Rectangle bounds;
    Camera2D camera;
} DVTPDrawViewportParameters;

void
DVTPDrawViewport(
    DVTPDrawViewportParameters params
);

#endif
