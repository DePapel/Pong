#include <iostream>
#include <string>
#include <stdlib.h>
#include "myGameStateManager.h"
#include "myMainLevel.h"
#include "GameOver.h"
#include "myGoalLevel.h"
#include "../ComponentManager/GameObject.h"
#include "../Components/TransformComp.h"
#include "../Components/SpriteComp.h"
#include "../Components/Rigidbody.h"
#include "../Components/AudioComp.h"
#include "../Components/PlayerComp.h"
#include "../Components/CollisionComp.h"
#include "../Resource/ResourceManager.h"
#include "AEAudio.h"
#include <random>
int Levels::MainLevel::p1Score;
int Levels::MainLevel::p2Score;

void Levels::MainLevel::SetScore(int p)
{
	if (p == 1)
		this->p1Score++;
	else if (p == 2)
		this->p2Score++;
}

int Levels::MainLevel::GetScore(int p)
{
	if (p == 1)
		return p1Score;
	else if (p == 2)
		return p2Score;
}

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


	//CollisionComp* ballCollision = ball->AddComp<CollisionComp>();
	//ballCollision->SetPlayer(player1, player2);

	bgmaudio = new GO();
	AudioComp* acompPtr = bgmaudio->AddComp<AudioComp>();
	acompPtr->SetAudio("Assets/bouken.mp3");
	acompPtr->SetMusicLoop(-1);

	rigid = new GO();
	RigidbodyComp* body = new RigidbodyComp(rigid);
	Velocity = body->GetVelocity();


}

