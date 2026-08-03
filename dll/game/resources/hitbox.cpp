#include "hitbox.h"

extern "C" {
    GAME_API bool CheckHitboxCollision(BoundingBox box, float rayX, float rayY, float rayZ) {
        return (rayX >= box.minX && rayX <= box.maxX &&
                rayY >= box.minY && rayY <= box.maxY &&
                rayZ >= box.minZ && rayZ <= box.maxZ);
    }
}

