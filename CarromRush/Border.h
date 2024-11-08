#pragma once
#include "ActorObject.h"
namespace BanZ
{
    class Border : public ActorObject
    {
	private:
		VECTOR2 borderEdge;
	public:
		Border();
		Border(VECTOR2 position, VECTOR2 borderEdge);
		Border(VECTOR2 position, VECTOR2 borderEdge, float mass);
		void Init() override;
		void Update(const float& elapsedTime) override;
		void Render() override;
		void OnDestroy() override;
		const VECTOR2& GetBorderEdge() { return borderEdge; }
    };
}

