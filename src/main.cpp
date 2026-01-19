#include "food.hpp"
#include "gamestate.hpp"
#include "raylib.h"
#include "snake.hpp"

constexpr int fps	  = 60;

Color green			  = {173, 204, 96, 255};
Color darkGreen		  = {43, 52, 24, 255};

int cellSize		  = 30;
int cellCount		  = 25;

double lastUpdateTime = 0;

bool eventTriggered(const double interval) {
	if (const double currentTime = GetTime(); currentTime - lastUpdateTime > interval) {
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}

int main() {
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(cellCount * cellSize, cellCount * cellSize, "Hello Raylib");
	SetTargetFPS(fps);

	auto [food, snake] = GameState();

	while (!WindowShouldClose()) {
		BeginDrawing();

		if (eventTriggered(0.2)) {
			snake.Update();
		}

		if (IsKeyPressed(KEY_UP) && snake.direction.y != 1) {
			snake.direction = {0, -1};
		}
		if (IsKeyPressed(KEY_DOWN) && snake.direction.y != -1) {
			snake.direction = {0, 1};
		}
		if (IsKeyPressed(KEY_RIGHT) && snake.direction.x != 1) {
			snake.direction = {1, 0};
		}
		if (IsKeyPressed(KEY_LEFT) && snake.direction.x != -1) {
			snake.direction = {-1, 0};
		}

		food.Draw(cellSize);
		snake.Draw(cellSize);

		ClearBackground(BLACK);

		EndDrawing();
	}

	// destroy the window and clean up the OpenGL context
	CloseWindow();
	return 0;
}
