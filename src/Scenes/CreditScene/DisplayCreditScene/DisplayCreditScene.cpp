/*
** EPITECH PROJECT, 2024
** gui
** File description:
** DisplayCreditScene
*/

#include "DisplayCreditScene.hpp"

namespace Zappy {
    namespace GUI {
        namespace Scene {
            CreditScene::CreditScene(std::shared_ptr<Zappy::GUI::Raylib::Render> render, std::string text, int sceneNbr) : _sceneNbr(sceneNbr)
            {
                _render = render;
                _background = std::make_unique<Zappy::GUI::Component::Background2D>("assets/img/map_forest_scenery.png");
                _backButton = std::make_unique<Zappy::GUI::Component::Button>(std::make_pair(20, 20), std::make_pair(-20, -10), "<- BACK", 20, GREEN);
                _text = std::make_unique<Zappy::GUI::Component::Text>(std::make_pair(_render->getWidth() / 3 , _render->getHeight() / 3), text, 30, WHITE);
            }

            void CreditScene::destroy()
            {
                _text->destroy();
                _backButton->destroy();
                _background->destroy();
            }

            void CreditScene::start()
            {
            }

            void CreditScene::event()
            {
            }

            void CreditScene::draw3D()
            {
            }

            void CreditScene::draw2D()
            {
                _background->draw();
                _backButton->draw();
                _text->draw();
            }

            std::string CreditScene::nextScene()
            {
                if (_backButton->isClicked(_backButton->getText()))
                    return "credits";
                std::string txt = "credit" + std::to_string(_sceneNbr);
                return txt;
            }
        }
    }
}