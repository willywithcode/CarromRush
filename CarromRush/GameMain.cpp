#pragma comment(lib, "lib/GameEngine.lib")
#include "BanGame.h"
#include "ActorManager.h"
#include "Circle.h"
#include"PhysicsEngine.h"
#include "Border.h"
#include "InputSystem.h"
using namespace BanZ;
void maingame(const float& elapsedTime)
{
	ActorManager::getInstance()->Update(elapsedTime);
	PhysicsEngine::getInstance()->Update(elapsedTime);
    InputSystem::getInstance()->ProcessInput();
}

void sceneInit()
{
	ActorManager::getInstance()->Init();
    Circle* circle1 = new Circle(50.0f, VECTOR2(300,300));
	ActorManager::getInstance()->PushActor(circle1);
	InputSystem::getInstance()->SetSelectedCircle(circle1);
    Circle* circle2 = new Circle(50.0f, VECTOR2(700, 300));
    ActorManager::getInstance()->PushActor(circle2);
	Border* border1 = new Border(VECTOR2(100, 360), VECTOR2(50, 600));
	ActorManager::getInstance()->PushActor(border1);
	Border* border2 = new Border(VECTOR2(1180, 360), VECTOR2(50, 600));
	ActorManager::getInstance()->PushActor(border2);
	Border* border3 = new Border(VECTOR2(640, 100), VECTOR2(1200, 50));
	ActorManager::getInstance()->PushActor(border3);
	Border* border4 = new Border(VECTOR2(640, 620), VECTOR2(1200, 50));
	ActorManager::getInstance()->PushActor(border4);
}

void sceneRender()
{
    BanGame::Get()->SetBackgroundColor(COLOR::BLACK);
    ActorManager::getInstance()->Render();
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    auto banGame = BanGame::Get();
    banGame->CreateGameWindow(hInstance, nCmdShow, L"Begin Game Programming", L"gamewindow", 1280, 720);
    banGame->CreateCamera(1280, 720, 0.1f, 1000.f);

    auto Init = std::bind(sceneInit);
    auto Update = std::bind(maingame, std::placeholders::_1);
    auto Render = std::bind(sceneRender);

    banGame->GameRun(Init, Update, Render);

    delete banGame;
    return 0;
}