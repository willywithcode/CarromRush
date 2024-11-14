#pragma once
#include "Circle.h"
class Striker : public BanZ::Circle
{
public:
	Striker();
	Striker(float radius);
	Striker(float radius, BanZ::VECTOR2 position);
	Striker(float radius, BanZ::VECTOR2 position, BanZ::VECTOR2 velocity);
	Striker(float radius, BanZ::VECTOR2 position, BanZ::VECTOR2 velocity, float mass);
	void Render() override;
};

