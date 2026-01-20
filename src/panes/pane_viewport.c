#include "pane_viewport.h"

void
DVTPDrawViewport(DVTPDrawViewportParameters params) {
  BeginScissorMode(
    params.bounds.x, 
    params.bounds.y, 
    params.bounds.width, 
    params.bounds.height
);

  BeginMode2D(params.camera);

  ClearBackground(GREEN);
  DrawRectangle(0.0, 0.0, 20, 20, (Color){0, 0, 0, 255});

  EndMode2D();

  EndScissorMode();
}
