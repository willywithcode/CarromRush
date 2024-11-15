#pragma comment(lib, "lib/GameEngine.lib")
#include "BanGame.h"
#include "ActorManager.h"
#include "Circle.h"
#include"PhysicsEngine.h"
#include "Border.h"
#include "InputSystem.h"
#include "WhiteCoin.h"
#include "BlackCoin.h"
#include "RedCoin.h"
#include "Striker.h"
#include "Hole.h"
#include "CarromBoard.h"
using namespace BanZ;
VECTOR2 screenSize = { 720.0f, 720.0f };
void maingame(const float& elapsedTime)
{
	ActorManager::getInstance()->Update(elapsedTime);
	PhysicsEngine::getInstance()->Update(elapsedTime);
    InputSystem::getInstance()->ProcessInput();
}

void sceneInit()
{
	float coinRadius = 15.0f;
	ActorManager::getInstance()->Init();
    Circle* circle1 = new Striker(25.0f, VECTOR2(300,100));

    // GameEngine todo 1
    auto temp = dynamic_cast<Striker*>(circle1);
    temp->LoadSprite("../Data/Images/cocai_fix.png");
    temp->SetEffect(BanGame::Get()->CreateSprite("../Data/Images/cocai_effect_fix.png"));

	ActorManager::getInstance()->PushActor(circle1);
	InputSystem::getInstance()->SetSelectedCircle(circle1);

    float distance = coinRadius * 2;
    bool isBlack = false;
    VECTOR2 centerPos(360, 360);
    Circle* redCoin = new RedCoin(coinRadius, centerPos);
    ActorManager::getInstance()->PushActor(redCoin);

    for (int layer = 1; layer <= 3; ++layer) {
        int numCoins = layer * 6;
        float angleStep = 360.0f / numCoins;

        for (int i = 0; i < numCoins; ++i) {
            float angle = i * angleStep;
            float radian = angle * (3.14159265359f / 180.0f);
            VECTOR2 pos = centerPos + VECTOR2(cos(radian), sin(radian)) * distance * layer;

            Circle* coin = nullptr;
            if (isBlack)
                coin = new BlackCoin(coinRadius, pos);
            else
                coin = new WhiteCoin(coinRadius, pos);

            isBlack = !isBlack;
            ActorManager::getInstance()->PushActor(coin);
        }
    }
    
	Border* border1 = new Border(VECTOR2(0, screenSize.y/2), VECTOR2(40, screenSize.y));
	ActorManager::getInstance()->PushActor(border1);
	Border* border2 = new Border(VECTOR2(screenSize.x, screenSize.y/2), VECTOR2(40, screenSize.y));
	ActorManager::getInstance()->PushActor(border2);
	Border* border3 = new Border(VECTOR2(screenSize.x/2, 0), VECTOR2(screenSize.x, 40));
	ActorManager::getInstance()->PushActor(border3);
	Border* border4 = new Border(VECTOR2(screenSize.x/2, screenSize.y), VECTOR2(screenSize.x, 40));
	ActorManager::getInstance()->PushActor(border4);
    Circle* hole1 = new Hole(8.0f, VECTOR2(71, 649));        
    Circle* hole2 = new Hole(8.0f, VECTOR2(71, 71));
    Circle* hole3 = new Hole(8.0f, VECTOR2(649, 649));
    Circle* hole4 = new Hole(8.0f, VECTOR2(649, 71));
    ActorManager::getInstance()->PushActor(hole1);
    ActorManager::getInstance()->PushActor(hole2);
    ActorManager::getInstance()->PushActor(hole3);
    ActorManager::getInstance()->PushActor(hole4);

	CarromBoard* board = new CarromBoard(screenSize.x, screenSize.y, screenSize/2);
	ActorManager::getInstance()->PushActor(board);
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
    banGame->CreateGameWindow(hInstance, nCmdShow, L"Begin Game Programming", L"gamewindow", screenSize.x, screenSize.y);
    banGame->CreateCamera(screenSize.x, screenSize.y, 0.1f, 1000.f);

    auto Init = std::bind(sceneInit);
    auto Update = std::bind(maingame, std::placeholders::_1);
    auto Render = std::bind(sceneRender);

    banGame->GameRun(Init, Update, Render);

    delete banGame;
    return 0;
}