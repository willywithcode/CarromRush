#include "InputSystem.h"
#include"iostream"
BanZ::InputSystem::InputSystem()
{
	selectedCircle = nullptr;
	startDragPos = VECTOR2{ 0, 0 };
	endDragPos = VECTOR2{ 0, 0 };
	isDragging = false;
}

void BanZ::InputSystem::OnMouseDown()
{
    auto banGame = BanGame::Get();
	VECTOR2 mousePos = banGame->GetMousePosition();

    float distance = banGame->Length(mousePos - selectedCircle->GetPosition());
    if (distance <= selectedCircle->GetRadius())
    {
        startDragPos = mousePos;  
        isDragging = true;       
    }

}

void BanZ::InputSystem::OnMouseUp(const VECTOR2& moveDirection)
{
    isDragging = false;  
    auto banGame = BanGame::Get();
	float force = banGame->Length(startDragPos - endDragPos);
	selectedCircle->SetVelocity(moveDirection*force);
}


void BanZ::InputSystem::OnMouseMove(VECTOR2& moveDirection)
{
    auto banGame = BanGame::Get();
    VECTOR2 mousePos = banGame->GetMousePosition();
    VECTOR2 dragVector = mousePos - startDragPos;

    VECTOR2 reverseDragVector = -dragVector;
	endDragPos = startDragPos+reverseDragVector;
    banGame->DrawLine(selectedCircle->GetPosition(), endDragPos, 10.0f, 0, COLOR::GREEN);
	moveDirection = banGame->Normalize(reverseDragVector);
}

void BanZ::InputSystem::ProcessInput()
{
	auto banGame = BanGame::Get();
	VECTOR2 moveDirection = VECTOR2{ 0, 0 };
    if (isDragging)
	{
		OnMouseMove(moveDirection);
	}

	if (banGame->GetPress(Mouse::LeftMouse))
	{
		OnMouseDown();
	}

	if(banGame->GetRelease(Mouse::LeftMouse) && isDragging)
	{
		OnMouseUp(moveDirection);
	}
}

