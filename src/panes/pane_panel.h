#ifndef DVTP_PANE_PANEL_H
#define DVTP_PANE_PANEL_H

#include <raylib.h>
#include <stdint.h>

typedef struct DVTPDrawPanelParameters {
    Rectangle bounds;
    Camera2D camera;
    uint8_t padding;
} DVTPDrawPanelParameters;

void
DVTPDrawPanel(
    DVTPDrawPanelParameters params
);

#endif
