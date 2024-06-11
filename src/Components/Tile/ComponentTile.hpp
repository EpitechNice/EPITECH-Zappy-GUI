/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** ComponentTile
*/

#ifndef COMPONENT_TILE_HPP_
    #define COMPONENT_TILE_HPP_

    #include <raylib.h>
    #include <memory>
    #include <iostream>

    #include "ComponentCube.hpp"
    #include "ColorManager.hpp"
    #include "ComponentModel3D.hpp"
    #include "ComponentRessources.hpp"
    #include "TileRessources.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            class Tile {
                public:
                    Tile(Vector3 pos, Vector3 size, Color color, std::shared_ptr<Ressources> ressourcesDrawer, std::shared_ptr<Zappy::GUI::Ressources::TileRessources> ressources);
                    ~Tile();

                    void destroy();

                    Vector3 getPos() const;
                    BoundingBox getTopBox() const;

                    void draw();

                    void highlight(bool highlight);
                    void select(bool select);

                protected:
                private:
                    Vector3 _pos;
                    Vector3 _size;
                    Color _color;
                    std::shared_ptr<Ressources> _ressourcesDrawer;
                    std::shared_ptr<Zappy::GUI::Ressources::TileRessources> _ressources;
                    bool _highlight;
                    bool _select;
                    bool _isDestroyed;
                    Vector3 _grassPos;
                    Vector3 _grassSize;
                    Vector3 _dirtPos;
                    Vector3 _dirtSize;

                    std::unique_ptr<Cube> _grass;
                    std::unique_ptr<Cube> _dirt;
                    std::unique_ptr<Cube> _wire;
                    float _selectEffect;
            };
        }
    }
}

#endif /* !COMPONENT_TILE_HPP_ */
