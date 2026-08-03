#ifndef ROUND_H
#define ROUND_H

#include "core_exports.h"

struct RoundState {
    int roundNumber;
    float timeRemaining;
    bool isFreezeTime;
    int tScore;
    int ctScore;
    int winnerTeam;
};

extern "C" {
    GAME_API RoundState UpdateRoundTimer(RoundState state, float deltaTime, int aliveTCount, int aliveCTCount, bool isBombPlanted);
}

#endif

