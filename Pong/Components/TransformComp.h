#pragma once
#include "../ComponentManager/GameObject.h"
#include "../ComponentManager/EngineComp.h"
//#include "../RTTI/BaseRTTI.h"
#include "AEMath.h"

class TransformComp : public EngineComp
{
	AEVec2 pos;
	AEVec2 scale;
	float rot;
	AEMtx33 transformMatrix;

	void CalculateMatrix();

public:
	TransformComp(GO* owner);

	bool Update() override;

	//Gettors
	const AEVec2& GetPos() const { return pos; }
	const AEVec2& GetScale() const { return scale; }
	const float& GetRot() const { return rot; }
	const AEMtx33& GetMatrix() const { return transformMatrix; }

	//Mutators
	void SetPos(const AEVec2& otherPos);
	void SetScale(const AEVec2& otherScale);
	void SetRot(const float& otherRot);

	//Other Fn
	void PrintMatrix();

	//For the RTTI
	//static BaseRTTI* CreateTransformComp();
	//std::string GetType() override;
	//static constexpr const char* TransformTypeName = "TransformComp";
};