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
            AComponent::~AComponent()
            {
                destroy();
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



            std::pair<float, float> AComponent::getPos() const
            {
                return std::make_pair(_posX, _posY);
            }

            float AComponent::getPosX() const
            {
                return _posX;
            }

            float AComponent::getPosY() const
            {
                return _posY;
            }


            void AComponent::setPos(float x, float y)
            {
                _posX = x;
                _posY = y;
            }

            void AComponent::setPosX(float x)
            {
                _posX = x;
            }

            void AComponent::setPosY(float y)
            {
                _posY = y;
            }

            void AComponent::modPosX(float x)
            {
                _posX += x;
            }

            void AComponent::modPosY(float y)
            {
                _posY += y;
            }




            std::pair<float, float> AComponent::getSize() const
            {
                return std::make_pair(_sizeX, _sizeY);
            }

            float AComponent::getSizeX() const
            {
                return _sizeX;
            }

            float AComponent::getSizeY() const
            {
                return _sizeY;
            }


            void AComponent::setSize(float x, float y)
            {
                _sizeX = x;
                _sizeY = y;
            }

            void AComponent::setSizeX(float x)
            {
                _sizeX = x;
            }

            void AComponent::setSizeY(float y)
            {
                _sizeY = y;
            }

            void AComponent::modSizeX(float x)
            {
                _sizeX += x;
            }

            void AComponent::modSizeY(float y)
            {
                _sizeY += y;
            }



            Color AComponent::getColor() const
            {
                return _color;
            }

            void AComponent::setColor(Color color)
            {
                _color = color;
            }
        }
    }
}
