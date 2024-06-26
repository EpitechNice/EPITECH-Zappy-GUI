/*
** EPITECH PROJECT, 2024
** tmp
** File description:
** RelativePlayerPosition
*/

#ifndef RELATIVEPLAYERPOSITION_HPP_
    #define RELATIVEPLAYERPOSITION_HPP_

    #include <string>
    #include <raylib.h>

namespace Zappy {
    namespace GUI {
        class RelativePlayerPosition {
            public:
                static RelativePlayerPosition *get();

                void setStart(Vector3 start);
                void setTileSize(float tileSize);

                Vector3 getRelativePlayerPosition(int x, int y);

            private:
                RelativePlayerPosition() = default;
                ~RelativePlayerPosition() = default;

                Vector3 _start = {0, 0, 0};
                float _tileSize = 0;
        };
    }
}

#endif /* !RELATIVEPLAYERPOSITION_HPP_ */
