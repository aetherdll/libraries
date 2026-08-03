#include "round.h"

extern "C" {
    GAME_API RoundState UpdateRoundTimer(RoundState state, float deltaTime, int aliveTCount, int aliveCTCount, bool isBombPlanted) {
        if (state.winnerTeam != 0) return state;

        if (state.isFreezeTime) {
            state.timeRemaining -= deltaTime;
            if (state.timeRemaining <= 0.0f) {
                state.isFreezeTime = false;
                state.timeRemaining = 115.0f;
            }
            return state;
        }

        state.timeRemaining -= deltaTime;

        if (aliveTCount == 0 && !isBombPlanted) {
            state.winnerTeam = 2;
            state.ctScore++;
        } else if (aliveCTCount == 0 && !isBombPlanted) {
            state.winnerTeam = 1;
            state.tScore++;
        } else if (state.timeRemaining <= 0.0f && !isBombPlanted) {
            state.winnerTeam = 2;
            state.ctScore++;
        }

        return state;
    }
}

