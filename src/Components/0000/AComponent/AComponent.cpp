/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** AComponent
*/

#include "AComponent.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            AComponent::AComponent(std::pair<int, int> pos, std::pair<int, int> size)
            {
                _pos = pos;
                _size = size;
            }

            AComponent::~AComponent()
            {
                destroy();
            }


            std::pair<int, int> AComponent::getPos() const
            {
                return _pos;
            }

            std::pair<int, int> AComponent::getSize() const
            {
                return _size;
            }


            void AComponent::setPos(std::pair<int, int> pos)
            {
                _pos = pos;
            }

            void AComponent::setPosX(int x)
            {
                _pos.first = x;
            }

            void AComponent::setPosY(int y)
            {
                _pos.second = y;
            }

            void AComponent::modPosX(int x)
            {
                _pos.first += x;
            }

            void AComponent::modPosY(int y)
            {
                _pos.second += y;
            }


            void AComponent::destroy()
            {
                if (_isDestroyed) return;
                _isDestroyed = true;
            }

            void AComponent::update()
            {
            }

            void AComponent::draw()
            {
            }
        }
    }
}