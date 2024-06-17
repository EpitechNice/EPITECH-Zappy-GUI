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
                _background = std::make_unique<Zappy::GUI::Component::Background2D>("assets/img/map_war_scenery.png");
                _backButton = std::make_pair(std::make_unique<Zappy::GUI::Component::Button>(std::make_pair(20, 20), std::make_pair(-20, -10), i18nHelper->getTranslation("[menu.back_button]"), 20, GREEN), "[menu.back_button]");
                _text = std::make_pair(std::make_unique<Zappy::GUI::Component::TextBox>(std::make_pair( 100, 100), _render->getWidth() - 200, i18nHelper->getTranslation(text), 20, WHITE), text);
                _lang = i18nHelper->getCurrentLocale();
            }

            void HelperScene::destroy()
            {
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

            void HelperScene::resize()
            {
                _background->resize();
                _backButton.first->resize();
                _text.first->resize();
            }
        }
    }
}