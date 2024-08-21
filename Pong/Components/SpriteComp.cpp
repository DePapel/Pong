#include "SpriteComp.h"
#include "TransformComp.h"

SpriteComp::SpriteComp(GO* owner) : GraphicsComp(owner)
{
}

SpriteComp::~SpriteComp()
{
	AEGfxTextureUnload(mTex);
}

bool SpriteComp::Update()
{
	if (BaseComponent::Update() == false)
		return false;

	//Create quad
	AEGfxMeshStart();

	AEGfxTriAdd(
		-0.5f, -0.5f, 0xFFFFFFFF, 0, 1,
		0.5f, -0.5f, 0xFFFFFFFF, 1, 1,
		-0.5f, 0.5f, 0xFFFFFFFF, 0, 0
	);

	AEGfxTriAdd(
		0.5f, -0.5f, 0xFFFFFFFF, 1, 1,
		0.5f, 0.5f, 0xFFFFFFFF, 1, 0,
		-0.5f, 0.5f, 0xFFFFFFFF, 0, 0
	);
	AEGfxVertexList* mesh = AEGfxMeshEnd();


	//Set render mode
	AEGfxSetRenderMode(AE_GFX_RM_COLOR);
	//AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);

	//Set color multiply
	AEGfxSetColorToMultiply(1, 1, 1, 1);

	//Set color to add
	AEGfxSetColorToAdd(mColor.r / 255.f, mColor.g / 255.f, mColor.b / 255.f, 0.f);

	//Set blend Mode
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);

	//Set transparency
	AEGfxSetTransparency(1);

	//Set texture
	AEGfxTextureSet(mTex, 0, 0);

	//Set transform
	//Get the trasnform from my owner transform comp
	AEMtx33 trasnf = mOwner->FindComp<TransformComp>()->GetMatrix();
	AEGfxSetTransform(trasnf.m);

	//call DrawMesh
	AEGfxMeshDraw(mesh, AE_GFX_MDM_TRIANGLES);

	AEGfxMeshFree(mesh);
	return false;
}

void SpriteComp::SetTexture(std::string s)
{
	if (mTex != nullptr)
		AEGfxTextureUnload(mTex);

	mTex = AEGfxTextureLoad(s.c_str());
}

