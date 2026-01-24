#include "render.h"
#include "raylib.h"
#include <math.h>
#include <stddef.h>

float
DVTPRaylibCameraZoomForZoomLevel(DVTPCameraZoomLevel zoomLevel) {
    switch (zoomLevel) {
        case DVTP_CAMERA_ZOOM_ONE_TENTH:
            return 0.1;
        case DVTP_CAMERA_ZOOM_ONE_QUARTER:
            return 0.25;
        case DVTP_CAMERA_ZOOM_ONE_HALF:
            return 0.5;
        case DVTP_CAMERA_ZOOM_ONE:
            return 1.0;
        case DVTP_CAMERA_ZOOM_TWO:
            return 2.0;
        case DVTP_CAMERA_ZOOM_FOUR:
            return 4.0;
    }
}

DVTPCameraZoomLevel
zoomIn(
    DVTPCameraZoomLevel currentZoom
) {
    if(currentZoom == DVTP_CAMERA_ZOOM_FOUR) {
        // min
        return DVTP_CAMERA_ZOOM_FOUR;
    }

    return (DVTPCameraZoomLevel)(currentZoom + 1);
}

DVTPCameraZoomLevel
zoomOut(
    DVTPCameraZoomLevel currentZoom
) {
    if(currentZoom == DVTP_CAMERA_ZOOM_ONE_TENTH) {
        // min
        return DVTP_CAMERA_ZOOM_ONE_TENTH;
    }

    return (DVTPCameraZoomLevel)(currentZoom - 1);
}

typedef enum DVTPLandLevel {
    DVTP_LAND_LEVEL_WATER,
    DVTP_LAND_LEVEL_LAND,
    DVTP_LAND_LEVEL_MOUNTAIN
} DVTPLandLevel;

// TODO: Format not garbage
// TODO: return handles to free...
Texture2D DVTPGenerateWorldTexture(float *worldData,
                               uint16_t worldSideLength) {
  Image overworldImage = GenImageColor(worldSideLength, worldSideLength, BLACK);

  // TODO:params.worldSideLength Limit scope to around viewport
  for (size_t y = 0; y < worldSideLength; y++) {
    for (size_t x = 0; x < worldSideLength; x++) {
      Color modifiedColor;
      DVTPLandLevel level;
      float height = worldData[(y * worldSideLength) + x];
      float offsetHeight = height + 1.0;
      float absOffsetHeight = fabsf(offsetHeight);
      float absHeight = (absOffsetHeight / 2.0);

      if (height < -0.5) {
        level = DVTP_LAND_LEVEL_WATER;
      } else if (height > 0.75) {
        level = DVTP_LAND_LEVEL_MOUNTAIN;
      } else {
        level = DVTP_LAND_LEVEL_LAND;
      }

      switch (level) {
      case DVTP_LAND_LEVEL_LAND:
        modifiedColor = (Color){.r = GREEN.r * absHeight,
                                .g = GREEN.g * absHeight,
                                .b = GREEN.b * absHeight,
                                .a = 255};
        break;
      case DVTP_LAND_LEVEL_MOUNTAIN:
        modifiedColor = (Color){.r = GRAY.r * absHeight,
                                .g = GRAY.g * absHeight,
                                .b = GRAY.b * absHeight,
                                .a = 255};
        break;
      case DVTP_LAND_LEVEL_WATER:
        modifiedColor = (Color){.r = BLUE.r * absHeight,
                                .g = BLUE.g * absHeight,
                                .b = BLUE.b * absHeight,
                                .a = 255};
        break;
      }

      ImageDrawPixel(&overworldImage, x, y, modifiedColor);
    }
  }

  Texture2D overworldTex = LoadTextureFromImage(
    overworldImage
  );

  return overworldTex;
};
