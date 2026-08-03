#ifndef BOMB_H
#define BOMB_H

#include "core_exports.h"

struct BombState {
    bool isPlanted;
    bool isDefused;
    float plantProgress;
    float defuseProgress;
    float timer;
};

extern "C" {
    GAME_API BombState UpdateBombStatus(BombState bomb, bool isPlanting, bool isDefusing, bool hasKit, float deltaTime);
    GAME_API float CalculateExplosionDamage(float bombX, float bombZ, float playerX, float playerZ);
}

#endif

