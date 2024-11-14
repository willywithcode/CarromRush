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
		Circle(float radius, BanZ::VECTOR2 position);
		Circle(float radius, BanZ::VECTOR2 position, BanZ::VECTOR2 velocity);
		Circle(float radius, BanZ::VECTOR2 position, BanZ::VECTOR2 velocity, float mass);

		void Init() override;
		void Update(const float& elapsedTime) override;
		void virtual Render() override;
		void OnDestroy() override;
		float GetRadius() { return radius; }
	private:
		float radius;
	};
}

