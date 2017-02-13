#include "SoundEffect.h"

void AudioCallback(void *userdata, Uint8 * stream, int len);

SoundEffect::SoundEffect(char* Filename)
{
	SDL_LoadWAV_RW(SDL_RWFromFile(Filename, "rb"), 1, &Spec, &AudioBuffer, &AudioLength);
	Spec.callback = AudioCallback;
	Spec.userdata = this;
}

void SoundEffect::Play()
{
	// Reset auf Anfang
	CurrentAudioPosition = AudioBuffer;
	CurrentAudioLength = AudioLength;

	
	// Abspielen
	SDL_OpenAudio(&Spec, nullptr);
	SDL_PauseAudio(0);
}



void AudioCallback(void *userdata, Uint8 * stream, int len)
{
	SoundEffect* CurrentEffect = (SoundEffect*)userdata;

	if (CurrentEffect->CurrentAudioLength == 0)
		return;

	len = len > CurrentEffect->CurrentAudioLength ? CurrentEffect->CurrentAudioLength : len;

	SDL_MixAudio(stream, CurrentEffect->CurrentAudioPosition, len, SDL_MIX_MAXVOLUME);

	CurrentEffect->CurrentAudioPosition += len;
	CurrentEffect->CurrentAudioLength -= len;
}
