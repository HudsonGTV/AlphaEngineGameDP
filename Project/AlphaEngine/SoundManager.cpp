#include "AEEngine.h"
#include "SoundManager.h"

SoundManager::SoundManager() {

	m_audioPath = "";

	m_device = 0;
	m_context = 0;

}

SoundManager::~SoundManager() {

	m_context = alcGetCurrentContext();
	m_device = alcGetContextsDevice(m_context);

	alcMakeContextCurrent(NULL);
	alcDestroyContext(m_context);

	if(m_device) {
		alcCloseDevice(m_device);
	}

}

void SoundManager::Init() {

	m_device = alcOpenDevice(NULL);

	if(m_device == NULL) {
		OutputDebugStringA("ERROR: Could Not Load Audio Device!");
	}

	// CREATE CONTEXT
	m_context = alcCreateContext(m_device, NULL);

	// SET ACTIVE CONTEXT
	alcMakeContextCurrent(m_context);

	alGetError();

}

void SoundManager::LoadAudio(char *audioPath) {

	/*char *alBuffer;
	long int alBufferLen;

	unsigned int alSource;
	unsigned int alSampleSet;

	ALenum alFormatBuffer;
	ALsizei alFreqBuffer;
	ALboolean alLoop;*/

	// TODO: Add alut to project
	///alBuffer = locateAudioBuffer(audioPath);

	/*alGenSources(1, &alSource);

	// CREATE BUFFER
	alGenBuffers(1, &alSampleSet);

	// PUT THE DATA INTO OUR SAMPLESET BUFFER
	alBufferData(alSampleSet, alFormatBuffer, alBuffer, alBufferLen, alFreqBuffer);

	// ASSIGN THE BUFFER TO THIS SOURCE
	alSourcei(alSource, AL_BUFFER, alSampleSet);*/

	// RELEASE THE DATA
	///alutUnloadWAV(alFormatBuffer, alBuffer, alBufferLen, alFreqBuffer);

}

void SoundManager::PlayAudio() {

}
