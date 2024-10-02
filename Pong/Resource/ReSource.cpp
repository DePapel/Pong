#include "ReSource.h"
#include "AEEngine.h"

void Resource::IncCnt()
{
	++cnt;
}

void Resource::DecCnt()
{
	--cnt;
}

void* Resource::GetData()
{
	return data;
}

int Resource::GetCnt()
{
	return cnt;
}

void MusicResource::LoadData(std::string filename)
{
	AEAudio* pA = new AEAudio;
	*pA = AEAudioLoadMusic(filename.c_str());

	data = pA;
}

void MusicResource::UnloadData()
{
	if (data == nullptr)
		return;

	AEAudioUnloadAudio(*static_cast<AEAudio*>(data));
	delete static_cast<AEAudio*>(data);
	data = nullptr;
}

MusicResource::~MusicResource()
{
	UnloadData();
}

void TextureResource::LoadData(std::string filename)
{
	data = AEGfxTextureLoad(filename.c_str());
}

void TextureResource::UnloadData()
{
	if (data == nullptr)
		return;

	AEGfxTextureUnload(static_cast<AEGfxTexture*>(data));
	delete static_cast<AEGfxTexture*>(data);
	data = nullptr;
}

TextureResource::~TextureResource()
{
	UnloadData();
}
