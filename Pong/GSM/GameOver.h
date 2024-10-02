#pragma once
#include "../GSM/myBaseLevel.h"
#include "AEEngine.h"
#include <string>

namespace Levels
{
	class GameOver : public GSM::BaseLevel
	{
		static int winPlayer;

	public:
		void SetWinPlayer(int n);

		void Init() override;
		void Update() override;
		void Exit() override;
	};
}