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

    #include "ComponentCubic.hpp"
    #include "ColorManager.hpp"
    #include "ComponentModel3D.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            class Tile {
                public:
                    Tile(Vector3 pos, Vector3 size, Color color);
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
                    bool _highlight;
                    bool _select;
                    bool _isDestroyed;
                    Vector3 _grassPos;
                    Vector3 _grassSize;
                    Vector3 _dirtPos;
                    Vector3 _dirtSize;

                    std::unique_ptr<Cubic> _grass;
                    std::unique_ptr<Cubic> _dirt;
                    std::unique_ptr<Cubic> _wire;

                    std::unique_ptr<Model3D> _food;
                    std::unique_ptr<Model3D> _egg;
                    std::unique_ptr<Model3D> _linemate;
                    std::unique_ptr<Model3D> _deraumere;
                    std::unique_ptr<Model3D> _sibur;
                    std::unique_ptr<Model3D> _mendiane;
                    std::unique_ptr<Model3D> _phiras;
                    std::unique_ptr<Model3D> _thystame;
            };
        }
    }
}

#endif /* !COMPONENT_TILE_HPP_ */
