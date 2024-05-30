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

    #include "ComponentCubic.hpp"
    #include "ColorManager.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            class Tile {
                public:
                    Tile(Vector3 pos, Color color);
                    ~Tile() = default;

                    void draw();

                    void highlight(bool highlight);

                protected:
                private:
                    Vector3 _pos;
                    Color _color;
                    bool _highlight;

                    std::unique_ptr<Cubic> _grass;
                    std::unique_ptr<Cubic> _dirt;
                    std::unique_ptr<Cubic> _wire;
            };
        }
    }
}

#endif /* !COMPONENT_TILE_HPP_ */
