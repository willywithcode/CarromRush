#pragma once
#include "SingletonTemplate.h"
#include "ActorObject.h"
#include <vector>
namespace BanZ {
	class ActorManager : public SingletonTemplate<ActorManager>
	{
	public:
		void Init();
		void Update(const float& elapsedTime);
		void Render();
		template<typename T>
		T* CreateActor();
		void PushActor(ActorObject*);
		void DestroyActor(ActorObject*);
		void DestroyActors();
	private:
		std::vector<ActorObject*> actors;
	};
}

