/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** ComponentInspecterSelecterGroup
*/

#ifndef COMPONENT_INSPECTER_SELECTER_GROUP_HPP_
    #define COMPONENT_INSPECTER_SELECTER_GROUP_HPP_

    #include <vector>

    #include "ComponentInspecterSelecter.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            class InspecterSelecterGroup {
                public:
                    InspecterSelecterGroup(std::pair<int, int> pos, int width);
                    ~InspecterSelecterGroup();

                    void destroy();

                    void update();

                    void draw();

                    void reset();

                    void addPlayer(std::shared_ptr<Zappy::GUI::Ressources::Players> player);

                    void modPosX(int x);

                protected:
                private:
                    std::pair<int, int> _pos;
                    std::pair<int, int> _size;
                    std::vector<std::shared_ptr<InspecterSelecter>> _players;
                    bool _isDestroyed = false;
                    int _selected = -1;
            };
        }
    }

}


#endif /* !COMPONENT_INSPECTER_SELECTER_GROUP_HPP_ */
