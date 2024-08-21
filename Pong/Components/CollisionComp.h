#pragma once
#include "AEVec2.h"
#include "../ComponentManager/GameObject.h"
#include "../ComponentManager/EngineComp.h"

//class CollisionComp : public EngineComp
//{
//	GO* colliball;
//	GO* colliPlayer1;
//	GO* colliPlayer2;
//public:
//	CollisionComp(GO* owner);
//	void SetPlayer(GO* p1, GO* p2);
//
//	bool Collision(AEVec2 ballPos, AEVec2 p1Pos);
//	bool Update() override;
//};

bool Collision(AEVec2 ballPos, AEVec2 p1Pos, AEVec2 p2Pos, AEVec2 ballCor, AEVec2 playerCor);