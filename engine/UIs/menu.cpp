#include <string>
#include <iostream>
#include "engine/mainEngine.h"
#include "engine/UIs/UI.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

void RenderMenu()
{
	float screenX = GetScreenWidth();
	float screenY = GetScreenHeight();

	int fontSize = 40;

	float offsetX = screenX * 0.085;
	float offsetY = screenY * 0.05;
	float elementX = screenX * 0.375;
	float elementY = screenY * 0.1;
	float fullElementY = elementY + 2 * fontSize;

	DrawRectangle(0, 0, screenX, screenY, Fade(BLACK, 0.8f));

	const std::string title = "Sensitivity";

	DrawText(title.c_str(), offsetX + (elementX - MeasureText(title.c_str(), fontSize)) / 2, offsetY, fontSize, WHITE);

	GuiSlider((Rectangle){offsetX, offsetY + fontSize, elementX, elementY},
			  "0.1", "1",
			  &Engine::sensivity, 0.1, 1);
	std::string currentValue = std::to_string(Engine::sensivity);

	DrawText(currentValue.c_str(), offsetX + (elementX - MeasureText(currentValue.c_str(), fontSize)) / 2, offsetY + elementY + fontSize, fontSize, YELLOW);

	// FPS
	const std::string title2 = "Target FPS";

	DrawText(title2.c_str(), elementX + 2 * offsetX + (elementX - MeasureText(title2.c_str(), fontSize)) / 2, offsetY, fontSize, WHITE);

	float temp = Engine::targetFps;

	if (IsWindowState(FLAG_VSYNC_HINT)){
		GuiSetState(STATE_DISABLED);
		temp = GetMonitorRefreshRate(GetCurrentMonitor());
	}

	GuiSlider((Rectangle){elementX + 2 * offsetX, offsetY + fontSize, elementX, elementY},
			  "10", "200",
			  &temp, 10, 200);
	GuiSetState(STATE_NORMAL);
	if (temp != Engine::targetFps and not IsWindowState(FLAG_VSYNC_HINT))
	{
		Engine::targetFps = (int)temp;

		SetTargetFPS(Engine::targetFps);
	}
	std::string currentValue2;
	if (IsWindowState(FLAG_VSYNC_HINT)){
		currentValue2 = std::to_string(GetMonitorRefreshRate(GetCurrentMonitor()));
	}
	else{
		currentValue2 = std::to_string(Engine::targetFps);
	}

	DrawText(currentValue2.c_str(), elementX + 2 * offsetX + (elementX - MeasureText(currentValue2.c_str(), fontSize)) / 2, offsetY + elementY + fontSize, fontSize, YELLOW);
	// camera speed

	const std::string title3 = "Camera speed";

	DrawText(title3.c_str(), offsetX + (elementX - MeasureText(title3.c_str(), fontSize)) / 2, offsetY + fullElementY, fontSize, WHITE);

	float temp2 = Engine::cameraSpeed;

	GuiSlider((Rectangle){offsetX, offsetY + fontSize + fullElementY, elementX, elementY},
			  "1", "10",
			  &temp2, 1, 10);

	Engine::cameraSpeed = (int)temp2;
	std::string currentValue3 = std::to_string(Engine::cameraSpeed);

	DrawText(currentValue3.c_str(), offsetX + (elementX - MeasureText(currentValue3.c_str(), fontSize)) / 2, offsetY + elementY + fontSize + fullElementY, fontSize, YELLOW);

	// VSYNC
	int temp3 = IsWindowState(FLAG_VSYNC_HINT);

	DrawText("VSync", 2 * offsetX + elementX, offsetY + fullElementY + fontSize + (elementY - fontSize) / 2, fontSize, WHITE);

	GuiToggleSlider((Rectangle){2 * offsetX + elementX + MeasureText("VSync", fontSize) + (elementX - elementX / 2 - MeasureText("VSync", fontSize)), offsetY + fullElementY + fontSize + elementY / 4, elementX / 2, elementY / 2}, "OFF;ON", &temp3);

	if (temp3 != IsWindowState(FLAG_VSYNC_HINT))
	{
		if (IsWindowState(FLAG_VSYNC_HINT)){
			ClearWindowState(FLAG_VSYNC_HINT);
			SetTargetFPS(Engine::targetFps);
		}
		else{
			SetWindowState(FLAG_VSYNC_HINT);
			SetTargetFPS(0);
		}
			
		
		temp3 = IsWindowState(FLAG_VSYNC_HINT);
	}
}