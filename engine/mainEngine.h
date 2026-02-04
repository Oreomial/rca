#pragma once
#include "raylib.h"

namespace Engine
{
    extern Camera camera;
    extern int currentGui;
    extern float sensivity;
    extern int targetFps;
    extern int cameraSpeed;
    
    void Init();
}