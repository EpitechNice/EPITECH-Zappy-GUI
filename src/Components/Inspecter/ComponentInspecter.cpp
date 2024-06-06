/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** ComponentInspecter
*/

#include "ComponentInspecter.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            Inspecter::Inspecter()
                : _isDestroyed(false)
            {
                int height = GetScreenHeight();
                _screenWidth = GetScreenWidth();
                _width = _screenWidth / 3;
                int heightPart = height / 8;
                int heightPartMini = heightPart / 4;

                _rectTopBackground = std::make_unique<Rectangle>(std::make_pair(_screenWidth + _width, 0), std::make_pair(_width, heightPart), (Color){68, 69, 64, 255});
                _rectTop = std::make_unique<Rectangle>(std::make_pair(_screenWidth + _width, heightPart - heightPartMini), std::make_pair(_width, heightPartMini), (Color){112, 108, 79, 255});
                _rectMid = std::make_unique<Rectangle>(std::make_pair(_screenWidth + _width, 0), std::make_pair(_width, height), (Color){68, 69, 64, 255});
                _rectBot = std::make_unique<Rectangle>(std::make_pair(_screenWidth + _width, height - heightPart), std::make_pair(_width, heightPart), (Color){112, 108, 79, 255});
                _rectTopBackground->setStroke(1, BLACK);
                _rectMid->setStroke(3, BLACK);
                _rectBot->setStroke(1, BLACK);

                _openButton = std::make_unique<Button>(std::make_pair(0, 0), std::make_pair(-5, -40), "<", 30, SKYBLUE);
                _openButton->disableBubble();
                _buttonSize = _openButton->getSize();
                _openButton->setPos(std::make_pair(_screenWidth - 8 - _buttonSize.first, height / 2 - _buttonSize.second / 2));
                _open = false;
            }

            Inspecter::~Inspecter()
            {
                if (!_isDestroyed)
                    destroy();
            }


            void Inspecter::destroy()
            {
                _openButton->destroy();
            }


            void Inspecter::draw()
            {
                _rectMid->draw();
                _rectTopBackground->draw();
                _rectTop->draw();
                _rectBot->draw();
                _openButton->draw();
            }

            void Inspecter::update()
            {
                if (_openButton->isClicked())
                    (_open) ? _setInspecterClose() : _setInspecterOpen();
            }

            bool Inspecter::mouseIsOn() const
            {
                bool isOn = _openButton->isHover() || _openButton->isClicked();
                if (_open)
                    isOn = GetMouseX() < _width ? true : isOn;
                return isOn;
            }


            void Inspecter::_setInspecterOpen()
            {
                _rectTopBackground->setPosX(_screenWidth - _width);
                _rectTop->setPosX(_screenWidth - _width);
                _rectMid->setPosX(_screenWidth - _width);
                _rectBot->setPosX(_screenWidth - _width);
                _openButton->setPosX(_screenWidth - _width - 8 - _buttonSize.first);
                _openButton->setText(">");

                _open = true;
            }

            void Inspecter::_setInspecterClose()
            {
                _rectTopBackground->setPosX(_screenWidth);
                _rectTop->setPosX(_screenWidth);
                _rectMid->setPosX(_screenWidth);
                _rectBot->setPosX(_screenWidth);
                _openButton->setPosX(_screenWidth - 8 - _buttonSize.first);
                _openButton->setText("<");

                _open = false;
            }
        }
    }
}