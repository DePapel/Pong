#pragma once
#include "AEVec2.h"
#include "../ComponentManager/EngineComp.h"

class RigidbodyComp : public EngineComp
{
	float drag = 1.05f;

	AEVec2 Velocity;
	AEVec2 MaxVelocity;
	GO* colliPlayer1;
	GO* colliPlayer2;
	bool CheckEpsilon(float v, float EP = EPSILON);

public:
	RigidbodyComp(GO* owner);

	void AddVelocity(float x, float y);
	void SetPlayer(GO* obj1, GO* obj2);

	void ClearVelocity();

	bool Update() override;
};