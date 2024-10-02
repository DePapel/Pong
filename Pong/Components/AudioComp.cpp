#include "AudioComp.h"
#include "../ComponentManager/Manager.h"

#include "AEEngine.h"
#include "AEAudio.h"
#include "../Resource/ResourceManager.h"



AudioComp::AudioComp(GO* owner) : BaseComponent(owner), mGroup(), mAudio()
{
	Manager<AudioComp>::getPtr()->AddPtr(this);
	mGroup = AEAudioCreateGroup();
}

AudioComp::~AudioComp()
{
	Manager<AudioComp>::getPtr()->RemovePtr(this);
	ResourceManager* ptr = ResourceManager::GetPtr();
	ptr->UnloadFn(name);

	AEAudioUnloadAudioGroup(mGroup);
}

void AudioComp::SetAudio(const std::string& s)
{
	name = s;
	ResourceManager* ptr = ResourceManager::GetPtr();
	MusicResource* pA = ptr->GetFn<MusicResource>(s);

	mAudio = static_cast<AEAudio*>(pA->GetData());
}

void AudioComp::SetMusicLoop(int n)
{
	musicLoop = n;
}

bool AudioComp::Update()
{
	if (BaseComponent::Update() == false)
		return false;

	int loops = 0;
	if (loop)
		loops = -1;

	if (!playing)
	{
		playing = true;
		
		if (musicLoop == -1)
			loops = -1;
		else if (musicLoop == 0)
			loops = 0;
		AEAudioPlay(*mAudio, mGroup, volume, pitch, loops);
	}

	return false;
}