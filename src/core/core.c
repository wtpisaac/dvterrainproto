#include "core.h"
#include <stdlib.h>

#include "../../vendored/FastNoiseLite.h"

void
DVTPCreateWorld(DVTPCreateWorldParams params) {
    float* worldData = calloc(
        params.sideLength * params.sideLength,
        sizeof(float)
    );

    fnl_state noiseState = fnlCreateState();
    noiseState.noise_type = FNL_NOISE_OPENSIMPLEX2S;

    for(size_t y = 0; y < params.sideLength; y++) {
        for(size_t x = 0; x < params.sideLength; x++) {
            worldData[(y * params.sideLength) + x] = fnlGetNoise2D(
                &noiseState,
                (FNLfloat)x, 
                (FNLfloat)y
            );
        }
    }

    *params.buffer_store_ptr = worldData;

    return;
}
