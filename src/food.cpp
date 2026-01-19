#include "food.hpp"
#include <raylib.h>

Food::Food() {
	const Image image = LoadImage("resources/food.png");
	texture			  = LoadTextureFromImage(image);
	UnloadImage(image);
	position = GenerateRandomPos(25);
}

Food::~Food() {
	UnloadTexture(texture);
}

void Food::Draw(const int cellSize) const {
	DrawTexture(texture, position.x * cellSize, position.y * cellSize, WHITE);
}

Vector2 Food::GenerateRandomPos(const int cellCount) {
	const float x = GetRandomValue(0, cellCount - 1);
	const float y = GetRandomValue(0, cellCount - 1);
	return Vector2{x, y};
}

void Food::UpdatePosition() {
	position.x = GetRandomValue(0, 24);
	position.y = GetRandomValue(0, 24);
}
