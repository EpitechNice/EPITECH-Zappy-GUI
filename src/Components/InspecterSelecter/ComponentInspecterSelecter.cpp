/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** InspecterSelecter
*/

#include "ComponentInspecterSelecter.hpp"


namespace Zappy {
    namespace GUI {
        namespace Component {
            InspecterSelecter::InspecterSelecter(std::pair<int, int> pos, int width, std::shared_ptr<Zappy::GUI::Ressources::Players> player)
            {
                setRef();
                _posX = pos.first;
                _posY = pos.second;
                _sizeX = width;
                _sizeY = 0;
                _player = player;
                _egg = nullptr;

                float refSize = 1.67;
                float size = refSize * _refWidth / 100;
                _team = std::make_unique<Circle>(std::make_pair<float, float>((float)(pos.first + size), (float)(pos.second + 10)), 10, Zappy::GUI::Ressources::Ref::get()->ressources->teamsColor[player->getTeam()]);
                _text = std::make_unique<Text>(std::make_pair<float, float>((float)(pos.first + size * 2), (float)(pos.second + 10)), std::string("Player #" + std::to_string(player->getId())), size, WHITE);
                _sizeY = _text->getSizeY() + 20;
                _background = std::make_unique<RoundedRectangle>(std::make_pair<float, float>((float)pos.first, (float)pos.second), std::make_pair<float, float>((float)_sizeX, (float)_sizeY), 0.2, (Color){55, 56, 40, 255});

                _team->setPosX((float)(pos.first + 20));
                _team->setPosY((float)(pos.second + _background->getSizeY() / 2));

                _text->setPosX((float)(pos.first + 40));
                _text->setPosY((float)(pos.second + 10));

                _refPosX = _posX / _refWidth * 100;
                _refPosY = _posY / _refHeight * 100;
                _refSizeX = _sizeX / _refWidth * 100;
            }

            InspecterSelecter::InspecterSelecter(std::pair<int, int> pos, int width, std::shared_ptr<Zappy::GUI::Ressources::Eggs> egg)
            {
                setRef();
                _posX = pos.first;
                _posY = pos.second;
                _sizeX = width;
                _sizeY = 0;
                _player = nullptr;
                _egg = egg;

                float refSize = 1.67;
                float size = refSize * _refWidth / 100;
                _team = std::make_unique<Circle>(std::make_pair<float, float>((float)(pos.first + size), (float)(pos.second + 10)), 10, Zappy::GUI::Ressources::Ref::get()->ressources->teamsColor[egg->getTeam()]);
                _text = std::make_unique<Text>(std::make_pair<float, float>((float)(pos.first + size * 2), (float)(pos.second + 10)), std::string("Egg #" + std::to_string(egg->getId())), size, WHITE);
                _sizeY = _text->getSizeY() + 20;
                _background = std::make_unique<RoundedRectangle>(std::make_pair<float, float>((float)pos.first, (float)pos.second), std::make_pair<float, float>((float)_sizeX, (float)_sizeY), 0.2, (Color){55, 56, 40, 255});

                _team->setPosX((float)(pos.first + 20));
                _team->setPosY((float)(pos.second + _background->getSizeY() / 2));

                _text->setPosX((float)(pos.first + 40));
                _text->setPosY((float)(pos.second + 10));

                _refPosX = _posX / _refWidth * 100;
                _refPosY = _posY / _refHeight * 100;
                _refSizeX = _sizeX / _refWidth * 100;
            }

            void InspecterSelecter::update()
            {
                _state = CheckCollisionPointRec(GetMousePosition(), (Rectangle){(float)_posX, (float)_posY, (float)_sizeX, (float)_sizeY}) ? IsMouseButtonPressed(MOUSE_LEFT_BUTTON) ? CLICKED : HOVER : NONE;
            }

            void InspecterSelecter::draw()
            {
                if (_state == HOVER || _state == CLICKED || _state == SELECTED)
                    _background->draw();
                _text->draw();
                _team->draw();
            }

            void InspecterSelecter::resize()
            {
                setRef();
                _posX = _refPosX * _refWidth / 100;
                _posY = _refPosY * _refHeight / 100;
                _sizeX = _refSizeX * _refWidth / 100;

                _background->resize();
                _background->setPosX((float)_posX);
                _background->setPosY((float)_posY);

                _text->resize();
                _text->setPosX((float)(_posX + 40));
                _text->setPosY((float)(_posY + 10));

                _team->resize();
                _team->setPosX((float)(_posX + 20));
                _team->setPosY((float)(_posY + _background->getSizeY() / 2));
                _sizeY = _background->getSizeY();
            }

            void InspecterSelecter::modPosX(float x)
            {
                _posX += x;
                _background->setPosX((float)_posX);
                _background->setPosY((float)_posY);

                _text->setPosX((float)(_posX + 40));
                _text->setPosY((float)(_posY + 10));

                _team->setPosX((float)(_posX + 20));
            }

            void InspecterSelecter::modPosY(float y)
            {
                _posY += y;
                _background->setPosX((float)_posX);
                _background->setPosY((float)_posY);

                _text->setPosX((float)(_posX + 40));
                _text->setPosY((float)(_posY + 10));

                _team->setPosY((float)(_posY + _background->getSizeY() / 2));
            }

            void InspecterSelecter::setPosX(float x)
            {
                _posX = x;
                _background->setPosX((float)_posX);
                _background->setPosY((float)_posY);

                _text->setPosX((float)(_posX + 40));
                _text->setPosY((float)(_posY + 10));

                _team->setPosX((float)(_posX + 20));
            }

            void InspecterSelecter::setPosY(float y)
            {
                _posY = y;
                _background->setPosX((float)_posX);
                _background->setPosY((float)_posY);

                _text->setPosX((float)(_posX + 40));
                _text->setPosY((float)(_posY + 10));

                _team->setPosY((float)(_posY + _background->getSizeY() / 2));
            }


            void InspecterSelecter::setSelected(bool selected)
            {
                if (selected) {
                    _state = SELECTED;
                    _background->setColor((Color){112, 108, 79, 255});
                } else {
                    _state = NONE;
                    _background->setColor((Color){55, 56, 40, 255});
                }
            }

            bool InspecterSelecter::isClicked() const
            {
                return _state == CLICKED;
            }

            bool InspecterSelecter::isPlayer() const
            {
                return _player != nullptr;
            }

            std::shared_ptr<Zappy::GUI::Ressources::Eggs> InspecterSelecter::getEgg() const
            {
                return _egg;
            }

            std::shared_ptr<Zappy::GUI::Ressources::Players> InspecterSelecter::getPlayer() const
            {
                return _player;
            }
        }
    }
}