#include "Rigidbody.h"
#include "TransformComp.h"
#include "PlayerComp.h"
#include "AEEngine.h"
#include <iostream>
#include "../GSM/myMainLevel.h"
#include "../Components/CollisionComp.h"
#include "../GSM/myGameStateManager.h"

#include "random"

bool RigidbodyComp::CheckEpsilon(float v, float EP)
{
    if (v < -EP || v > EP)
        return true;

    return false;
}

RigidbodyComp::RigidbodyComp(GO* owner) : EngineComp(owner), Velocity(), MaxVelocity()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-1.0, 1.0);

    Velocity.x = dis(gen) * 800.f;
    Velocity.y = dis(gen) * 800.f;
    MaxVelocity.x = 2000;
    MaxVelocity.y = 2000;
}

void RigidbodyComp::AddVelocity(float x, float y)
{
    Velocity.x += x;
    Velocity.y += y;

    Velocity.x = AEClamp(Velocity.x, -MaxVelocity.x, MaxVelocity.x);
    Velocity.y = AEClamp(Velocity.y, -MaxVelocity.y, MaxVelocity.y);
}

AEVec2 RigidbodyComp::GetVelocity()
{
    return Velocity;
}

void RigidbodyComp::ClearVelocity()
{
    Velocity.x = 0;
    Velocity.y = 0;
}

bool RigidbodyComp::Update()
{
    if (BaseComponent::Update() == false)
        return false;

    if (CheckEpsilon(Velocity.x) == false)
        Velocity.x = 0;
    if (CheckEpsilon(Velocity.y) == false)
        Velocity.y = 0;

    return true;
}
