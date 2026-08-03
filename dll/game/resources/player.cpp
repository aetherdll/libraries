#include "player.h"

extern "C" {
    GAME_API PlayerData ApplyDamageToPlayer(PlayerData player, float damage, bool hasHelmet) {
        if (!player.isAlive) return player;

        if (player.armor > 0.0f) {
            float absorbed = damage * 0.5f;
            player.armor -= (absorbed * 0.5f);
            damage -= absorbed;
            if (player.armor < 0.0f) player.armor = 0.0f;
        }

        player.health -= damage;
        if (player.health <= 0.0f) {
            player.health = 0.0f;
            player.isAlive = false;
            player.deaths++;
        }

        return player;
    }
}

