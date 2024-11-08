#pragma once
#include "DataFormat.h"	
#include "BanGame.h"
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
		float GetMass() { return mass; }
	protected:
		VECTOR2 position;
		VECTOR2 velocity;
		float mass;
	};
}
