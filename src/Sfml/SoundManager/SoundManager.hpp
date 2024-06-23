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

    #include "Path.hpp"

namespace Zappy {
    namespace GUI {
        namespace Sfml {
            /**
             * @brief A class to manage sounds
             */
            class SoundManager {
                public:
                    /**
                     * @brief Get the instance of the SoundManager
                     *
                     * @return `SoundManager&` The instance of the SoundManager
                     */
                    static SoundManager& getInstance();

                    /**
                     * @brief Set the music of the SoundManager
                     *
                     * @param musiquePath The path to the music file
                     */
                    void setMusique(const std::string& musiquePath);

                    /**
                     * @brief Set the sound effect of the SoundManager
                     *
                     * @param effetSonorePath The path to the sound effect file
                     */
                    void setEffetSonore(const std::string& effetSonorePath);

                    /**
                     * @brief Set the volume of the sound effect
                     *
                     * @param newVolume The new volume
                     */
                    void setVolumeEffetSonore(float newVolume);

                    /**
                     * @brief Set the volume of the music
                     *
                     * @param newVolume The new volume
                     */
                    void setVolumeGeneralMusique(float newVolume);

                    /**
                     * @brief Play the sound of the clicked button
                     */
                    void playButtonClickSound();

                    /**
                     * @brief Play the general sound effect
                     */
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
