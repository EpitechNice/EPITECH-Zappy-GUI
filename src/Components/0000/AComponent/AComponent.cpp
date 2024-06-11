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
            AComponent::AComponent(std::pair<float, float> pos, std::pair<float, float> size)
            {
                _isDestroyed = false;
                _posX = pos.first;
                _posY = pos.second;
                _sizeX = size.first;
                _sizeY = size.second;
            }

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


            void AComponent::setPos(std::pair<float, float> pos)
            {
                _posX = pos.first;
                _posY = pos.second;
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


            void AComponent::setSize(std::pair<float, float> size)
            {
                _sizeX = size.first;
                _sizeY = size.second;
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
        }
    }
}