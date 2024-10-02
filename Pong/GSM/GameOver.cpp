#include "GameOver.h"
#include "myGameStateManager.h"
#include "myMainLevel.h"

s8 winplayerFont, commentFont;

int Levels::GameOver::winPlayer;

void Levels::GameOver::SetWinPlayer(int n)
{
	if (n == 1)
		winPlayer = 1;
	else if (n == 2)
		winPlayer = 2;
}

void Levels::GameOver::Init()
{
	winplayerFont = AEGfxCreateFont("Assets/esamanru-Bold.ttf", 20);
}

void Levels::GameOver::Update()
{
	if (winPlayer == 1)
		AEGfxPrint(winplayerFont, "Player 1 Win!!", -0.3, 0, 1, 1, 1, 1, 1);
	else if (winPlayer == 2)
		AEGfxPrint(winplayerFont, "Player 2 Win!!", -0.3, 0, 1, 1, 1, 1, 1);

	AEGfxPrint(winplayerFont, "Press R Restart", -0.15, -0.3, 0.5, 1, 1, 1, 1);
	AEGfxPrint(winplayerFont, "Press ESC Exit", -0.15, -0.4, 0.5, 1, 1, 1, 1);

	if (AEInputCheckCurr(AEVK_R))
	{
		GSM::GameStateManager* gsm = GSM::GameStateManager::GetGSMPtr();
		gsm->ChangeLevel(new Levels::MainLevel);
	}
}

void Levels::GameOver::Exit()
{
	//AEGfxDestroyFont(winplayerFont);
	//AEGfxDestroyFont(commentFont);
}
