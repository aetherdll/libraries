#include "economy.h"

extern "C" {
    GAME_API int CalculateKillReward(int weaponType) {
        switch (weaponType) {
            case 1: return 300;
            case 2: return 300;
            case 3: return 600;
            case 4: return 1500;
            default: return 300;
        }
    }

    GAME_API int CalculateRoundEndReward(bool isWinner, int consecutiveLosses, bool bombPlanted) {
        if (isWinner) {
            return 3250;
        } else {
            int baseLoss = 1400;
            int bonus = (consecutiveLosses > 4 ? 4 : consecutiveLosses) * 500;
            if (bombPlanted) bonus += 800;
            return baseLoss + bonus;
        }
    }
}

