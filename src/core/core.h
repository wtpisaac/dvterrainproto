#ifndef DVTP_CORE_H
#define DVTP_CORE_H

#include <stdint.h>

typedef struct DVTPCreateWorldParams {
    uint16_t sideLength;
    float** buffer_store_ptr;
} DVTPCreateWorldParams;

void
DVTPCreateWorld(
    DVTPCreateWorldParams params
);

#endif