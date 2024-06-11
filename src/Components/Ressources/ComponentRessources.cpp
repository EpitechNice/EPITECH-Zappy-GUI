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
                _size = size;
                _isDestroyed = false;

                float tileXPart = size.x / 8;
                float tileYPart = size.y / 4;
                float scale = 0.2;


                _pos = {0, 0, 0};
                _refPosFood         = {tileXPart * 3, _pos.y + size.y / 2, tileYPart * 2};
                _refPosEgg          = {tileXPart * 5, _pos.y + size.y / 2, tileYPart * 2};
                _refPosLinemate     = {tileXPart * 2, _pos.y + size.y / 2, tileYPart * 1};
                _refPosDeraumere    = {tileXPart * 6, _pos.y + size.y / 2, tileYPart * 1};
                _refPosSibur        = {tileXPart * 7, _pos.y + size.y / 2, tileYPart * 2};
                _refPosMendiane     = {tileXPart * 6, _pos.y + size.y / 2, tileYPart * 3};
                _refPosPhiras       = {tileXPart * 2, _pos.y + size.y / 2, tileYPart * 3};
                _refPosThystame     = {tileXPart * 1, _pos.y + size.y / 2, tileYPart * 2};
                _refPosZappy        = {tileXPart * 4, _pos.y + size.y / 2, tileYPart * 1};

                _food = std::make_unique<Model3D>("Food/scene", _refPosFood, 1, (Vector3){1, 0, 0}, -20);
                _food->setOnPosY(_pos.y + size.y / 2 - 0.2);
                _egg = std::make_unique<Model3D>("Egg/scene", _refPosEgg, 0.3);
                _egg->setOnPosY(_pos.y + size.y / 2);
                _linemate = std::make_unique<Model3D>("Rocks/rock_1/rock", _refPosLinemate, scale);
                _deraumere = std::make_unique<Model3D>("Rocks/rock_2/rock", _refPosDeraumere, scale);
                _sibur = std::make_unique<Model3D>("Rocks/rock_3/rock", _refPosSibur, scale);
                _mendiane = std::make_unique<Model3D>("Rocks/rock_4/rock", _refPosMendiane, scale);
                _phiras = std::make_unique<Model3D>("Rocks/rock_5/rock", _refPosPhiras, scale);
                _thystame = std::make_unique<Model3D>("Rocks/rock_6/rock", _refPosThystame, scale);
                _zappy = std::make_unique<Model3D>("Zappy/scene", _refPosZappy, 1, (Vector3){0, 1, 0}, 90);
                _zappy->setOnPosY(_pos.y + size.y / 2);
            }

            Ressources::~Ressources()
            {
                destroy();
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


            void Ressources::setPos(Vector3 pos)
            {
                _pos = pos;
                _pos.x -= _size.x / 2;
                _pos.z -= _size.z / 2;

                _food->setPosX(_refPosFood.x + _pos.x);
                _food->setPosY(_refPosFood.y + _pos.y);
                _food->setPosZ(_refPosFood.z + _pos.z);
                _food->setOnPosY(_pos.y + _size.y / 2 - 0.2);

                _egg->setPosX(_refPosEgg.x + _pos.x);
                _egg->setPosY(_refPosEgg.y + _pos.y);
                _egg->setPosZ(_refPosEgg.z + _pos.z);
                _egg->setOnPosY(_pos.y + _size.y / 2);

                _linemate->setPosX(_refPosLinemate.x + _pos.x);
                _linemate->setPosY(_refPosLinemate.y + _pos.y);
                _linemate->setPosZ(_refPosLinemate.z + _pos.z);

                _deraumere->setPosX(_refPosDeraumere.x + _pos.x);
                _deraumere->setPosY(_refPosDeraumere.y + _pos.y);
                _deraumere->setPosZ(_refPosDeraumere.z + _pos.z);

                _sibur->setPosX(_refPosSibur.x + _pos.x);
                _sibur->setPosY(_refPosSibur.y + _pos.y);
                _sibur->setPosZ(_refPosSibur.z + _pos.z);

                _mendiane->setPosX(_refPosMendiane.x + _pos.x);
                _mendiane->setPosY(_refPosMendiane.y + _pos.y);
                _mendiane->setPosZ(_refPosMendiane.z + _pos.z);

                _phiras->setPosX(_refPosPhiras.x + _pos.x);
                _phiras->setPosY(_refPosPhiras.y + _pos.y);
                _phiras->setPosZ(_refPosPhiras.z + _pos.z);

                _thystame->setPosX(_refPosThystame.x + _pos.x);
                _thystame->setPosY(_refPosThystame.y + _pos.y);
                _thystame->setPosZ(_refPosThystame.z + _pos.z);

                _zappy->setPosX(_refPosZappy.x + _pos.x);
                _zappy->setPosY(_refPosZappy.y + _pos.y);
                _zappy->setPosZ(_refPosZappy.z + _pos.z);
                _zappy->setOnPosY(_pos.y + _size.y / 2);
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