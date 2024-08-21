#pragma once
#include "../GSM/myBaseLevel.h"
#include "../ComponentManager/GameObject.h"

namespace Levels
{
	class MainLevel : public GSM::BaseLevel
	{
		int cnt;
		GO* player1;
		GO* player2;
		GO* ball;

	public:
		void Init() override;
		void Update() override;
		void Exit() override;
	};
}