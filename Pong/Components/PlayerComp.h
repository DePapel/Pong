#pragma once
#include "../ComponentManager/Manager.h"
#include "../ComponentManager/LogicComp.h"
#include "AEVec2.h"

class PlayerComp : public LogicComp
{
	float speed = 500.f;
	int playerNum = 0;

public:
	PlayerComp(GO* owner);
	void SetNum(int num);
	int GetNum();
	bool Update() override;
};

//