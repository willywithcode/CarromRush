#include "Border.h"
namespace BanZ
{

	BanZ::Border::Border()
	{
		this->position = { 0,0 };
		this->borderEdge = { 0,0 };
		this->mass = 1.0;
		this->velocity = { 0,0 };
	}

	BanZ::Border::Border(VECTOR2 position, VECTOR2 borderEdge)
	{
		this->position = position;
		this->borderEdge = borderEdge;
		this->mass = 1.0;
		this->velocity = { 0,0 };
	}

	BanZ::Border::Border(VECTOR2 position, VECTOR2 borderEdge, float mass)
	{
		this->position = position;
		this->borderEdge = borderEdge;
		this->mass = mass;
		this->velocity = { 0,0 };
	}

	void Border::Init()
	{
		ActorObject::Init();
	}

	void Border::Update(const float& elapsedTime)
	{
	}

	void BanZ::Border::Render()
	{
		ActorObject::Render();
		BanGame::Get()->DrawRectangle(this->position, this->borderEdge, 0, COLOR::BLUE);
	}

	void BanZ::Border::OnDestroy()
	{
	}
}
