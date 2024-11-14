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
    Circle* circle1 = new Circle(20.0f, VECTOR2(300,300),false);
	ActorManager::getInstance()->PushActor(circle1);
	InputSystem::getInstance()->SetSelectedCircle(circle1);

    VECTOR2 startPos(700, 300);
    float distance = 40.0f;

    int rows = 5; 
    int index = 0;
    for (int i = 0; i < rows; ++i) {
        int numCircles = i + 1; 
        float offsetX = -distance * (numCircles - 1) / 2.0f;
        for (int j = 0; j < numCircles; ++j) {
            VECTOR2 pos = startPos + VECTOR2(offsetX + j * distance, i * distance);
            Circle* circle = new Circle(20.0f, pos,false);
            ActorManager::getInstance()->PushActor(circle);
        }
    }

	Border* border1 = new Border(VECTOR2(100, 360), VECTOR2(50, 600));
	ActorManager::getInstance()->PushActor(border1);
	Border* border2 = new Border(VECTOR2(1180, 360), VECTOR2(50, 600));
	ActorManager::getInstance()->PushActor(border2);
	Border* border3 = new Border(VECTOR2(640, 100), VECTOR2(1200, 50));
	ActorManager::getInstance()->PushActor(border3);
	Border* border4 = new Border(VECTOR2(640, 620), VECTOR2(1200, 50));
	ActorManager::getInstance()->PushActor(border4);

    Circle* hole1 = new Circle(25.0f, VECTOR2(150, 150),true);        
    Circle* hole2 = new Circle(25.0f, VECTOR2(1130, 150),true);       
    Circle* hole3 = new Circle(25.0f, VECTOR2(150, 570),true);        
    Circle* hole4 = new Circle(25.0f, VECTOR2(1130, 570),true);      
    ActorManager::getInstance()->PushActor(hole1);
    ActorManager::getInstance()->PushActor(hole2);
    ActorManager::getInstance()->PushActor(hole3);
    ActorManager::getInstance()->PushActor(hole4);
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