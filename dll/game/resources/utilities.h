#ifndef UTILITIES_H
#define UTILITIES_H

#include "core_exports.h"

struct FlashEffect {
    float duration;
    float intensity;
};

extern "C" {
    GAME_API FlashEffect CalculateFlashbang(float flashX, float flashZ, float playerX, float playerZ, float playerAngle);
}

#endif

