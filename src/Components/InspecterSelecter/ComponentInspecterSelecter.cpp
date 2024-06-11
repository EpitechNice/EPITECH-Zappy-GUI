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
                _pos = pos;
                _player = player;
                _size = std::make_pair(width, 0);
                _team = std::make_unique<Circle>(std::make_pair<float, float>((float)(pos.first + 20), (float)(pos.second + 10)), 10, player->getTeam());
                _text = std::make_unique<Text>(std::make_pair<float, float>((float)(pos.first + 40), (float)(pos.second + 10)), std::string("Player #" + std::to_string(player->getId())), 20, WHITE);
                _size.second = _text->getSize().second + 20;
                _background = std::make_unique<RoundedRectangle>(std::make_pair<float, float>((float)pos.first, (float)pos.second), std::make_pair<float, float>((float)_size.first, (float)_size.second), 0.2, (Color){55, 56, 40, 255});

                _team->setPosX((float)(pos.first + 20));
                _team->setPosY((float)(pos.second + _background->getSize().second / 2));

                _text->setPos(std::make_pair<float, float>((float)(pos.first + 40), (float)(pos.second + 10)));
            }

            InspecterSelecter::~InspecterSelecter()
            {
                destroy();
            }

            void InspecterSelecter::destroy()
            {
                if (_isDestroyed)
                    return;
                _text->destroy();
                _isDestroyed = true;
            }

            void InspecterSelecter::update()
            {
                _state = CheckCollisionPointRec(GetMousePosition(), (Rectangle){(float)_pos.first, (float)_pos.second, (float)_size.first, (float)_size.second}) ? IsMouseButtonPressed(MOUSE_LEFT_BUTTON) ? CLICKED : HOVER : NONE;
            }

            void InspecterSelecter::draw()
            {
                if (_state == HOVER || _state == CLICKED || _state == SELECTED)
                    _background->draw();
                _text->draw();
                _team->draw();
            }

            void InspecterSelecter::modPosX(int x)
            {
                _pos.first += x;
                _background->setPosition(std::make_pair<float, float>((float)_pos.first, (float)_pos.second));
                _text->setPos(std::make_pair<float, float>((float)(_pos.first + 40), (float)(_pos.second + 10)));
                _team->setPosX((float)(_pos.first + 20));
            }

            void InspecterSelecter::modPosY(int y)
            {
                _pos.second += y;
                _background->setPosition(std::make_pair<float, float>((float)_pos.first, (float)_pos.second));
                _text->setPos(std::make_pair<float, float>((float)(_pos.first + 40), (float)(_pos.second + 10)));
                _team->setPosY((float)(_pos.second + _background->getSize().second / 2));
            }

            void InspecterSelecter::setPosX(int x)
            {
                _pos.first = x;
                _background->setPosition(std::make_pair<float, float>((float)_pos.first, (float)_pos.second));
                _text->setPos(std::make_pair<float, float>((float)(_pos.first + 40), (float)(_pos.second + 10)));
                _team->setPosX((float)(_pos.first + 20));
            }

            void InspecterSelecter::setPosY(int y)
            {
                _pos.second = y;
                _background->setPosition(std::make_pair<float, float>((float)_pos.first, (float)_pos.second));
                _text->setPos(std::make_pair<float, float>((float)(_pos.first + 40), (float)(_pos.second + 10)));
                _team->setPosY((float)(_pos.second + _background->getSize().second / 2));
            }

            std::pair<int, int> InspecterSelecter::getSize() const
            {
                return _size;
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

            std::shared_ptr<Zappy::GUI::Ressources::Players> InspecterSelecter::getPlayer() const
            {
                return _player;
            }
        }
    }
}