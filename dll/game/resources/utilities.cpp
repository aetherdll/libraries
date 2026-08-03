#include "utilities.h"
#include <cmath>

extern "C" {
    GAME_API FlashEffect CalculateFlashbang(float flashX, float flashZ, float playerX, float playerZ, float playerAngle) {
        FlashEffect effect = { 0.0f, 0.0f };
        float dx = flashX - playerX;
        float dz = flashZ - playerZ;
        float dist = std::sqrt(dx*dx + dz*dz);

        if (dist < 20.0f) {
            effect.duration = (1.0f - (dist / 20.0f)) * 4.5f;
            effect.intensity = 1.0f;
        }
        return effect;
    }
}

