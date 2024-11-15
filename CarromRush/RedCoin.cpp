#include "RedCoin.h"

RedCoin::RedCoin() : Circle()
{
}

RedCoin::RedCoin(float radius) : Circle(radius)
{
}

RedCoin::RedCoin(float radius, BanZ::VECTOR2 position) : Circle(radius, position)
{
}

RedCoin::RedCoin(float radius, BanZ::VECTOR2 position, BanZ::VECTOR2 velocity) : Circle(radius, position, velocity)
{
}

RedCoin::RedCoin(float radius, BanZ::VECTOR2 position, BanZ::VECTOR2 velocity, float mass) : Circle(radius, position, velocity, mass)
{
}

void RedCoin::Render()
{
	auto game = BanZ::BanGame::Get();
	game->DrawSprite(game->CreateSprite("../Data/Images/codo_fix.png"), this->position, BanZ::VECTOR2(this->GetRadius(), this->GetRadius()) * 2, 0);
}
