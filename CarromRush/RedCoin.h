#pragma once
#include "Circle.h"
class RedCoin: public BanZ::Circle
{
public:
	RedCoin();
	RedCoin(float radius);
	RedCoin(float radius, BanZ::VECTOR2 position);
	RedCoin(float radius, BanZ::VECTOR2 position, BanZ::VECTOR2 velocity);
	RedCoin(float radius, BanZ::VECTOR2 position, BanZ::VECTOR2 velocity, float mass);
	void Render() override;
};

