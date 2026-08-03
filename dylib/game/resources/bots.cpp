#include "bots.h"
#include <cmath>

extern "C" {
    GAME_API BotState UpdateBotAI(BotState currentBot, float targetX, float targetY, float targetZ, float deltaTime) {
        float dx = targetX - currentBot.posX;
        float dy = targetY - currentBot.posY;
        float dz = targetZ - currentBot.posZ;
        float distance = std::sqrt(dx*dx + dy*dy + dz*dz);

        if (distance < 15.0f) {
            currentBot.isAlerted = true;
            currentBot.posX += (dx / distance) * 2.5f * deltaTime;
            currentBot.posZ += (dz / distance) * 2.5f * deltaTime;
        } else {
            currentBot.isAlerted = false;
        }

        return currentBot;
    }
}

