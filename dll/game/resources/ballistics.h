#ifndef BALLISTICS_H
#define BALLISTICS_H

#include "core_exports.h"

struct Vector3D {
    float x;
    float y;
    float z;
};

extern "C" {
    GAME_API Vector3D CalculateBulletStep(
        Vector3D currentPos, 
        Vector3D velocity, 
        float windX, 
        float windZ, 
        float gravity, 
        float deltaTime
    );

    GAME_API float CalculateDamage(float baseDamage, int hitZone, float armorValue);
}

#endif

