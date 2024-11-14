#include "ActorObject.h"

namespace BanZ
{
	void ActorObject::Init()
	{
		angle = 0;
	}

	void ActorObject::Update(const float& elapsedTime)
	{
		this->position += this->velocity * elapsedTime;
	}

	void ActorObject::Render()
	{
	}

	void ActorObject::OnDestroy()
	{
	}
}
