#pragma once

#include "food.hpp"
#include "snake.hpp"

class GameState {
public:
	Food food	= Food{};
	Snake snake = Snake{};
	void Draw() const;
	void Update();
};
