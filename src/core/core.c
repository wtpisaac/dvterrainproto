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
    noiseState.domain_warp_type = FNL_DOMAIN_WARP_OPENSIMPLEX2;
    noiseState.domain_warp_amp = 10.0;

    for(size_t y = 0; y < params.sideLength; y++) {
        for(size_t x = 0; x < params.sideLength; x++) {
            float modX = x;
            float modY = y;
            fnlDomainWarp2D(&noiseState, &modX, &modY);
            worldData[(y * params.sideLength) + x] = fnlGetNoise2D(
                &noiseState,
                modX, 
                modY
            );
        }
    }

    *params.buffer_store_ptr = worldData;

    return;
}
