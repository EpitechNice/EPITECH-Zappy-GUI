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
    #include <tuple>

    #include "ComponentRectangle.hpp"
    #include "ComponentButton.hpp"
    #include "ComponentButtonClassic.hpp"
    #include "ComponentTextGroupDraggable.hpp"
    #include "ComponentCircle.hpp"

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

                    void addMessage(const std::string &message, const std::string &name, const std::string &tabName);

                    bool mouseIsOn() const;

                protected:
                private:
                    bool _isDestroyed;
                    bool _open;
                    int _width;
                    bool _hasNotif;

                    std::unique_ptr<Rectangle> _rectTopBackground;
                    std::unique_ptr<Rectangle> _rectTop;
                    std::unique_ptr<Rectangle> _rectMid;
                    std::unique_ptr<Rectangle> _rectBot;
                    std::unique_ptr<Button> _openButton;
                    std::unique_ptr<Circle> _notifCircle;

                    typedef enum {
                        NAME = 0,
                        BUTTON = 1,
                        TEXT_GROUP = 2,
                        NOTIF = 3,
                        NOTIF_COUNT = 4
                    } ChatIndex;

                    std::vector<std::tuple<std::string, std::unique_ptr<ButtonClassic>, std::unique_ptr<TextGroupDraggable>, std::unique_ptr<Circle>, int>> _chats;
                    int _chatIndex;

                    void _setChatboxOpen();
                    void _setChatboxClose();
                    void _updateChatbox();
            };
        }
    }
}

#endif /* !COMPONENTCHATBOX_HPP_ */
