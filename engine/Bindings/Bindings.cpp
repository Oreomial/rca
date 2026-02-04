#include "engine/mainEngine.h"
#include "raylib.h"

void checkKeys() {
    if(IsKeyPressed(KEY_ESCAPE)){
        if(Engine::currentGui == 1){
            Engine::currentGui = 0;
        }
        else if(Engine::currentGui == 0){
            EnableCursor();
            Engine::currentGui = 1;
        }
    }
}