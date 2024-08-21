#include "CollisionComp.h"
#include "Rigidbody.h"
#include "TransformComp.h"
#include "PlayerComp.h"
#include "AEEngine.h"
#include "../GSM/myMainLevel.h"
#include "../ComponentManager/GameObject.h"
#include <iostream>

//CollisionComp::CollisionComp(GO* owner) : EngineComp(owner)
//{
//}
//
//void CollisionComp::SetPlayer(GO* p1, GO* p2)
//{
//    colliPlayer1 = p1;
//    colliPlayer2 = p2;
//}
//
//bool CollisionComp::Collision(AEVec2 ballPos, AEVec2 p1Pos)
//{
//    //TransformComp* ball = mOwner->FindComp<TransformComp>();
//    //TransformComp* p1 = colliPlayer1->FindComp<TransformComp>();
//    //TransformComp* p2 = colliPlayer2->FindComp<TransformComp>();
//
//    float maxWidth = 800, maxHeight = 450;
//
//    if (ballPos.y >= maxHeight)
//    {
//        return true;
//    }
//    if (ballPos.y <= -maxHeight)
//    {
//        return true;
//    }
//
//    return false;
//}
//
//bool CollisionComp::Update()
//{
//    return true;
//}

float maxWidth = 800, maxHeight = 450;
bool Collision(AEVec2 ballPos, AEVec2 p1Pos, AEVec2 p2Pos, AEVec2 ballCor, AEVec2 playerCor)
{

	if (ballPos.y >= maxHeight)
		return true;
	else if (ballPos.y <= -maxHeight)
		return true;
	else if (ballPos.x - ballCor.x <= p1Pos.x + playerCor.x
		&& p1Pos.y - playerCor.y <= ballPos.y + ballCor.y
		&& p1Pos.y + playerCor.y >= ballPos.y - ballCor.y)
		return true;

	return false;
}
