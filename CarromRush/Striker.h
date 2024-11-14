#pragma once
#include "Circle.h"
// GameEngine todo 1
#include "BanGame.h"
class Striker : public BanZ::Circle
{
public:
	Striker();
	Striker(float radius);
	Striker(float radius, BanZ::VECTOR2 position);
	Striker(float radius, BanZ::VECTOR2 position, BanZ::VECTOR2 velocity);
	Striker(float radius, BanZ::VECTOR2 position, BanZ::VECTOR2 velocity, float mass);
	// GameEngine todo 1
	void LoadSprite(const std::string&);

	void SetEffect(const BanZ::pSprite& eff) { this->effect = eff; }

	void Render() override;
private:
	// GameEngine todo 1
	BanZ::pSprite striker;
	BanZ::pSprite effect;

};

