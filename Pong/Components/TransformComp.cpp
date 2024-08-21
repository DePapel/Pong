#include "TransformComp.h"
#include <iostream>

void TransformComp::CalculateMatrix()
{
	//Create a translate matrix
	AEMtx33 translateMtx;
	AEMtx33Trans(&translateMtx, pos.x, pos.y);

	//Create a Rotation matrix
	AEMtx33 rotationMtx;
	AEMtx33Rot(&rotationMtx, rot);

	//Create a scale matrix
	AEMtx33 scaleMtx;
	AEMtx33Scale(&scaleMtx, scale.x, scale.y);

	//Concatenate them
	AEMtx33Concat(&transformMatrix, &rotationMtx, &scaleMtx);
	AEMtx33Concat(&transformMatrix, &translateMtx, &transformMatrix);
}

TransformComp::TransformComp(GO* owner) : EngineComp(owner), pos(), scale(), rot(0), transformMatrix()
{
	pos.x = 0;
	pos.y = 0;
	
	scale.x = 1;
	scale.y = 1;

	CalculateMatrix();
}

bool TransformComp::Update()
{
	if (BaseComponent::Update() == false)
		return false;

	CalculateMatrix();

	//PrintMatrix();

	return true;
}

void TransformComp::SetPos(const AEVec2& otherPos)
{
	this->pos = otherPos;

	CalculateMatrix();
}

void TransformComp::SetScale(const AEVec2& otherScale)
{
	this->scale = otherScale;

	CalculateMatrix();
}

void TransformComp::SetRot(const float& otherRot)
{
	this->rot = otherRot;

	CalculateMatrix();
}

void TransformComp::PrintMatrix()
{
	std::cout << "Printing Transform Comp. With this values: " << std::endl;
	std::cout << "Translate : " << pos.x << " " << pos.y << std::endl;
	std::cout << "Rotation  : " << rot << std::endl;
	std::cout << "Scale     : " << scale.x << " " << scale.y << std::endl << std::endl;

	std::cout << "---------------------------------" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << "|";
		for (int x = 0; x < 3; x++)
		{
			std::cout << " " << transformMatrix.m[i][x];
		}

		std::cout << " |";
		std::cout << std::endl;
	}
	std::cout << "---------------------------------" << std::endl;
}
