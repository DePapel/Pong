#pragma once

#include "../ComponentManager/Manager.h"
#include "../ComponentManager/GraphicsComp.h"
#include "../ComponentManager/GameObject.h"

#include "AEMath.h"
#include "AEGraphics.h"
#include <string>

class SpriteComp : public GraphicsComp
{
public:
	struct Color
	{
		unsigned char r = 0;
		unsigned char g = 0;
		unsigned char b = 0;
	};
private:
	Color mColor;

	//texture
	AEGfxTexture* mTex = nullptr;

public:
	SpriteComp(GO* owner);
	~SpriteComp();

	//Draw
	bool Update() override;

	//Gettors/Settors
	Color& GetColor() { return mColor; }

	void SetTexture(std::string s);
};