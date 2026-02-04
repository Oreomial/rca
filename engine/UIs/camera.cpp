#include "raylib.h"
#include <engine/UIs/UI.h>
#include "engine/mainEngine.h"

void RenderCamera() {
    int mouseWheel = GetMouseWheelMove();
    float delta = GetFrameTime();

    if(IsKeyDown(KEY_W)){
        UpdateCameraPro(&Engine::camera, (Vector3){Engine::cameraSpeed * delta, 0, 0}, (Vector3){0, 0, 0}, 0);
    }
    if(IsKeyDown(KEY_S)){
        UpdateCameraPro(&Engine::camera, (Vector3){-Engine::cameraSpeed * delta, 0, 0}, (Vector3){0, 0, 0}, 0);
    }
    if(IsKeyDown(KEY_A)){
        UpdateCameraPro(&Engine::camera, (Vector3){0, -Engine::cameraSpeed * delta, 0}, (Vector3){0, 0, 0}, 0);
    }
    if(IsKeyDown(KEY_D)){
        UpdateCameraPro(&Engine::camera, (Vector3){0, Engine::cameraSpeed * delta, 0}, (Vector3){0, 0, 0}, 0);
    }
    if(IsKeyDown(KEY_E)){
        UpdateCameraPro(&Engine::camera, (Vector3){0, 0, Engine::cameraSpeed * delta}, (Vector3){0, 0, 0}, 0);
    }
    if(IsKeyDown(KEY_Q)){
        UpdateCameraPro(&Engine::camera, (Vector3){0, 0, -Engine::cameraSpeed * delta}, (Vector3){0, 0, 0}, 0);
    }
    if(IsMouseButtonDown(MOUSE_BUTTON_RIGHT)){
        Vector2 MouseDelta = GetMouseDelta();
        UpdateCameraPro(&Engine::camera, (Vector3){0, 0, 0}, (Vector3){MouseDelta.x * Engine::sensivity, MouseDelta.y * Engine::sensivity, 0}, 0);
    }
    if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
        DisableCursor();
    }
    if(IsMouseButtonReleased(MOUSE_BUTTON_RIGHT)) {
        EnableCursor();
    }
}