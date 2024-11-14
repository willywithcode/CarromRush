#pragma once
#include "DataFormat.h"	
#include "BanGame.h"
#include <functional>
namespace BanZ
{
	class ActorObject
	{
	public:
		void virtual Init();
		void virtual Update(const float& elapsedTime);
		void virtual Render();
		void virtual OnDestroy();
		VECTOR2& GetPosition() { return position; }
		VECTOR2& GetVelocity() { return velocity; }
		void SetPosition(VECTOR2 position) { this->position = position; }
		void SetVelocity(VECTOR2 velocity) { this->velocity = velocity; }
		float GetMass() { return mass; }
		void virtual OnTriggeredEnter(ActorObject*) {};
		bool IsTriggered() { return isTriggered; }
	protected:
		VECTOR2 position;
		VECTOR2 velocity;
		// GameEngine todo 1
		float angle;

		float mass;
		bool isTriggered;
	};
}
