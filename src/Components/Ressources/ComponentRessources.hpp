/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** ComponentRessources
*/

#ifndef COMPONENT_RESSOURCES_HPP_
    #define COMPONENT_RESSOURCES_HPP_

    #include <raylib.h>
    #include <memory>

    #include "ComponentModel3D.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            class Ressources {
                public:
                    Ressources(Vector3 size);
                    ~Ressources();

                    void destroy();

                    void drawFood();
                    void drawEgg();
                    void drawLinemate();
                    void drawDeraumere();
                    void drawSibur();
                    void drawMendiane();
                    void drawPhiras();
                    void drawThystame();
                    void drawZappy();

                    void setPos(Vector3 pos);
                protected:
                private:
                    bool _isDestroyed;

                    Vector3 _size;
                    Vector3 _pos;

                    Vector3 _refPosFood;
                    Vector3 _refPosEgg;
                    Vector3 _refPosLinemate;
                    Vector3 _refPosDeraumere;
                    Vector3 _refPosSibur;
                    Vector3 _refPosMendiane;
                    Vector3 _refPosPhiras;
                    Vector3 _refPosThystame;
                    Vector3 _refPosZappy;

                    std::unique_ptr<Model3D> _food;
                    std::unique_ptr<Model3D> _egg;
                    std::unique_ptr<Model3D> _linemate;
                    std::unique_ptr<Model3D> _deraumere;
                    std::unique_ptr<Model3D> _sibur;
                    std::unique_ptr<Model3D> _mendiane;
                    std::unique_ptr<Model3D> _phiras;
                    std::unique_ptr<Model3D> _thystame;
                    std::unique_ptr<Model3D> _zappy;
            };
        }
    }
}

#endif /* !COMPONENT_RESSOURCES_HPP_ */
