#pragma once
#include "../ComponentManager/BaseComp.h"
#include "AEAudio.h"
#include <string>

class AudioComp : public BaseComponent
{
	AEAudioGroup mGroup;
	AEAudio mAudio;

	float volume = 0.25f;
	float pitch = 1;

	bool loop = true;
	bool playing = false;

public:
	AudioComp(GO* owner);
	~AudioComp();
	bool Update() override;

	void SetAudio(std::string s);

};