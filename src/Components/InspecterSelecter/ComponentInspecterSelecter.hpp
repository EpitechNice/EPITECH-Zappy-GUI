/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** InspecterSelecter
*/

#ifndef COMPONENT_INSPECTER_SELECTER_HPP_
    #define COMPONENT_INSPECTER_SELECTER_HPP_

    #include <iostream>
    #include <memory>
    #include <raylib.h>

    #include "Players.hpp"
    #include "ComponentRoundedRectangle.hpp"
    #include "ComponentText.hpp"
    #include "ComponentCircle.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            class InspecterSelecter {
                public:
                    InspecterSelecter(std::pair<int, int> pos, int width, std::shared_ptr<Zappy::GUI::Ressources::Players> player);
                    ~InspecterSelecter();

                    void destroy();

                    void update();

                    void draw();

                    void modPosX(int x);
                    void modPosY(int y);
                    void setPosX(int x);
                    void setPosY(int y);

                    std::pair<int, int> getSize() const;

                    void setSelected(bool selected);

                    bool isClicked() const;

                    std::shared_ptr<Zappy::GUI::Ressources::Players> getPlayer() const;

                protected:
                private:
                    typedef enum {
                        NONE,
                        HOVER,
                        CLICKED,
                        SELECTED,
                    } State;

                    std::pair<int, int> _pos;
                    std::pair<int, int> _size;
                    std::shared_ptr<Zappy::GUI::Ressources::Players> _player;
                    std::unique_ptr<RoundedRectangle> _background;
                    std::unique_ptr<Text> _text;
                    std::unique_ptr<Circle> _team;
                    State _state = NONE;
                    bool _isDestroyed = false;
            };
        }
    }
}

#endif /* !COMPONENT_INSPECTER_SELECTER_HPP_ */
