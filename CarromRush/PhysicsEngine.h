#pragma once
#include "ActorManager.h"
#include "Circle.h"
#include "Border.h"
namespace BanZ
{
	class PhysicsEngine : public BanZ::SingletonTemplate<PhysicsEngine>
	{
		float fixedDecelerationSpeed = 0.7f; 
		float collidedDecelerationSpeed = 0.05f; 
	public: 
		void Update(const float& elapsedTime);
		bool CheckCollisionCircleVsCircle(const BanZ::VECTOR2& posCircle1, const BanZ::VECTOR2& posCircle2, const float& radiusCircle1, const float& radiusCircle2);
		void HandleCollisionCircleVsCircle(BanZ::VECTOR2& posCircle1, BanZ::VECTOR2& posCircle2, BanZ::VECTOR2& velocityCircle1, BanZ::VECTOR2& velocityCircle2, const float& radiusCircle1, const float& radiusCircle2,const float& mass1, const float& mass2);
		bool CheckCollisionCircleVsBorder(const BanZ::VECTOR2& posCircle, const float& radiusCircle, const BanZ::VECTOR2& posBorder, const BanZ::VECTOR2& borderEdge,VECTOR2& collisionNormal);
		void HandleCollisionCircleVsBorder(BanZ::VECTOR2& velocityCircle, const VECTOR2 collisionNormal);
		void ProcessCollision();
		void HandleCircleVsCircleCollisions(const std::vector<Circle*>& circles);
		void HandleCircleVsBorderCollisions(const std::vector<Circle*>& circles, const std::vector<Border*>& borders);
	};
}

