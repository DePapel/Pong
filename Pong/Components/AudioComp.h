#pragma once
#include "../ComponentManager/BaseComp.h"
#include "AEAudio.h"
#include <string>

class AudioComp : public BaseComponent
{
	std::string name;
	AEAudioGroup mGroup;
	AEAudio* mAudio;

	float volume = 0.25f;
	float pitch = 1;

	bool loop = true;
	bool playing = false;
	int musicLoop;

public:
	AudioComp(GO* owner);
	~AudioComp();
	void SetAudio(const std::string& s);
	void SetMusicLoop(int n);

	bool Update() override;
};