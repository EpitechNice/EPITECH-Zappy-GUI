/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** ComponentRessources
*/

#include "ComponentRessources.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            Ressources::Ressources(Vector3 size)
            {
                _sizeX = size.x;
                _sizeY = size.y;
                _sizeZ = size.z;
                _posX = 0;
                _posY = 0;
                _posZ = 0;

                float tileXPart = size.x / 8;
                float tileYPart = size.y / 4;
                float scale = 0.2;


                _refPosFood         = {tileXPart * 3, _posY + size.y / 2, tileYPart * 2};
                _refPosEgg          = {tileXPart * 5, _posY + size.y / 2, tileYPart * 2};
                _refPosLinemate     = {tileXPart * 2, _posY + size.y / 2, tileYPart * 1};
                _refPosDeraumere    = {tileXPart * 6, _posY + size.y / 2, tileYPart * 1};
                _refPosSibur        = {tileXPart * 7, _posY + size.y / 2, tileYPart * 2};
                _refPosMendiane     = {tileXPart * 6, _posY + size.y / 2, tileYPart * 3};
                _refPosPhiras       = {tileXPart * 2, _posY + size.y / 2, tileYPart * 3};
                _refPosThystame     = {tileXPart * 1, _posY + size.y / 2, tileYPart * 2};
                _refPosZappy        = {tileXPart * 4, _posY + size.y / 2, tileYPart * 1};

                _food = std::make_unique<Model3D>("Food/scene", _refPosFood, 1, (Vector3){1, 0, 0}, -20);
                _food->setOnPosY(_posY + size.y / 2 - 0.2);
                _egg = std::make_unique<Model3D>("Egg/scene", _refPosEgg, 0.3);
                _egg->setOnPosY(_posY + size.y / 2);
                _linemate = std::make_unique<Model3D>("Rocks/rock_1/rock", _refPosLinemate, scale);
                _deraumere = std::make_unique<Model3D>("Rocks/rock_2/rock", _refPosDeraumere, scale);
                _sibur = std::make_unique<Model3D>("Rocks/rock_3/rock", _refPosSibur, scale);
                _mendiane = std::make_unique<Model3D>("Rocks/rock_4/rock", _refPosMendiane, scale);
                _phiras = std::make_unique<Model3D>("Rocks/rock_5/rock", _refPosPhiras, scale);
                _thystame = std::make_unique<Model3D>("Rocks/rock_6/rock", _refPosThystame, scale);
                _zappy = std::make_unique<Model3D>("Zappy/scene", _refPosZappy, 1, (Vector3){0, 1, 0}, 90);
                _zappy->setOnPosY(_posY + size.y / 2);
            }

            void Ressources::destroy()
            {
                if (_isDestroyed)
                    return;
                _food->destroy();
                _egg->destroy();
                _linemate->destroy();
                _deraumere->destroy();
                _sibur->destroy();
                _mendiane->destroy();
                _phiras->destroy();
                _thystame->destroy();
                _zappy->destroy();
                _isDestroyed = true;
            }


            void Ressources::setPosX(float x)
            {
                _posX = x;
                _posX -= _sizeX / 2;
                _food->setPosX(_refPosFood.x + _posX);
                _egg->setPosX(_refPosEgg.x + _posX);
                _linemate->setPosX(_refPosLinemate.x + _posX);
                _deraumere->setPosX(_refPosDeraumere.x + _posX);
                _sibur->setPosX(_refPosSibur.x + _posX);
                _mendiane->setPosX(_refPosMendiane.x + _posX);
                _phiras->setPosX(_refPosPhiras.x + _posX);
                _thystame->setPosX(_refPosThystame.x + _posX);
                _zappy->setPosX(_refPosZappy.x + _posX);
            }

            void Ressources::setPosY(float y)
            {
                _posY = y;
                _food->setPosY(_refPosFood.y + _posY);
                _food->setOnPosY(_posY + _sizeY / 2 - 0.2);
                _egg->setPosY(_refPosEgg.y + _posY);
                _egg->setOnPosY(_posY + _sizeY / 2);
                _linemate->setPosY(_refPosLinemate.y + _posY);
                _deraumere->setPosY(_refPosDeraumere.y + _posY);
                _sibur->setPosY(_refPosSibur.y + _posY);
                _mendiane->setPosY(_refPosMendiane.y + _posY);
                _phiras->setPosY(_refPosPhiras.y + _posY);
                _thystame->setPosY(_refPosThystame.y + _posY);
                _zappy->setPosY(_refPosZappy.y + _posY);
                _zappy->setOnPosY(_posY + _sizeY / 2);
            }

            void Ressources::setPosZ(float z)
            {
                _posZ = z;
                _posZ -= _sizeZ / 2;
                _food->setPosZ(_refPosFood.z + _posZ);
                _egg->setPosZ(_refPosEgg.z + _posZ);
                _linemate->setPosZ(_refPosLinemate.z + _posZ);
                _deraumere->setPosZ(_refPosDeraumere.z + _posZ);
                _sibur->setPosZ(_refPosSibur.z + _posZ);
                _mendiane->setPosZ(_refPosMendiane.z + _posZ);
                _phiras->setPosZ(_refPosPhiras.z + _posZ);
                _thystame->setPosZ(_refPosThystame.z + _posZ);
                _zappy->setPosZ(_refPosZappy.z + _posZ);
            }


            void Ressources::drawFood()
            {
                _food->draw();
            }

            void Ressources::drawEgg()
            {
                _egg->draw();
            }

            void Ressources::drawLinemate()
            {
                _linemate->draw();
            }

            void Ressources::drawDeraumere()
            {
                _deraumere->draw();
            }

            void Ressources::drawSibur()
            {
                _sibur->draw();
            }

            void Ressources::drawMendiane()
            {
                _mendiane->draw();
            }

            void Ressources::drawPhiras()
            {
                _phiras->draw();
            }

            void Ressources::drawThystame()
            {
                _thystame->draw();
            }

            void Ressources::drawZappy()
            {
                _zappy->draw();
            }
        }
    }
}