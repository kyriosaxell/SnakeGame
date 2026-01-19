#include "snake.hpp"
#include "raymath.h"

void Snake::Draw(const int cellSize) const {
	const auto fSize = static_cast<float>(cellSize);
	for (const auto &[x, y] : body) {
		const auto rectangle = Rectangle{
			x * fSize,
			y * fSize,
			fSize,
			fSize
		};
		DrawRectangleRounded(rectangle, 0.5, 6, DARKGREEN);
	}
}

void Snake::Update() {
	if (body.empty()) return;

	body.pop_back();
	// Sums the head (first item) plus the actual direction
	body.push_front(Vector2Add(body.front(), direction));
}
