/*
** EPITECH PROJECT, 2024
** gui
** File description:
** SoundManager
*/

#ifndef SOUNDMANAGER_HPP_
    #define SOUNDMANAGER_HPP_

    #include <raylib.h>
    #include <raymath.h>
    #include <memory>
    #include <iostream>
    #include <SFML/Audio.hpp>

namespace Zappy {
    namespace GUI {
        namespace Sfml {
            class SoundManager {
                public:
                    static SoundManager& getInstance();

                    void setMusique(const std::string& musiquePath);
                    void setEffetSonore(const std::string& effetSonorePath);
                    void setVolumeEffetSonore(float newVolume);
                    void setVolumeGeneralMusique(float newVolume);

                    void playButtonClickSound();
                    void playgeneralSound();
                private:
                    sf::SoundBuffer _clickSoundBuffer;
                    sf::SoundBuffer _generalSoundBuffer;
                    sf::Sound _clickSound;
                    sf::Sound _generalSound;
                    float _volumeClickSound;
                    float _volumeGeneralSound;
                    SoundManager();
            };
        }
    }
}

#endif /* !SOUNDMANAGER_HPP_ */
