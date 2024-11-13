#pragma once
#include "constants.h"
#include "Play.h"

struct Paddle
	{
		;Play::Point2D pos = { DISPLAY_WIDTH / 2, DISPLAY_HEIGHT-(DISPLAY_HEIGHT-30)};
	};

extern Paddle paddle;
void DrawPaddle(Paddle& paddle);
void updatePaddle(Paddle& paddle);
bool isColliding(const Paddle& paddle, const Play::GameObject& obj);