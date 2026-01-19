#include "gamestate.hpp"

void GameState::Draw() const {
	food.Draw(25);
	snake.Draw(30);
}

void GameState::Update() {
	snake.Update();
}