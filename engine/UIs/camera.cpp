#include "raylib.h"
#include <engine/UIs/UI.h>

void RenderCamera(Camera *camera, float *zoom, int sensivity) {
    int mouseWheel = GetMouseWheelMove();

     if (mouseWheel != 0)
        {
            *zoom += mouseWheel;
        }
    if(IsKeyDown(KEY_W)){
        UpdateCameraPro(camera, (Vector3){0.1, 0, 0}, (Vector3){0, 0, 0}, *zoom);
    }
    if(IsKeyDown(KEY_S)){
        UpdateCameraPro(camera, (Vector3){-0.1, 0, 0}, (Vector3){0, 0, 0}, *zoom);
    }
    if(IsKeyDown(KEY_A)){
        UpdateCameraPro(camera, (Vector3){0, -0.1, 0}, (Vector3){0, 0, 0}, *zoom);
    }
    if(IsKeyDown(KEY_D)){
        UpdateCameraPro(camera, (Vector3){0, 0.1, 0}, (Vector3){0, 0, 0}, *zoom);
    }
    if(IsKeyDown(KEY_E)){
        UpdateCameraPro(camera, (Vector3){0, 0, 0.1}, (Vector3){0, 0, 0}, *zoom);
    }
    if(IsKeyDown(KEY_Q)){
        UpdateCameraPro(camera, (Vector3){0, 0, -0.1}, (Vector3){0, 0, 0}, *zoom);
    }
    if(IsMouseButtonDown(MOUSE_BUTTON_RIGHT)){
        Vector2 MouseDelta = GetMouseDelta();
        float FrameDelta = GetFrameTime();
        UpdateCameraPro(camera, (Vector3){0, 0, 0}, (Vector3){MouseDelta.x * sensivity * FrameDelta, MouseDelta.y * sensivity * FrameDelta, 0}, *zoom);
    }
    if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
        DisableCursor();
    }
    if(IsMouseButtonReleased(MOUSE_BUTTON_RIGHT)) {
        EnableCursor();
    }
}