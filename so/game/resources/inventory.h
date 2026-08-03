#ifndef INVENTORY_H
#define INVENTORY_H

#include "core_exports.h"

struct Inventory {
    int primaryWeaponId;
    int secondaryWeaponId;
    int knifeId;
    int grenadeCount;
    bool hasDefuseKit;
    bool hasKevlar;
    bool hasHelmet;
};

extern "C" {
    GAME_API bool EquipWeapon(Inventory* inv, int slot, int weaponId);
    GAME_API bool DropWeapon(Inventory* inv, int slot);
}

#endif

