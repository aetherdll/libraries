#include "inventory.h"

extern "C" {
    GAME_API bool EquipWeapon(Inventory* inv, int slot, int weaponId) {
        if (!inv) return false;
        if (slot == 1) inv->primaryWeaponId = weaponId;
        else if (slot == 2) inv->secondaryWeaponId = weaponId;
        else if (slot == 3) inv->knifeId = weaponId;
        else return false;
        return true;
    }

    GAME_API bool DropWeapon(Inventory* inv, int slot) {
        if (!inv) return false;
        if (slot == 1) inv->primaryWeaponId = 0;
        else if (slot == 2) inv->secondaryWeaponId = 0;
        else return false;
        return true;
    }
}

