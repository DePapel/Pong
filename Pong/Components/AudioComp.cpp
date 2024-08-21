#include "AudioComp.h"
#include "../ComponentManager/Manager.h"

#include "AEEngine.h"
#include "AEAudio.h"

AudioComp::AudioComp(GO* owner) : BaseComponent(owner), mGroup(), mAudio()
{
	Manager<AudioComp>::getPtr()->AddPtr(this);
	mGroup = AEAudioCreateGroup();
}

AudioComp::~AudioComp()
{
	Manager<AudioComp>::getPtr()->RemovePtr(this);

	AEAudioUnloadAudio(mAudio);
	AEAudioUnloadAudioGroup(mGroup);
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
		AEAudioPlay(mAudio, mGroup, volume, pitch, loops);
	}

	return false;
}

void AudioComp::SetAudio(std::string s)
{
	mAudio = AEAudioLoadMusic(s.c_str());
}


