#pragma once
#include "Circle.h"
class WhiteCoin : public BanZ::Circle
{
public:
	WhiteCoin();
	WhiteCoin(float radius);
	WhiteCoin(float radius, BanZ::VECTOR2 position);
	WhiteCoin(float radius, BanZ::VECTOR2 position, BanZ::VECTOR2 velocity);
	WhiteCoin(float radius, BanZ::VECTOR2 position, BanZ::VECTOR2 velocity, float mass);
	void Render() override;
};

