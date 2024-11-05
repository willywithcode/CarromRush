#include "ActorManager.h"

namespace BanZ {
	void ActorManager::Init()
	{
		for (auto actor : this->actors)
		{
			actor->Init();
		}
	}

	void ActorManager::Update(const float& elapsedTime)
	{
		for (auto actor : this->actors)
		{
			actor->Update(elapsedTime);
		}

	}

	void ActorManager::Render()
	{
		for (auto actor : this->actors)
		{
			actor->Render();
		}

	}
	void ActorManager::PushActor(ActorObject* actor)
	{
		this->actors.push_back(actor);
	}
	void ActorManager::DestroyActor(ActorObject* actor)
	{
		if (actor == nullptr) return;
		for (std::vector<ActorObject*>::iterator it = this->actors.begin(); it != this->actors.end(); it++)
		{
			if (*it == actor)
			{
				this->actors.erase(it);
				actor->OnDestroy();
				delete actor;
				break;
			}
		}
	}
	void ActorManager::DestroyActors()
	{
		for (auto actor : this->actors)
		{
			delete actor;
		}
		this->actors.clear();
	}
	template<typename T>
	T* ActorManager::CreateActor()
	{
		static_assert(std::is_base_of<ActorObject, T>::value, "T must be derived from ActorObject");
		T* actor = new T();
		this->actors.push_back(actor);
		return actor;
	}

}