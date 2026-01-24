#include "pane_viewport.h"
#include "raylib.h"

#define BASE_PANEL_SIZE 20

void
DVTPDrawViewport(DVTPDrawViewportParameters params) {
  BeginScissorMode(
    params.bounds.x, 
    params.bounds.y, 
    params.bounds.width,
    params.bounds.height
);

  BeginMode2D(params.camera);

  ClearBackground(BLACK);

  DrawTextureEx(
    params.overworldTex,
    (Vector2){0, 0},
    0.0,
    BASE_PANEL_SIZE,
    WHITE
  );

  EndMode2D();

  EndScissorMode();
}
