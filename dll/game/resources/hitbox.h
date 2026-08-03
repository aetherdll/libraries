#ifndef HITBOX_H
#define HITBOX_H

#include "core_exports.h"

struct BoundingBox {
    float minX, minY, minZ;
    float maxX, maxY, maxZ;
};

extern "C" {
    GAME_API bool CheckHitboxCollision(BoundingBox box, float rayX, float rayY, float rayZ);
}

#endif

