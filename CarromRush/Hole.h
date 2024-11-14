#pragma once
#include "Circle.h"
class Hole : public BanZ::Circle
{
public:
	Hole();
	Hole(float radius);
	Hole(float radius, BanZ::VECTOR2 position);
	Hole(float radius, BanZ::VECTOR2 position, BanZ::VECTOR2 velocity);
	Hole(float radius, BanZ::VECTOR2 position, BanZ::VECTOR2 velocity, float mass);
	void Render() override;
};

