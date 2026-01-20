#ifndef DVTP_INPUT_H
#define DVTP_INPUT_H

#include <raylib.h>

typedef struct DVTPHandleInputsParameters {
    Camera2D* camera;
    float panSpeed;
} DVTPHandleInputsParameters;

bool
DVTPHandleInputs(
    DVTPHandleInputsParameters params
);

#endif
