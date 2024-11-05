#pragma once
#include "DataFormat.h"	
namespace BanZ
{
	class ActorObject
	{
	public:
		void virtual Init();
		void virtual Update(const float& elapsedTime);
		void virtual Render();
		void virtual OnDestroy();
	protected:
		VECTOR2 position;
		VECTOR2 velocity;
	};
}
