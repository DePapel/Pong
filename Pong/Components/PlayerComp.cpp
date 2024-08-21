#include "../Components/PlayerComp.h"
#include "../ComponentManager/LogicComp.h"
#include "../Components/TransformComp.h"
#include "../Components/Rigidbody.h"
#include "AEEngine.h"

PlayerComp::PlayerComp(GO* owner) : LogicComp(owner) {}

void PlayerComp::SetNum(int num)
{
	playerNum = num;
}

int PlayerComp::GetNum()
{
	return playerNum;
}

bool PlayerComp::Update()
{
	if (BaseComponent::Update() == false)
		return false;

	TransformComp* t = mOwner->FindComp<TransformComp>();
	if (!t)
		return false;

	//RigidbodyComp* r = mOwner->FindComp<RigidbodyComp>();
	//if (!r)
	//	return false;

	//Check for input
	if (AEInputCheckCurr(AEVK_W) && playerNum == 1)
	{
		//Move my transform
		t->SetPos({ -800, t->GetPos().y + 15 });
		//r->AddVelocity(0, speed);
	}
	//Check for input
	if (AEInputCheckCurr(AEVK_S) && playerNum == 1)
	{
		//Move my transform
		t->SetPos({ -800, t->GetPos().y - 15 });
		//r->AddVelocity(0, -speed);
	}
	//Check for input
	if (playerNum == 2)
	{
		s32 mouseX, mouseY;
		AEInputGetCursorPosition(&mouseX, &mouseY);
		t->SetPos({ 800, -(float)mouseY +450});
	}

	//if) player Outrange of view
	if (t->GetPos().y <= -410)
		t->SetPos({ t->GetPos().x,-410 });
	if (t->GetPos().y >= 410)
		t->SetPos({ t->GetPos().x,410 });



	return false;
}

