#include "Hole.h"
Hole::Hole() : Circle()
{
}

Hole::Hole(float radius) : Circle(radius)
{
	this->isTriggered = true;
}

Hole::Hole(float radius, BanZ::VECTOR2 position) : Circle(radius, position, true)
{
}

Hole::Hole(float radius, BanZ::VECTOR2 position, BanZ::VECTOR2 velocity) : Circle(radius, position, velocity, true)
{
}

Hole::Hole(float radius, BanZ::VECTOR2 position, BanZ::VECTOR2 velocity, float mass) : Circle(radius, position, velocity, mass, true)
{
}

void Hole::Render()
{
	auto game = BanZ::BanGame::Get();
	game->DrawSprite(game->CreateSprite("../Data/Images/hole_fix.png"), this->position, BanZ::VECTOR2(this->GetRadius(), this->GetRadius()) * 8, 0, BanZ::COLOR::DEFAULT, BanZ::VECTOR2(0, 0), -1);
}
