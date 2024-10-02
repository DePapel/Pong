#pragma once
#include "AEVec2.h"
#include "../ComponentManager/EngineComp.h"
#include "../GSM/myMainLevel.h"

class RigidbodyComp : public EngineComp
{
	float drag = 1.05f;

	AEVec2 Velocity;
	AEVec2 MaxVelocity;
	bool CheckEpsilon(float v, float EP = EPSILON);
	
public:
	RigidbodyComp(GO* owner);
	void AddVelocity(float x, float y);
	void ClearVelocity();

	AEVec2 GetVelocity();

	bool Update() override;
};