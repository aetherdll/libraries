#ifndef CORE_EXPORTS_H
#define CORE_EXPORTS_H

#if defined(_WIN32) || defined(__CYGWIN__)
    #ifdef BUILDING_GAME_DLL
        #define GAME_API __declspec(dllexport)
    #else
        #define GAME_API __declspec(dllimport)
    #endif
#else
    #define GAME_API __attribute__ ((visibility ("default")))
#endif

#endif

