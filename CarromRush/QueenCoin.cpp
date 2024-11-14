#include "QueenCoin.h"

QueenCoin::QueenCoin() : Circle()
{
}

QueenCoin::QueenCoin(float radius) : Circle(radius)
{
}

QueenCoin::QueenCoin(float radius, BanZ::VECTOR2 position) : Circle(radius, position)
{
}

QueenCoin::QueenCoin(float radius, BanZ::VECTOR2 position, BanZ::VECTOR2 velocity) : Circle(radius, position, velocity)
{
}

QueenCoin::QueenCoin(float radius, BanZ::VECTOR2 position, BanZ::VECTOR2 velocity, float mass) : Circle(radius, position, velocity, mass)
{
}

void QueenCoin::Render()
{
	auto game = BanZ::BanGame::Get();
	game->DrawSprite(game->CreateSprite("../Data/Images/codo_fix.png"), this->position, BanZ::VECTOR2(this->GetRadius(), this->GetRadius()) * 2, 0);
}