void Levels::MainLevel::Update()
{
	TransformComp* ballObj = ball->FindComp<TransformComp>();
	TransformComp* p1 = player1->FindComp<TransformComp>();
	TransformComp* p2 = player2->FindComp<TransformComp>();
	float x, y;

	AEVec2 n;
	AEVec2 pro;
	float maxWidth = 800, maxHeight = 450;

	AEVec2 ballCor;
	AEVec2Set(&ballCor, ballObj->GetScale().x / 2.f, ballObj->GetScale().y / 2.f);
	AEVec2 playerCor;
	AEVec2Set(&playerCor, p1->GetScale().x / 2.f, p1->GetScale().y / 2.f);

	//collision overline
	//if (Collision(ballObj->GetPos(), p1->GetPos(), p2->GetPos(), ballCor, playerCor)) //way3
	if (ballObj->GetPos().y >= maxHeight) //way 1
	{
		n = { 0, -1 };
		AEVec2Project(&pro, &Velocity, &n);
		AEVec2Scale(&pro, &pro, -1);
		AEVec2Scale(&pro, &pro, 2);
		AEVec2Add(&Velocity, &Velocity, &pro);
	}

	//collision underline
	//else if (Collision(ballObj->GetPos(), p1->GetPos(), p2->GetPos(), ballCor, playerCor)) //way 3
	if (ballObj->GetPos().y <= -maxHeight) //way 1
	{
		n = { 0, 1 };
		AEVec2Project(&pro, &Velocity, &n);
		AEVec2Scale(&pro, &pro, -1);
		AEVec2Scale(&pro, &pro, 2);
		AEVec2Add(&Velocity, &Velocity, &pro);
	}

	//Collision Player1 and Ball
	//else if (Collision(ball->GetPos(), p1->GetPos(), p2->GetPos(), ballCor, playerCor)) //way 3
	if (ballObj->GetPos().x - ballCor.x <= p1->GetPos().x + playerCor.x
		&& p1->GetPos().y - playerCor.y <= ballObj->GetPos().y + ballCor.y
		&& p1->GetPos().y + playerCor.y >= ballObj->GetPos().y - ballCor.y) //way 1
	{
		f32 maxAngle = 20.f;
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<> dis(-maxAngle, maxAngle);

		AEVec2 nor = { 0,0 };
		AEVec2Normalize(&nor, &Velocity); //nor.x == cos0, nor.y == sin0
		f32 norangle = AERadToDeg(AEACos(AEDegToRad(nor.x)));

		f32 angle = norangle + dis(gen);

		AEVec2 newUnitvec = { AECos(AEDegToRad(angle)), AESin(AEDegToRad(angle)) };
		AEVec2 newVec = { newUnitvec.x * AEVec2Length(&Velocity), newUnitvec.y * AEVec2Length(&Velocity) };
		AEVec2Set(&Velocity, newVec.x, newVec.y);

		n = { 1, 0 };
		AEVec2Project(&pro, &Velocity, &n);
		AEVec2Scale(&pro, &pro, -1);
		AEVec2Scale(&pro, &pro, 2);
		AEVec2Add(&Velocity, &Velocity, &pro);

		sfxaudio = new GO();
		AudioComp* sfxPtr = sfxaudio->AddComp<AudioComp>();
		sfxPtr->SetAudio("Assets/ore.mp3");
		sfxPtr->SetMusicLoop(0);
	}

	//Collision Player2 and Ball
	if (ballObj->GetPos().x + ballCor.x >= p2->GetPos().x - playerCor.x
		&& p2->GetPos().y - playerCor.y <= ballObj->GetPos().y + ballCor.y
		&& p2->GetPos().y + playerCor.y >= ballObj->GetPos().y - ballCor.y)
	{
		f32 maxAngle = 20.f;
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<> dis(-maxAngle, maxAngle);

		AEVec2 nor = { 0,0 };
		AEVec2Normalize(&nor, &Velocity); //nor.x == cos0, nor.y == sin0
		f32 norangle = AERadToDeg(AEACos(AEDegToRad(nor.x)));

		f32 angle = norangle + dis(gen);

		AEVec2 newUnitvec = { AECos(AEDegToRad(angle)), AESin(AEDegToRad(angle)) };
		AEVec2 newVec = { newUnitvec.x * AEVec2Length(&Velocity), newUnitvec.y * AEVec2Length(&Velocity) };
		AEVec2Set(&Velocity, newVec.x, newVec.y);

		n = { -1, 0 };
		AEVec2Project(&pro, &Velocity, &n);
		AEVec2Scale(&pro, &pro, -1);
		AEVec2Scale(&pro, &pro, 2);
	
		AEVec2Add(&Velocity, &Velocity, &pro);

		sfxaudio = new GO();
		AudioComp* sfxPtr = sfxaudio->AddComp<AudioComp>();
		sfxPtr->SetAudio("Assets/ore.mp3");
		sfxPtr->SetMusicLoop(0);
	}

	x = ballObj->GetPos().x + Velocity.x * AEFrameRateControllerGetFrameTime();
	y = ballObj->GetPos().y + Velocity.y * AEFrameRateControllerGetFrameTime();

	ballObj->SetPos({ x,y });


	if (ballObj->GetPos().x >= maxWidth)
	{
		Levels::MainLevel::p1Score++;
		GSM::GameStateManager* gsm = GSM::GameStateManager::GetGSMPtr();
		gsm->ChangeLevel(new Levels::MainLevel);
	}
	else if (ballObj->GetPos().x <= -maxWidth)
	{
		Levels::MainLevel::p2Score++;
		GSM::GameStateManager* gsm = GSM::GameStateManager::GetGSMPtr();
		gsm->ChangeLevel(new Levels::MainLevel);
	}

	s8 pFont = AEGfxCreateFont("Assets/esamanru-Bold.ttf", 72);

	std::string str1 = std::to_string(Levels::MainLevel::p1Score);
	std::string str2 = std::to_string(Levels::MainLevel::p2Score);

	const char* cstr1 = str1.c_str();
	const char* cstr2 = str2.c_str();

	AEGfxPrint(pFont, cstr1, -0.5, 0.8, 1, 1, 1, 1, 1);
	AEGfxPrint(pFont, cstr2, 0.5, 0.8, 1, 1, 1, 1, 1);

	AEGfxMeshStart();

	if (Levels::MainLevel::p1Score >= 2)
	{
		Levels::MainLevel::p1Score = 0;
		Levels::GameOver* over = new GameOver();
		over->SetWinPlayer(1);
		GSM::GameStateManager* gsm = GSM::GameStateManager::GetGSMPtr();
		gsm->ChangeLevel(new Levels::GameOver);
	}
	else if (Levels::MainLevel::p2Score >= 2)
	{
		Levels::MainLevel::p2Score = 0;
		Levels::GameOver* over = new GameOver();
		over->SetWinPlayer(2);
		GSM::GameStateManager* gsm = GSM::GameStateManager::GetGSMPtr();
		gsm->ChangeLevel(new Levels::GameOver);
	}
}

void Levels::MainLevel::Exit()
{
	std::cout << "Main level Exit" << std::endl;
	delete player1;
	delete player2;
	delete ball;
	delete bgmaudio;
	delete sfxaudio;
	delete rigid;
}
