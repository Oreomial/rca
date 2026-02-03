#include "raylib.h"

void RenderCamera(Camera *camera, float *zoom) {
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
        UpdateCameraPro(camera, (Vector3){0, 0, 0}, (Vector3){GetMouseDelta().x*6*GetFrameTime(), GetMouseDelta().y*6*GetFrameTime(), 0.0f}, *zoom);
    }
    if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
        DisableCursor();
    }
    if(IsMouseButtonReleased(MOUSE_BUTTON_RIGHT)) {
        EnableCursor();
    }
}

namespace Engine
{
    void Init() {
    Camera camera = { 0 };
    camera.position = (Vector3){ 0.0f, 2.0f, 4.0f };    // Camera position
    camera.target = (Vector3){ 0.0f, 2.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 60.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type
    float zoom = 0;

    InitWindow(1000, 1000, "test");
    SetTargetFPS(60);
    
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        RenderCamera(&camera, &zoom);
        DrawText("Test", 190, 200, 20, LIGHTGRAY);

        BeginMode3D(camera);
            DrawCubeWires((Vector3){ 0, 0, 0}, 2.0f, 2.0f, 2.0f, MAROON);
            DrawGrid(10, 1.0f);
        EndMode3D();

        EndDrawing();
    }
    CloseWindow();
    }
}
