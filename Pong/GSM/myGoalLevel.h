#pragma once
#include "../GSM/myBaseLevel.h"

namespace Levels
{
	class GoalLevel :public GSM::BaseLevel
	{
	public:
		void Init() override;
		void Update() override;
		void Exit() override;
	};
}