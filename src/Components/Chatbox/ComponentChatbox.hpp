/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** ComponentChatbox
*/

#ifndef COMPONENT_CHATBOX_HPP_
    #define COMPONENT_CHATBOX_HPP_

    #include <raylib.h>
    #include <string>
    #include <vector>
    #include <memory>

    #include "ComponentRectangle.hpp"
    #include "ComponentButton.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            class Chatbox {
                public:
                    Chatbox();
                    ~Chatbox();

                    void destroy();

                    void update();

                    void draw();

                protected:
                private:
                    bool _isDestroyed;
                    bool _open;
                    int _width;

                    std::unique_ptr<Rectangle> _rectTop;
                    std::unique_ptr<Rectangle> _rectMid;
                    std::unique_ptr<Rectangle> _rectBot;
                    std::unique_ptr<Button> _openButton;

                    void _setChatboxOpen();
                    void _setChatboxClose();
            };
        }
    }
}

#endif /* !COMPONENTCHATBOX_HPP_ */
