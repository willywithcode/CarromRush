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

// GameEngine todo 1
void Striker::LoadSprite(const std::string& local)
{
	auto game = BanZ::BanGame::Get();
	striker = game->CreateSprite(local);
}

void Striker::Render()
{
	auto game = BanZ::BanGame::Get();

	

	//game->DrawSprite(game->CreateSprite("../Data/Images/cocai_fix.png"), this->position, BanZ::VECTOR2(this->GetRadius(), this->GetRadius()) * 2, 0);
	
	// GameEngine todo 1
	game->DrawSprite(striker, this->position, BanZ::VECTOR2(this->GetRadius(), this->GetRadius()) * 2, 0);
	game->DrawSprite(effect, this->position, BanZ::VECTOR2(this->GetRadius(), this->GetRadius()) * 3.0f, -angle);


	angle++;
}
