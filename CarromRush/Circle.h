#pragma once
#include "DataFormat.h"
#include "ActorObject.h"
#include "BanGame.h"
namespace BanZ
{
	class Circle : public BanZ::ActorObject
	{
	public:
		Circle();
		Circle(float radius);
		Circle(float radius,bool isTriggered);
		Circle(float radius, BanZ::VECTOR2 position);
		Circle(float radius, BanZ::VECTOR2 position,bool isTriggered);
		Circle(float radius, BanZ::VECTOR2 position, BanZ::VECTOR2 velocity);
		Circle(float radius, BanZ::VECTOR2 position, BanZ::VECTOR2 velocity,bool isTriggered);
		Circle(float radius, BanZ::VECTOR2 position, BanZ::VECTOR2 velocity, float mass, bool isTriggered);

		void Init() override;
		void Update(const float& elapsedTime) override;
		void virtual Render() override;
		void OnDestroy() override;
		float GetRadius() { return radius; }
		bool IsTriggered() { return isTriggered; }
	private:
		float radius;
		bool isTriggered;
	};
}

