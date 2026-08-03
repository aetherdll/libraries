#ifndef ECONOMY_H
#define ECONOMY_H

#include "core_exports.h"

extern "C" {
    GAME_API int CalculateKillReward(int weaponType);
    GAME_API int CalculateRoundEndReward(bool isWinner, int consecutiveLosses, bool bombPlanted);
}

#endif

