#include "Striker.h"


Striker::Striker() : Circle()
{
}

Striker::Striker(float radius) : Circle(radius)
{
}

Striker::Striker(float radius, BanZ::VECTOR2 position) : Circle(radius, position)
{
}

Striker::Striker(float radius, BanZ::VECTOR2 position, BanZ::VECTOR2 velocity) : Circle(radius, position, velocity)
{
}

Striker::Striker(float radius, BanZ::VECTOR2 position, BanZ::VECTOR2 velocity, float mass) : Circle(radius, position, velocity, mass)
{
}

void Striker::Render()
{
	auto game = BanZ::BanGame::Get();
	game->DrawSprite(game->CreateSprite("../Data/Images/cocai1_fix.png"), this->position, BanZ::VECTOR2(this->GetRadius(), this->GetRadius()) * 2, 0);
}
