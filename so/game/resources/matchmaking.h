#ifndef MATCHMAKING_H
#define MATCHMAKING_H

#include "core_exports.h"

extern "C" {
    GAME_API bool IsMatchBalanced(int team1AverageElo, int team2AverageElo);
}

#endif

