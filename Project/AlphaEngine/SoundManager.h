#ifndef AUDIO_H
#define AUDIO_H

#include <al.h>
#include <alc.h>

class SoundManager {

protected:
	char *m_audioPath = "";

	ALCcontext *m_context;
	ALCdevice *m_device;

public:
	SoundManager();
	~SoundManager();

	void Init();

	void LoadAudio(char *audioPath);
	void PlayAudio();

};

#endif