#pragma once
#include "Circle.h"
class QueenCoin : public BanZ::Circle
{
public:
	QueenCoin();
	QueenCoin(float radius);
	QueenCoin(float radius, BanZ::VECTOR2 position);
	QueenCoin(float radius, BanZ::VECTOR2 position, BanZ::VECTOR2 velocity);
	QueenCoin(float radius, BanZ::VECTOR2 position, BanZ::VECTOR2 velocity, float mass);
	void Render() override;
};

