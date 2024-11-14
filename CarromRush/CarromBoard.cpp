#include "CarromBoard.h"

CarromBoard::CarromBoard()
{
	this->width = 0.0f;
	this->height = 0.0f;
	this->position = BanZ::VECTOR2(0.0f, 0.0f);
}

CarromBoard::CarromBoard(float width, float height) 
{
	this->width = width;
	this->height = height;
	this->position = BanZ::VECTOR2(0.0f, 0.0f);
}

CarromBoard::CarromBoard(float width, float height, BanZ::VECTOR2 position)
{
	this->width = width;
	this->height = height;
	this->position = position;
}

void CarromBoard::Render()
{
	auto game = BanZ::BanGame::Get();
	game->DrawSprite(game->CreateSprite("../Data/Images/banco_fix.png"), this->position,BanZ::VECTOR2(this->width,this->height), 0, BanZ::COLOR::DEFAULT, BanZ::VECTOR2(0,0), -2);
}
