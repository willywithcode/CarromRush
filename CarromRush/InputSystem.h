#pragma once
#include "ActorManager.h"
#include "Circle.h"
#include "Border.h"
#include "PhysicsEngine.h"
namespace BanZ
{
	class InputSystem : public BanZ::SingletonTemplate<InputSystem>
	{
		private:
			Circle* selectedCircle;
			VECTOR2 startDragPos;
			VECTOR2 endDragPos;
			bool isDragging;
			float maxForce = 500.0f;
			float maxLine = 200.0f;
		public:
			InputSystem();
			void OnMouseDown();
			void OnMouseUp(const VECTOR2& moveDirection);
			void OnMouseMove(VECTOR2& moveDirection);
			void ProcessInput();
			void SetSelectedCircle(Circle* circle) { selectedCircle = circle; }
	};
}

