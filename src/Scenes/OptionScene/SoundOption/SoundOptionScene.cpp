/*
** EPITECH PROJECT, 2024
** gui
** File description:
** SoundOption
*/

#include "SoundOptionScene.hpp"

namespace Zappy {
    namespace GUI {
        Scene::SoundOption::SoundOption(std::shared_ptr<Raylib::Render> render)
        {
            Zappy::GUI::I18n::I18nHelper* i18nHelper = Zappy::GUI::I18n::I18nHelper::getInstance();

            _lang = i18nHelper->getCurrentLocale();
            _background = std::make_unique<Component::Background2D>("map_forest_scenery.png");
            _backButton = std::make_pair(std::make_unique<Component::Button>(std::make_pair(20, 20), std::make_pair(-20, -10), i18nHelper->getTranslation("[menu.back_button]"), 20, GREEN), "[menu.back_button]");

            float partX = render->getWidth() / 7;
            float partY = render->getHeight() / 4;
            _music = std::make_unique<Component::VolumeSection>(std::make_pair(partX * 1, partY * 1), std::make_pair(partX * 2, partY * 2), i18nHelper->getTranslation("[menu.settings.sound.music]"), &Zappy::GUI::Sfml::SoundManager::setVolumeGeneralMusique);
            _sound = std::make_unique<Component::VolumeSection>(std::make_pair(partX * 4, partY * 1), std::make_pair(partX * 2, partY * 2), i18nHelper->getTranslation("[menu.settings.sound.sound]"), &Zappy::GUI::Sfml::SoundManager::setVolumeEffetSonore);
        }

        void Scene::SoundOption::destroy()
        {
            _background->destroy();
        }

        void Scene::SoundOption::update()
        {
            _music->update();
            _sound->update();
            Zappy::GUI::I18n::I18nHelper* i18nHelper = Zappy::GUI::I18n::I18nHelper::getInstance();
            if (i18nHelper->getCurrentLocale() != _lang) {
                _backButton.first->setText(i18nHelper->getTranslation(_backButton.second));
                _music->setText(i18nHelper->getTranslation("[menu.settings.sound.music]"));
                _sound->setText(i18nHelper->getTranslation("[menu.settings.sound.sound]"));
                _lang = i18nHelper->getCurrentLocale();
            }
        }

        void Scene::SoundOption::draw2D()
        {
            _background->draw();
            _backButton.first->draw();
            _music->draw();
            _sound->draw();
        }

        std::string Scene::SoundOption::nextScene()
        {
            if (_backButton.first->isClicked(_backButton.second))
                return "option";
            return "soundSetting";
        }

        void Scene::SoundOption::resize()
        {
            _background->resize();
            _backButton.first->resize();
            _music->resize();
            _sound->resize();
        }
    }
}