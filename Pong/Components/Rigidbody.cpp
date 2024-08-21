#include "Rigidbody.h"
#include "TransformComp.h"
#include "PlayerComp.h"
#include "AEEngine.h"
#include <iostream>
#include "../GSM/myMainLevel.h"
#include "../Components/CollisionComp.h"

bool RigidbodyComp::CheckEpsilon(float v, float EP)
{
    if (v < -EP || v > EP)
        return true;

    return false;
}

RigidbodyComp::RigidbodyComp(GO* owner) : EngineComp(owner), Velocity(), MaxVelocity()
{
    Velocity.x = -400;
    Velocity.y = 400;
    MaxVelocity.x = 800;
    MaxVelocity.y = 800;
}

void RigidbodyComp::AddVelocity(float x, float y)
{
    Velocity.x += x;
    Velocity.y += y;

    Velocity.x = AEClamp(Velocity.x, -MaxVelocity.x, MaxVelocity.x);
    Velocity.y = AEClamp(Velocity.y, -MaxVelocity.y, MaxVelocity.y);
}

void RigidbodyComp::SetPlayer(GO* obj1, GO* obj2)
{
    colliPlayer1 = obj1;
    colliPlayer2 = obj2;
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

    //Get the transform
    TransformComp* ball = mOwner->FindComp<TransformComp>();
    TransformComp* p1 = colliPlayer1->FindComp<TransformComp>();
    TransformComp* p2 = colliPlayer2->FindComp<TransformComp>();
    if (!ball)
        return false;

    float x, y;
    if (CheckEpsilon(Velocity.x) == false)
        Velocity.x = 0;
    if (CheckEpsilon(Velocity.y) == false)
        Velocity.y = 0;

    AEVec2 n;
    AEVec2 pro;
    float maxWidth = 800, maxHeight = 450;
    //collision overline
    //CollisionComp* check = mOwner->FindComp<CollisionComp>();

    AEVec2 ballCor;
    AEVec2Set(&ballCor, ball->GetScale().x / 2.f, ball->GetScale().y / 2.f);
    AEVec2 playerCor;
    AEVec2Set(&playerCor, p1->GetScale().x / 2.f, p1->GetScale().y / 2.f);
    
    //if (check->Collision(ball->GetPos(), p1->GetPos())) //way2
    //if (ball->GetPos().y >= maxHeight) //way1
    if(Collision(ball->GetPos(), p1->GetPos(), p2->GetPos(), ballCor, playerCor)) //way3
    {
        n = { 0, -1 };
        AEVec2Project(&pro, &Velocity, &n);
        AEVec2Scale(&pro, &pro, -1);
        AEVec2Scale(&pro, &pro, 2);

        AEVec2Add(&Velocity, &Velocity, &pro);
    }
    //collision underline
    //else if (check->Collision(ball->GetPos(), p1->GetPos())) //way 2
    //if (ball->GetPos().y <= -maxHeight) //way 1
    else if (Collision(ball->GetPos(), p1->GetPos(), p2->GetPos(), ballCor, playerCor)) //way 3
    {
        n = { 0, 1 };
        AEVec2Project(&pro, &Velocity, &n);
        AEVec2Scale(&pro, &pro, -1);
        AEVec2Scale(&pro, &pro, 2);

        AEVec2Add(&Velocity, &Velocity, &pro);
    }
    //Collision Player and Ball
    //else if (Collision(ball->GetPos(), p1->GetPos(), p2->GetPos(), ballCor, playerCor)) //way 3
    if (ball->GetPos().x - ballCor.x <= p1->GetPos().x + playerCor.x
        && p1->GetPos().y - playerCor.y <= ball->GetPos().y + ballCor.y
        && p1->GetPos().y + playerCor.y >= ball->GetPos().y - ballCor.y) //way 1
    {
        n = { 1, 0 };
        AEVec2Project(&pro, &Velocity, &n);
        AEVec2Scale(&pro, &pro, -1);
        AEVec2Scale(&pro, &pro, 2);

        AEVec2Add(&Velocity, &Velocity, &pro);
    }
    if (ball->GetPos().x + ballCor.x >= p2->GetPos().x - playerCor.x
        && p2->GetPos().y - playerCor.y <= ball->GetPos().y + ballCor.y
        && p2->GetPos().y + playerCor.y >= ball->GetPos().y - ballCor.y)
    {
        n = { -1, 0 };
        AEVec2Project(&pro, &Velocity, &n);
        AEVec2Scale(&pro, &pro, -1);
        AEVec2Scale(&pro, &pro, 2);

        AEVec2Add(&Velocity, &Velocity, &pro);
    }



    x = ball->GetPos().x + Velocity.x * AEFrameRateControllerGetFrameTime();
    y = ball->GetPos().y + Velocity.y * AEFrameRateControllerGetFrameTime();
    ball->SetPos({ x,y });
    return true;
}
