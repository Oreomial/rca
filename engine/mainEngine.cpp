#include <string>
#include "raylib.h"
#include "raygui.h"
#include "engine/mainEngine.h"
#include "engine/Bindings/Bindings.h"
#include "engine/UIs/UI.h"
#define RAYGUI_IMPLEMENTATION

Camera GenerateCamera()
{
    Camera camera = {0};
    camera.position = (Vector3){0.0f, 2.0f, 4.0f};
    camera.target = (Vector3){0.0f, 2.0f, 0.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    return camera;
}

void RenderUi()
{
    switch (Engine::currentGui)
    {
    case 0:
        RenderCamera();
        break;
    case 1:
        RenderMenu();
        break;
    default:
        RenderNoUI();
    }
}

void OpenWindow()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1000, 1000, "test");
    ToggleFullscreen();
    SetExitKey(KEY_END);
	SetWindowState(FLAG_VSYNC_HINT);
	ClearWindowState(FLAG_VSYNC_HINT);
    SetTargetFPS(Engine::targetFps);
    GuiSetStyle(DEFAULT, TEXT_SIZE, 40);
}

namespace Engine
{
    Camera3D camera = GenerateCamera();
    int currentGui = 0;
    float sensivity = 0.25;
    int targetFps = 60;
    int cameraSpeed = 5;

    void Init()
    {
        OpenWindow();

        while (!WindowShouldClose())
        {
            checkKeys();
            BeginDrawing();
            ClearBackground(RAYWHITE);

            RenderUi();
            RenderDebugUi();

            BeginMode3D(camera);
            DrawCubeWires((Vector3){0, 0, 0}, 2.0f, 2.0f, 2.0f, MAROON);
            DrawGrid(10, 1.0f);
            EndMode3D();

            EndDrawing();
        }
        CloseWindow();
    }
}
