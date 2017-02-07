#pragma once
#include "SDLInclude.h"

class SoundEffect
{
public:
	SoundEffect(char* Filename);
	void Play();

public:

	SDL_AudioSpec Spec;
	Uint8* AudioBuffer;
	Uint32 AudioLength;


	Uint8* CurrentAudioPosition;
	Uint32 CurrentAudioLength;
};