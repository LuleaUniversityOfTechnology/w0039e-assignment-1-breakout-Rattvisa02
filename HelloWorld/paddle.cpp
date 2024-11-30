#define PLAY_USING_GAMEOBJECT_MANAGER
#include "paddle.h"
#include "Play.h"
#include "constants.h"

Paddle paddle;

void DrawPaddle(Paddle& paddle)
{
	Play::DrawRect({(paddle.pos.x-50),(paddle.pos.y-5) }, {(paddle.pos.x+50),(paddle.pos.y+5)}, Play::cGreen, true);
}

void updatePaddle(Paddle& paddle)
	{
		if (Play::KeyDown(Play::KEY_LEFT) && paddle.pos.x >= 55)
			{
				paddle.pos.x -= 5;
			}
		if (Play::KeyDown(Play::KEY_RIGHT) && (paddle.pos.x <= DISPLAY_WIDTH - 55))
			{
				paddle.pos.x += 5;
			}
	}

bool isColliding(const Paddle& paddle, const Play::GameObject& obj)
{
    const float dx = obj.pos.x - ((paddle.pos.x - 50 > obj.pos.x) ? (paddle.pos.x - 50) : ((paddle.pos.x + 50 < obj.pos.x) ? (paddle.pos.x + 50) : obj.pos.x));
    const float dy = obj.pos.y - ((paddle.pos.y - 5 > obj.pos.y) ? (paddle.pos.y - 5) : ((paddle.pos.y + 5 < obj.pos.y) ? (paddle.pos.y + 5) : obj.pos.y));
    return (dx * dx + dy * dy) < (obj.radius * obj.radius);
}