/*
** EPITECH PROJECT, 2024
** gui
** File description:
** SoundManager
*/

#include "SoundManager.hpp"

namespace Zappy {
    namespace GUI {
        namespace Sfml {
            SoundManager::SoundManager()
            {
                if (!_clickSoundBuffer.loadFromFile("assets/Sounds/effetSonoreButton1.mp3"))
                    std::cerr << "INFO: Erreur lors du chargement du fichier audio du clic du bouton." << std::endl;
                if (!_generalSoundBuffer.loadFromFile("assets/Sounds/ClashRoyaleSoundtrack1.wav"))
                    std::cerr << "INFO: Erreur lors du chargement du fichier audio de la musique principale." << std::endl;
                _clickSound.setBuffer(_clickSoundBuffer);
                _generalSound.setBuffer(_generalSoundBuffer);
                _volumeClickSound = 50.0;
                _volumeGeneralSound = 50.0;
                _generalSound.setVolume(_volumeGeneralSound);
                _clickSound.setVolume(_volumeClickSound);
            }

            SoundManager& SoundManager::getInstance()
            {
                static SoundManager instance;
                return instance;
            }

            void SoundManager::playButtonClickSound()
            {
                _clickSound.play();
            }

            void SoundManager::playgeneralSound()
            {
                _generalSound.play();
            }

            void SoundManager::setVolumeEffetSonore(float newVolume){
                _volumeClickSound = newVolume;
                _generalSound.setVolume(_volumeGeneralSound);
            }

            void SoundManager::setVolumeGeneralMusique(float newVolume){
                _volumeGeneralSound = newVolume;
                _generalSound.setVolume(_volumeGeneralSound);
            }

            void SoundManager::setMusique(const std::string& musiquePath)
            {
                if (!_generalSoundBuffer.loadFromFile(musiquePath))
                    std::cerr << "INFO: Erreur lors du chargement du fichier audio de la musique principale." << std::endl;
                _generalSound.setBuffer(_generalSoundBuffer);
                _generalSound.setVolume(_volumeGeneralSound);
            }

            void SoundManager::setEffetSonore(const std::string& effetSonorePath)
            {
                if (!_clickSoundBuffer.loadFromFile(effetSonorePath))
                    std::cerr << "INFO: Erreur lors du chargement du fichier audio du clic du bouton." << std::endl;
                _clickSound.setBuffer(_clickSoundBuffer);
                _clickSound.setVolume(_volumeClickSound);
            }
        }
    }
}