#include "BlackCoin.h"

BlackCoin::BlackCoin() : Circle()
{
}

BlackCoin::BlackCoin(float radius) : Circle(radius)
{
}

BlackCoin::BlackCoin(float radius, BanZ::VECTOR2 position) : Circle(radius, position)
{
}

BlackCoin::BlackCoin(float radius, BanZ::VECTOR2 position, BanZ::VECTOR2 velocity) : Circle(radius, position, velocity)
{
}

BlackCoin::BlackCoin(float radius, BanZ::VECTOR2 position, BanZ::VECTOR2 velocity, float mass) : Circle(radius, position, velocity, mass)
{
}

void BlackCoin::Render()
{
	auto game = BanZ::BanGame::Get();
	game->DrawSprite(game->CreateSprite("../Data/Images/coden.png"), this->position, BanZ::VECTOR2(this->GetRadius(), this->GetRadius()) * 2, 0);
}