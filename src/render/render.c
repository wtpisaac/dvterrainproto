#include "render.h"

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
