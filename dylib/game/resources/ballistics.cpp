#include "ballistics.h"

extern "C" {

    GAME_API Vector3D CalculateBulletStep(
        Vector3D currentPos, 
        Vector3D velocity, 
        float windX, 
        float windZ, 
        float gravity, 
        float deltaTime
    ) {
        Vector3D newPos;
        
        float newVelX = velocity.x + (windX * deltaTime);
        float newVelY = velocity.y - (gravity * deltaTime);
        float newVelZ = velocity.z + (windZ * deltaTime);

        newPos.x = currentPos.x + (newVelX * deltaTime);
        newPos.y = currentPos.y + (newVelY * deltaTime);
        newPos.z = currentPos.z + (newVelZ * deltaTime);

        return newPos;
    }

    GAME_API float CalculateDamage(float baseDamage, int hitZone, float armorValue) {
        float multiplier = 1.0f;

        switch (hitZone) {
            case 1: multiplier = 2.5f; break;
            case 2: multiplier = 1.0f; break;
            case 3: multiplier = 0.6f; break;
            default: multiplier = 1.0f; break;
        }

        float totalDamage = baseDamage * multiplier;

        if (armorValue > 0.0f) {
            float absorbed = totalDamage * (armorValue / 100.0f);
            totalDamage -= absorbed;
        }

        return (totalDamage < 0.0f) ? 0.0f : totalDamage;
    }

}

