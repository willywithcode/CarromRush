#pragma comment(lib, "lib/GameEngine.lib")
#include "BanGame.h"
#include "ActorManager.h"
#include "Circle.h"
using namespace BanZ;
void maingame(const float& elapsedTime)
{
	ActorManager::getInstance()->Update(elapsedTime);
}

void sceneInit()
{
	ActorManager::getInstance()->Init();
    Circle* circle1 = new Circle(50.0f, VECTOR2(0,0),VECTOR2(10,10));
	ActorManager::getInstance()->PushActor(circle1);
    Circle* circle2 = new Circle(50.0f, VECTOR2(1280, 720), VECTOR2(-10, -10));
    ActorManager::getInstance()->PushActor(circle2);
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