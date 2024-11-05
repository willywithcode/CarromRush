#pragma once
#include "ActorManager.h"
class PhysicsEngine : public BanZ::SingletonTemplate<PhysicsEngine>
{
public: 
	bool CheckCollisionCircleVsCircle(const BanZ::VECTOR2& posCircle1,const BanZ::VECTOR2& posCircle2,const BanZ::VECTOR2& velocityCircle1,const BanZ::VECTOR2& veleocityCircle2,const float& radiusCircle1,const float& radiusCircle2);
	void HandleCollisionCircleVsCircle(const BanZ::VECTOR2& posCircle1, const BanZ::VECTOR2& posCircle2, const BanZ::VECTOR2& velocityCircle1, const BanZ::VECTOR2& veleocityCircle2, const float& radiusCircle1, const float& radiusCircle2);
};

