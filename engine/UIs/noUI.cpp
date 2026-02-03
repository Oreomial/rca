#include <string>
#include "raylib.h"
#include <engine/UIs/UI.h>

void RenderNoUI(){
    const std::string text = "No UI";
    int fontSize = 40;
    int textWidth = MeasureText(text.c_str(), fontSize);

    int x = GetScreenWidth()/2 - textWidth/2;
    int y = GetScreenHeight()/2 - fontSize/2;
    DrawText(text.c_str(), x, y, fontSize, RED);
}