#pragma once
#include "DataFormat.h"
#include "ActorObject.h"
#include "BanGame.h"
class Circle : public BanZ::ActorObject
{
public:
	Circle();
	Circle(float radius);
	Circle(float radius, BanZ::VECTOR2 position);
	Circle(float radius, BanZ::VECTOR2 position, BanZ::VECTOR2 velocity);

	void Init() override;
	void Update(const float& elapsedTime) override;
	void Render() override;
	void OnDestroy() override;
private:
	float radius;
};

