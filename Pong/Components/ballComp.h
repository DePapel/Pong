#pragma once
#include "AEVec2.h"
#include "../ComponentManager/EngineComp.h"


class BallComp : public EngineComp
{
	float speed = 300.f;
	AEVec2 ballVelocity;



};