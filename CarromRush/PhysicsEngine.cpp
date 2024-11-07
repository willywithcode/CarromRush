#include "PhysicsEngine.h"
#include "Circle.h"
#include <iostream>
namespace BanZ {

	bool PhysicsEngine::CheckCollisionCircleVsCircle(const BanZ::VECTOR2& posCircle1, const BanZ::VECTOR2& posCircle2, const float& radiusCircle1, const float& radiusCircle2)
	{
		auto banGame = BanGame::Get();
		float distance = banGame->Length(posCircle1 - posCircle2);
		return distance < radiusCircle1 + radiusCircle2;
	}

	void PhysicsEngine::HandleCollisionCircleVsCircle(BanZ::VECTOR2& posCircle1, BanZ::VECTOR2& posCircle2, BanZ::VECTOR2& velocityCircle1, BanZ::VECTOR2& velocityCircle2, const float& radiusCircle1, const float& radiusCircle2, const float& mass1, const float& mass2)
	{
		auto banGame = BanGame::Get();
		VECTOR2 collisionDir = banGame->Normalize(posCircle1 - posCircle2);
		float distance = banGame->Length(posCircle1 - posCircle2);
		float overlap = (radiusCircle1 + radiusCircle2 - distance) / 2;

		posCircle1 += collisionDir * overlap;
		posCircle2 -= collisionDir * overlap;

		float v1 = banGame->Dot(velocityCircle1, collisionDir);
		float v2 = banGame->Dot(velocityCircle2, collisionDir);

		float newV1 = (v1 * (mass1 - mass2) + 2 * mass2 * v2) / (mass1 + mass2);
		float newV2 = (v2 * (mass2 - mass1) + 2 * mass1 * v1) / (mass1 + mass2);

		velocityCircle1 += collisionDir * (newV1 - v1);
		velocityCircle2 += collisionDir * (newV2 - v2);

	}
	VECTOR2 FindNearestPointOnRectToCircle(const VECTOR2& circlePos, const VECTOR2& rectPos, const VECTOR2& rectEdge)
	{
		float halfWidth = rectEdge.x / 2.0f;
		float halfHeight = rectEdge.y / 2.0f;

		float nearestX;
		if (circlePos.x < rectPos.x - halfWidth) {
			nearestX = rectPos.x - halfWidth;
		}
		else if (circlePos.x > rectPos.x + halfWidth) {
			nearestX = rectPos.x + halfWidth;
		}
		else {
			nearestX = circlePos.x;
		}

		float nearestY;
		if (circlePos.y < rectPos.y - halfHeight) {
			nearestY = rectPos.y - halfHeight;
		}
		else if (circlePos.y > rectPos.y + halfHeight) {
			nearestY = rectPos.y + halfHeight;
		}
		else {
			nearestY = circlePos.y;
		}

		return VECTOR2{ nearestX, nearestY };
	}
	bool PhysicsEngine::CheckCollisionCircleVsBorder(const BanZ::VECTOR2& posCircle, const float& radiusCircle, const BanZ::VECTOR2& posBorder, const BanZ::VECTOR2& borderEdge,VECTOR2& collisionNormal)
	{
		VECTOR2 nearestPoint = FindNearestPointOnRectToCircle(posCircle, posBorder, borderEdge);
		float distance = BanGame::Get()->Length(posCircle - nearestPoint);
		if (distance <= radiusCircle)
		{
			collisionNormal = BanGame::Get()->Normalize(posCircle - nearestPoint);
			return true;
		}

		return false;
	}
	//Unity vector2 reflect
	void PhysicsEngine::HandleCollisionCircleVsBorder(BanZ::VECTOR2& velocityCircle, const VECTOR2 collisionNormal)
	{
		float dotProduct = BanGame::Get()->Dot(velocityCircle, collisionNormal);
		velocityCircle = velocityCircle- collisionNormal * (2 * dotProduct);
	}
	void PhysicsEngine::ProcessCollision()
	{
		auto ActorManager = ActorManager::getInstance();
		auto actors = ActorManager->GetActors();
		std::vector<Circle*> circles;
		std::vector<Border*> borders;

		for (auto actor : actors)
		{
			if (auto circle = dynamic_cast<Circle*>(actor))
				circles.push_back(circle);
			else if (auto border = dynamic_cast<Border*>(actor))
				borders.push_back(border);
		}
		CheckCircleVsCircleCollisions(circles);
	
		CheckCircleVsBorderCollisions(circles, borders);
	}
	void PhysicsEngine::CheckCircleVsCircleCollisions(const std::vector<Circle*>& circles)
	{
		for (int i = 0; i < circles.size(); i++)
		{
			for (int j = i + 1; j < circles.size(); j++)
			{
				auto circle1 = circles[i];
				auto circle2 = circles[j];
				if (circle1 != nullptr && circle2 != nullptr)
				{
					if (CheckCollisionCircleVsCircle(circle1->GetPosition(), circle2->GetPosition(), circle1->GetRadius(), circle2->GetRadius()))
					{
						HandleCollisionCircleVsCircle(circle1->GetPosition(), circle2->GetPosition(), circle1->GetVelocity(), circle2->GetVelocity(), circle1->GetRadius(), circle2->GetRadius(), circle1->GetMass(), circle2->GetMass());
					}
				}
			}
		}
	}
	void PhysicsEngine::CheckCircleVsBorderCollisions(const std::vector<Circle*>& circles, const std::vector<Border*>& borders)
	{
		for (auto circle : circles)
		{
			for (auto border : borders)
			{
				BanZ::VECTOR2 collisionNormal;
				if (CheckCollisionCircleVsBorder(circle->GetPosition(), circle->GetRadius(), border->GetPosition(), border->GetBorderEdge(), collisionNormal))
				{
					HandleCollisionCircleVsBorder(circle->GetVelocity(), collisionNormal);
				}
			}
		}
	}
}
