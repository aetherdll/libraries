#include "third.h"
#include <iostream>

extern "C" {
    GAME_API void LogGameEvent(const char* eventName, int eventCode) {
        std::cout << "[GAME_LOG] Event: " << eventName << " | Code: " << eventCode << std::endl;
    }
}

