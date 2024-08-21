#include <iostream>
#include "myMainLevel.h"
#include "myGameStateManager.h"
#include "../ComponentManager/GameObject.h"
#include "../Components/TransformComp.h"
#include "../Components/SpriteComp.h"
#include "../Components/Rigidbody.h"
#include "../Components/AudioComp.h"
#include "../Components/PlayerComp.h"
#include "../Components/CollisionComp.h"


void Levels::MainLevel::Init()
{
	//player1 °´Ã¼ ÃÊ±âÈ­	
	player1 = new GO();
	TransformComp* player1Transform = player1->AddComp<TransformComp>();
	SpriteComp* player1Sprite = player1->AddComp<SpriteComp>();
	//RigidbodyComp* player1RigidBody = player1->AddComp<RigidbodyComp>();
	PlayerComp* player1Move = player1->AddComp<PlayerComp>();
	player1Move->SetNum(1);
	player1Transform->SetPos({ -800,0 });
	player1Transform->SetScale({ 40,80 });
	//player1Sprite->GetColor

	//player2 °´Ã¼ ÃÊ±âÈ­
	player2 = new GO();
	TransformComp* player2Transform = player2->AddComp<TransformComp>();
	SpriteComp* player2Sprite = player2->AddComp<SpriteComp>();
	//RigidbodyComp* player2RigidBody = player2->AddComp<RigidbodyComp>();
	PlayerComp* player2Move = player2->AddComp<PlayerComp>();
	player2Move->SetNum(2);
	player2Transform->SetPos({ 800,0 });
	player2Transform->SetScale({ 40,80 });
	
	ball = new GO();
	TransformComp* ballTransform = ball->AddComp<TransformComp>();
	SpriteComp* ballSprite = ball->AddComp<SpriteComp>();
	RigidbodyComp* ballRigidBody = ball->AddComp<RigidbodyComp>();
	//ballMove->SetNum(3);
	ballTransform->SetPos({ 0,0 });
	ballTransform->SetScale({ 20,20 });

	ballRigidBody->SetPlayer(player1, player2);

	//CollisionComp* ballCollision = ball->AddComp<CollisionComp>();
	//ballCollision->SetPlayer(player1, player2);

	
	


	cnt = 0;

	std::cout << "Main Level Init" << std::endl;
}

void Levels::MainLevel::Update()
{
	//TransformComp* trs = player1->FindComp<TransformComp>();
	//SpriteComp* spr = player1->FindComp<SpriteComp>();
	//AudioComp* audio = player->FindComp<AudioComp>();

	//if (trs)
	//{
	//	trs->SetPos({ trs->GetPos().x + 1, trs->GetPos().y });
	//	std::cout << trs->GetPos().x << std::endl;
	//	if (trs->GetPos().x > 800)
	//		trs->SetPos({ -800, 0 });
	//	if (cnt % 10 == 0)
	//		trs->SetRot(trs->GetRot() + 0.5f);
	//
	//	trs->SetScale({ trs->GetScale().x * 1.01f, trs->GetScale().y * 1.01f });
	//}

	AEGfxMeshStart();
}

void Levels::MainLevel::Exit()
{
	std::cout << "Main level Exit" << std::endl;
	delete player1;
	delete player2;
}
