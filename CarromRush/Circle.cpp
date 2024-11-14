#include "Circle.h"
namespace BanZ
{
	Circle::Circle() : radius(0.0f)
	{
		this->position = BanZ::VECTOR2(0.0f, 0.0f);
		this->velocity = BanZ::VECTOR2(0.0f, 0.0f);
		this->mass = 1.0f;
	}

	Circle::Circle(float radius,bool isTriggered) : radius(radius)
	{
		this->position = BanZ::VECTOR2(0.0f, 0.0f);
		this->velocity = BanZ::VECTOR2(0.0f, 0.0f);
		this->mass = 1.0f;
		this->isTriggered = isTriggered;
	}

	Circle::Circle(float radius, BanZ::VECTOR2 position,bool isTriggered) : radius(radius)
	{
		this->position = position;
		this->velocity = BanZ::VECTOR2(0.0f, 0.0f);
		this->mass = 1.0f;
		this->isTriggered = isTriggered;
	}

	Circle::Circle(float radius, BanZ::VECTOR2 position, BanZ::VECTOR2 velocity,bool isTriggered) : radius(radius)
	{
		this->position = position;
		this->velocity = velocity;
		this->mass = 1.0f;
		this->isTriggered = isTriggered;
	}

	Circle::Circle(float radius, BanZ::VECTOR2 position, BanZ::VECTOR2 velocity, float mass,bool isTriggerd) : radius(radius)
	{
		this->position = position;
		this->velocity = velocity;
		this->mass = mass;
		this->isTriggered = isTriggerd;
	}

	void Circle::Init()
	{
		ActorObject::Init();
	}

	void Circle::Update(const float& elapsedTime)
	{
		ActorObject::Update(elapsedTime);
	}

	void Circle::Render()
	{
		ActorObject::Render();
		BanZ::BanGame::Get()->DrawCircle(this->position, this->radius,0,BanZ::COLOR::WHITE);
	}

	void Circle::OnDestroy()
	{
	}
}
