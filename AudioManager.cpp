#include "AudioManager.h"

AudioManager* AudioManager::instance = NULL;

AudioManager* AudioManager::getInstance() {
    if (instance == NULL)
        instance = new AudioManager();

    return instance;
}

void AudioManager::Free() {
    delete instance;
}

AudioManager::AudioManager() {
    assetManager = AssetManager::getInstance();

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0) {
        printf("Mixer Initialization Error: %s\n", Mix_GetError());
    }
}

AudioManager::~AudioManager() {
    Mix_Quit();
}


void AudioManager::playMusic(std::string filename, int loops) {
    Mix_PlayMusic(assetManager->getMusic(filename), loops);
}

void AudioManager::pauseMusic() {
    if (Mix_PlayingMusic() != 0)
        Mix_PauseMusic();
}

void AudioManager::resumeMusic() {
    if (Mix_PausedMusic() != 0)
        Mix_ResumeMusic();
}

void AudioManager::playSFX(std::string filename, int loops, int channel) {
    Mix_PlayChannel(channel, assetManager->getSFX(filename), loops);
}
