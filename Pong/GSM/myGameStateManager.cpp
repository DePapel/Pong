#include "myGameStateManager.h"
#include "../GSM/myBaseLevel.h"
#include "../ComponentManager/Manager.h"
#include "../ComponentManager/EngineComp.h"
#include "../ComponentManager/LogicComp.h"
#include "../ComponentManager/GraphicsComp.h"
GSM::GameStateManager* GSM::GameStateManager::ptr = nullptr;
GSM::GameStateManager::GameStateManager() : previousLevel(nullptr), currentLevel(nullptr) {};

GSM::GameStateManager::~GameStateManager()
{
	if (previousLevel)
		delete previousLevel;
	if (currentLevel)
		delete currentLevel;
}

GSM::GameStateManager* GSM::GameStateManager::GetGSMPtr()
{
	if (ptr == nullptr)
		ptr = new GameStateManager;

	return ptr;
}

void GSM::GameStateManager::DeleteGSM()
{
	if (ptr)
	{
		delete ptr;
		ptr = nullptr;
	}
}

void GSM::GameStateManager::Init()
{
	if (currentLevel)
		currentLevel->Init();
}

void GSM::GameStateManager::Update()
{
	if (currentLevel)
	{
		//EngineManager::Instance()->Update();
		//LogicManager::Instance()->Update();
		//GraphicsManager::Instance()->Update();

		//How to add Manager's Update???
		Manager<EngineComp>::getPtr()->Update();
		Manager<LogicComp>::getPtr()->Update();
		Manager<GraphicsComp>::getPtr()->Update();



		currentLevel->Update();
	}
}

void GSM::GameStateManager::Exit()
{
	if (currentLevel)
		currentLevel->Exit();
}

void GSM::GameStateManager::ChangeLevel(BaseLevel* newLvl)
{
	if (previousLevel)
		delete previousLevel;
	previousLevel = currentLevel;

	//Exit the current level;
	Exit();
	//Current level is now the "next" level
	currentLevel = newLvl;
	//Initialize the level
	Init();
}

bool GSM::GameStateManager::shouldExit()
{
	return currentLevel == nullptr;
}
