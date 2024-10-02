#pragma once
#include "../GSM/myBaseLevel.h"
#include "../ComponentManager/GameObject.h"
#include "AEEngine.h"
#include <string>

namespace Levels
{
	class MainLevel : public GSM::BaseLevel
	{
		int cnt;
		GO* player1;
		GO* player2;
		GO* ball;
		GO* bgmaudio;
		GO* sfxaudio;

		GO* rigid;
		AEVec2 Velocity;

		static int p1Score, p2Score;

	public:
		void SetScore(int p);
		int GetScore(int p);


		void Init() override;
		void Update() override;
		void Exit() override;
	};
}

