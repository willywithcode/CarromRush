#include "WhiteCoin.h"

WhiteCoin::WhiteCoin() : Circle()
{
}

WhiteCoin::WhiteCoin(float radius) : Circle(radius)
{
}	

WhiteCoin::WhiteCoin(float radius, BanZ::VECTOR2 position) : Circle(radius, position)
{
}

WhiteCoin::WhiteCoin(float radius, BanZ::VECTOR2 position, BanZ::VECTOR2 velocity) : Circle(radius, position, velocity)
{
}

WhiteCoin::WhiteCoin(float radius, BanZ::VECTOR2 position, BanZ::VECTOR2 velocity, float mass) : Circle(radius, position, velocity, mass)
{
}

void WhiteCoin::Render()
{
	auto game = BanZ::BanGame::Get();
	game->DrawSprite(game->CreateSprite("../Data/Images/covang.png"), this->position,BanZ::VECTOR2(this->GetRadius(), this->GetRadius()) * 2, 0);
}
