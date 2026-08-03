#ifndef PLAYER_H
#define PLAYER_H

#include "core_exports.h"

struct PlayerData {
    int id;
    int team;
    float health;
    float armor;
    bool isAlive;
    int kills;
    int deaths;
};

extern "C" {
    GAME_API PlayerData ApplyDamageToPlayer(PlayerData player, float damage, bool hasHelmet);
}

#endif

