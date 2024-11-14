#pragma once
#include "ActorObject.h"
class CarromBoard : public BanZ::ActorObject
{
public:
	CarromBoard();
	CarromBoard(float width, float height);
	CarromBoard(float width, float height, BanZ::VECTOR2 position);
	void Render() override;
protected:
	float width;
	float height;
};

