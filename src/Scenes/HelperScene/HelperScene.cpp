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
                _render = render;
                _background = std::make_unique<Zappy::GUI::Component::Background2D>("assets/img/map_classic_scenery.png");
                _backButton = std::make_unique<Zappy::GUI::Component::Button>(std::make_pair(20, 20), std::make_pair(-20, -10), "<- BACK", 20, GREEN);
                _text = std::make_unique<Zappy::GUI::Component::Text>(std::make_pair(_render->getWidth() / 3 , _render->getHeight() / 3), text, 30, WHITE);
            }

            void HelperScene::destroy()
            {
                _text->destroy();
                _backButton->destroy();
                _background->destroy();
            }

            void HelperScene::start()
            {
            }

            void HelperScene::event()
            {
            }

            void HelperScene::draw3D()
            {
            }

            void HelperScene::draw2D()
            {
                _background->draw();
                _backButton->draw();
                _text->draw();
            }

            std::string HelperScene::nextScene()
            {
                if (_backButton->isClicked(_backButton->getText()))
                    return "menu";
                return "help";
            }
        }
    }
}