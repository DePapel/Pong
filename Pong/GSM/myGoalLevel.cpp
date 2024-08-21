#include "myGoalLevel.h"
#include "myGameStateManager.h"
#include <iostream>

void Levels::GoalLevel::Init()
{
	std::cout << "Goal Level Init" << std::endl;
}

void Levels::GoalLevel::Update()
{
	std::cout << "Goal Level Update" << std::endl;
	std::cout << "You win" << std::endl;

	GSM::GameStateManager::GetGSMPtr()->ChangeLevel(nullptr);
}

void Levels::GoalLevel::Exit()
{
	std::cout << "Goal Level Exit" << std::endl;
}
