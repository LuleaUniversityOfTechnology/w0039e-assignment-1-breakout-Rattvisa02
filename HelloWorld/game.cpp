#define PLAY_IMPLEMENTATION
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Play.h"
#include "game.h"

void SpawnBall() 
	{
		const int objectId = Play::CreateGameObject(ObjectType::TYPE_BALL, { DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 3 }, 4, "ball");
		GameObject& ball = Play::GetGameObject(objectId);
		ball.velocity = normalize({ 1, -1 }) * ballSpeed;
	}

void StepFrame(float elapsedTime)
	{
		const std::vector<int> ballIds = Play::CollectGameObjectIDsByType(TYPE_BALL);
		for (int i=0;i< ballIds.size();i++)
			{
				GameObject& ball=Play::GetGameObject(ballIds[i]);
				if (ball.pos.x-ball.radius < 0 || ball.pos.x-ball.radius > DISPLAY_WIDTH)
					{
						ball.velocity.x = ball.velocity.x*(-1);
					}	
				if (ball.pos.y-ball.radius< 0 || ball.pos.y-ball.radius > DISPLAY_HEIGHT)
					{
						ball.velocity.y = ball.velocity.y*(-1);
					}
				// Check for collision with bricks
				const std::vector<int> brickIds = Play::CollectGameObjectIDsByType(TYPE_BRICK);
				for (int i = 0; i < brickIds.size(); i++)
				{
					GameObject& brick = Play::GetGameObject(brickIds[i]);
					if (Play::IsColliding(ball, brick))
					{
						Play::DestroyGameObject(brickIds[i]);
						ball.velocity.y = ball.velocity.y * (-1);
					}
				}
				Play::DrawObject(ball);
				Play::UpdateGameObject(ball, elapsedTime);
			}
		const std::vector<int> brickIds = Play::CollectGameObjectIDsByType(TYPE_BRICK);
		for (int i = 0; i < brickIds.size(); i++)
		{
			GameObject& brick = Play::GetGameObject(brickIds[i]);
			Play::DrawObject(brick);
		}
	}

void SetupScene()
	{
		for (int x = 5; x < DISPLAY_WIDTH - 20; x += 17)
			{
				for (int y = DISPLAY_HEIGHT - 20; y > DISPLAY_HEIGHT - 160;y -= 11) {
					const int brickID = Play::CreateGameObject(ObjectType::TYPE_BRICK, { x,y }, 6, "brick");
					GameObject& brick = Play::GetGameObject(brickID);
				}
			}
	}