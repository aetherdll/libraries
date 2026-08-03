#include "bomb.h"
#include <cmath>

extern "C" {
    GAME_API BombState UpdateBombStatus(BombState bomb, bool isPlanting, bool isDefusing, bool hasKit, float deltaTime) {
        if (!bomb.isPlanted && isPlanting) {
            bomb.plantProgress += (100.0f / 3.2f) * deltaTime;
            if (bomb.plantProgress >= 100.0f) {
                bomb.isPlanted = true;
                bomb.timer = 40.0f;
            }
        } else if (bomb.isPlanted && !bomb.isDefused) {
            bomb.timer -= deltaTime;
            if (isDefusing) {
                float defuseTime = hasKit ? 5.0f : 10.0f;
                bomb.defuseProgress += (100.0f / defuseTime) * deltaTime;
                if (bomb.defuseProgress >= 100.0f) {
                    bomb.isDefused = true;
                }
            }
        }
        return bomb;
    }

    GAME_API float CalculateExplosionDamage(float bombX, float bombZ, float playerX, float playerZ) {
        float dx = playerX - bombX;
        float dz = playerZ - bombZ;
        float dist = std::sqrt(dx*dx + dz*dz);
        float maxRadius = 25.0f;

        if (dist >= maxRadius) return 0.0f;
        return 500.0f * (1.0f - (dist / maxRadius));
    }
}

