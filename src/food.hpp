#pragma once

#include <raylib.h>

class Food {
  public:
	Food();
	~Food();

	Vector2 position;
	Texture2D texture;

	void Draw(int cellSize) const;
	void UpdatePosition();
	[[nodiscard]] static Vector2 GenerateRandomPos(int cellCount);
};
