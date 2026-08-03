#include "matchmaking.h"
#include <cmath>

extern "C" {
    GAME_API bool IsMatchBalanced(int team1AverageElo, int team2AverageElo) {
        return std::abs(team1AverageElo - team2AverageElo) <= 150;
    }
}

