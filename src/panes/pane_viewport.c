#include "pane_viewport.h"
#include "raylib.h"

#include <math.h>
#include <stdlib.h>

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

  typedef enum DVTPLandLevel {
    DVTP_LAND_LEVEL_WATER,
    DVTP_LAND_LEVEL_LAND,
    DVTP_LAND_LEVEL_MOUNTAIN
  } DVTPLandLevel;
  
  // TODO: Limit scope to around viewport
  for(size_t y = 0; y < params.worldSideLength; y++) {
    for(size_t x = 0; x < params.worldSideLength; x++) {
        DVTPLandLevel level;
        float height = params.worldData[(y * params.worldSideLength) + x];
        if(height < -0.5) {
            level = DVTP_LAND_LEVEL_WATER;
        } else if(height > 0.5) {
            level = DVTP_LAND_LEVEL_MOUNTAIN;
        } else {
            level = DVTP_LAND_LEVEL_LAND;
        }

        float absHeight = fabsf(height);
        Color modifiedColor;

        switch(level) {
            case DVTP_LAND_LEVEL_LAND:
                absHeight = fabsf(height + 0.5f);
                modifiedColor = (Color){
                    .r = GREEN.r * absHeight,
                    .g = GREEN.g * absHeight,
                    .b = GREEN.b * absHeight,
                    .a = 255
                };
                break;
            case DVTP_LAND_LEVEL_MOUNTAIN:
                modifiedColor = (Color){
                    .r = GRAY.r * absHeight,
                    .g = GRAY.g * absHeight,
                    .b = GRAY.b * absHeight,
                    .a = 255
                };
                break;
            case DVTP_LAND_LEVEL_WATER:
                modifiedColor = (Color){
                    .r = BLUE.r * absHeight,
                    .g = BLUE.g * absHeight,
                    .b = BLUE.b * absHeight,
                    .a = 255
                };
                break;
        }

        DrawRectangle(
            (20 * x), 
            (20 * y), 
            20, 
            20, 
            modifiedColor
        );
    }
  }

  EndMode2D();

  EndScissorMode();
}
