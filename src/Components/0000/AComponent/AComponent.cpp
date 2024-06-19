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

            void AComponent::draw()
            {
            }

            void AComponent::resize()
            {
            }


            void AComponent::setRef()
            {
                _refWidth = GetScreenWidth();
                _refHeight = GetScreenHeight();
            }

            float AComponent::getPosX() const
            {
                return _posX;
            }

            float AComponent::getPosY() const
            {
                return _posY;
            }

            float AComponent::getPosZ() const
            {
                return _posZ;
            }

            void AComponent::setPosX(float x)
            {
                _posX = x;
                _refPosX = _posX * 100 / _refWidth;
            }

            void AComponent::setPosY(float y)
            {
                _posY = y;
                _refPosY = _posY * 100 / _refHeight;
            }

            void AComponent::setPosZ(float z)
            {
                _posZ = z;
            }

            void AComponent::modPosX(float x)
            {
                _posX += x;
            }

            void AComponent::modPosY(float y)
            {
                _posY += y;
            }

            void AComponent::modPosZ(float z)
            {
                _posZ += z;
            }



            float AComponent::getSizeX() const
            {
                return _sizeX;
            }

            float AComponent::getSizeY() const
            {
                return _sizeY;
            }

            float AComponent::getSizeZ() const
            {
                return _sizeZ;
            }

            void AComponent::setSizeX(float x)
            {
                _sizeX = x;
                _refSizeX = _sizeX * 100 / _refWidth;
            }

            void AComponent::setSizeY(float y)
            {
                _sizeY = y;
                _refSizeY = _sizeY * 100 / _refHeight;
            }

            void AComponent::setSizeZ(float z)
            {
                _sizeZ = z;
            }

            void AComponent::modSizeX(float x)
            {
                _sizeX += x;
            }

            void AComponent::modSizeY(float y)
            {
                _sizeY += y;
            }

            void AComponent::modSizeZ(float z)
            {
                _sizeZ += z;
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
