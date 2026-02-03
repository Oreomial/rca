#include <string>
#include "raylib.h"
#include "engine/UIs/UI.h"
#define RAYGUI_IMPLEMENTATION

Camera GenerateCamera(){
    Camera camera = { 0 };
    camera.position = (Vector3){ 0.0f, 2.0f, 4.0f };
    camera.target = (Vector3){ 0.0f, 2.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    return camera;
}

void OpenWindow(){
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1000, 1000, "test");
    SetTargetFPS(60);
}

void RenderUi(int currentGui, Camera *camera, float *zoom){
    switch(currentGui){
        case 0:
            RenderCamera(camera, zoom, 5);
            break;
        case 1:
            RenderMenu();
            break;
        default:
            RenderNoUI();
    }       
}

namespace Engine
{
    void Init() {
        Camera camera = GenerateCamera();
        float zoom = 0;

        OpenWindow();
    
        while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);

            RenderUi(0, &camera, &zoom);
            RenderDebugUi();
            
        BeginMode3D(camera);
            DrawCubeWires((Vector3){ 0, 0, 0}, 2.0f, 2.0f, 2.0f, MAROON);
            DrawGrid(10, 1.0f);
        EndMode3D();

        EndDrawing();
    }
    CloseWindow();
    }
}
