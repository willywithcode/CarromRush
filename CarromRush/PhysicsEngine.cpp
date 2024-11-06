#include "PhysicsEngine.h"
#include "Circle.h"
#include <iostream>
namespace BanZ {

	bool PhysicsEngine::CheckCollisionCircleVsCircle(const BanZ::VECTOR2& posCircle1, const BanZ::VECTOR2& posCircle2, const BanZ::VECTOR2& velocityCircle1, const BanZ::VECTOR2& veleocityCircle2, const float& radiusCircle1, const float& radiusCircle2)
	{
		auto banGame = BanGame::Get();
		float distance = banGame->Length(posCircle1 - posCircle2);
		return distance < radiusCircle1 + radiusCircle2;
	}

	void PhysicsEngine::HandleCollisionCircleVsCircle(BanZ::VECTOR2& posCircle1, BanZ::VECTOR2& posCircle2, BanZ::VECTOR2& velocityCircle1, BanZ::VECTOR2& velocityCircle2, const float& radiusCircle1, const float& radiusCircle2)
	{
		auto banGame = BanGame::Get();
		VECTOR2 collisionDir = banGame->Normalize(posCircle1 - posCircle2);
		float distance = banGame->Length(posCircle1 - posCircle2);
		float overlap = (radiusCircle1 + radiusCircle2 - distance) / 2;

		posCircle1 += collisionDir * overlap;
		posCircle2 -= collisionDir * overlap;

		float v1 = banGame->Dot(velocityCircle1, collisionDir);
		float v2 = banGame->Dot(velocityCircle2, collisionDir);

		float newV1 = v2;	// (velocityCircle1 * (m1 - m2) + 2 * m2 * velocityCircle2) / (m1 + m2);   m1=m2
		float newV2 = v1;	//(velocityCircle2 * (m2 - m1) + 2 * m1 * velocityCircle1) / (m1 + m2);

		velocityCircle1 += collisionDir * (newV1 - v1);
		velocityCircle2 += collisionDir * (newV2 - v2);
	}
	void PhysicsEngine::ProcessCollision()
	{
		auto ActorManager = ActorManager::getInstance();
		auto actors = ActorManager->GetActors();
		for (int i = 0; i < actors.size(); i++)
		{
			for (int j = i + 1; j < actors.size(); j++)
			{
				auto circle1 = dynamic_cast<Circle*>(actors[i]);
				auto circle2 = dynamic_cast<Circle*>(actors[j]);
				if (CheckCollisionCircleVsCircle(circle1->GetPosition(), circle2->GetPosition(), circle1->GetVelocity(), circle2->GetVelocity(), circle1->GetRadius(), circle2->GetRadius()))
				{
					HandleCollisionCircleVsCircle(circle1->GetPosition(), circle2->GetPosition(), circle1->GetVelocity(), circle2->GetVelocity(), circle1->GetRadius(), circle2->GetRadius());
				}
			}
		}
	}
}
