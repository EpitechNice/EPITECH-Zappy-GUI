/*
** EPITECH PROJECT, 2024
** gui
** File description:
** HelperScene
*/

#include "HelperScene.hpp"

namespace Zappy {
    namespace GUI {
        namespace Scene {
            HelperScene::HelperScene(std::shared_ptr<Zappy::GUI::Raylib::Render> render, std::string text)
            {
                Zappy::GUI::I18n::I18nHelper* i18nHelper = Zappy::GUI::I18n::I18nHelper::getInstance();

                _render = render;
                _background = std::make_unique<Zappy::GUI::Component::Background2D>("assets/img/map_classic_scenery.png");
                _backButton = std::make_pair(std::make_unique<Zappy::GUI::Component::Button>(std::make_pair(20, 20), std::make_pair(-20, -10), i18nHelper->getTranslation("[menu.back_button]"), 20, GREEN), "[menu.back_button]");
                _text = std::make_pair(std::make_unique<Zappy::GUI::Component::Text>(std::make_pair(_render->getWidth() / 3 , _render->getHeight() / 3), i18nHelper->getTranslation(text), 30, WHITE), text);
                _lang = i18nHelper->getCurrentLocale();
            }

            void HelperScene::start()
            {}

            void HelperScene::destroy()
            {
                _text.first->destroy();
                _backButton.first->destroy();
                _background->destroy();
            }

            void HelperScene::update()
            {
                Zappy::GUI::I18n::I18nHelper* i18nHelper = Zappy::GUI::I18n::I18nHelper::getInstance();

                if (i18nHelper->getCurrentLocale() != _lang) {
                    _backButton.first->setText(i18nHelper->getTranslation(_backButton.second));
                    _text.first->setText(i18nHelper->getTranslation(_text.second));
                    _lang = i18nHelper->getCurrentLocale();
                }
            }

            void HelperScene::draw3D()
            {}

            void HelperScene::draw2D()
            {
                _background->draw();
                _backButton.first->draw();
                _text.first->draw();
            }

            std::string HelperScene::nextScene()
            {
                if (_backButton.first->isClicked(_backButton.second))
                    return "menu";
                return "help";
            }
        }
    }
}