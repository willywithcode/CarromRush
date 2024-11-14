#pragma once
#include "Circle.h"
class BlackCoin : public BanZ::Circle
{
public:
	BlackCoin();
	BlackCoin(float radius);
	BlackCoin(float radius, BanZ::VECTOR2 position);
	BlackCoin(float radius, BanZ::VECTOR2 position, BanZ::VECTOR2 velocity);
	BlackCoin(float radius, BanZ::VECTOR2 position, BanZ::VECTOR2 velocity, float mass);
	void Render() override;
};
