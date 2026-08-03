#ifndef BOTS_H
#define BOTS_H

#include "core_exports.h"

struct BotState {
    int id;
    float posX, posY, posZ;
    int targetPlayerId;
    float reactionTime;
    bool isAlerted;
};

extern "C" {
    GAME_API BotState UpdateBotAI(BotState currentBot, float targetX, float targetY, float targetZ, float deltaTime);
}

#endif

