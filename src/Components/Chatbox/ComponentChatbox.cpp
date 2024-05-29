/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** ComponentChatbox
*/

#include "ComponentChatbox.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            Chatbox::Chatbox()
                : _isDestroyed(false)
            {
                int height = GetScreenHeight();
                _width = GetScreenWidth() / 3;
                int heightPart = height / 8;

                _rectTop = std::make_unique<Rectangle>(std::make_pair(-_width, 0), std::make_pair(_width, heightPart), (Color){112, 108, 79, 255});
                _rectMid = std::make_unique<Rectangle>(std::make_pair(-_width, 0), std::make_pair(_width, height), (Color){68, 69, 64, 255});
                _rectBot = std::make_unique<Rectangle>(std::make_pair(-_width, height - heightPart), std::make_pair(_width, heightPart), (Color){112, 108, 79, 255});
                _rectTop->setStroke(1, BLACK);
                _rectMid->setStroke(3, BLACK);
                _rectBot->setStroke(1, BLACK);

                _openButton = std::make_unique<Button>(std::make_pair(0, 0), std::make_pair(-5, -40), ">", 30, ORANGE);
                _openButton->disableBubble();
                std::pair<float, float> buttonSize = _openButton->getSize();
                _openButton->setPos(std::make_pair(8, height / 2 - buttonSize.second / 2));
                _open = false;

                _textGroup = std::make_unique<TextGroup>(std::make_pair(-_width + 10, heightPart + 10), _width - 20, 20);
            }

            Chatbox::~Chatbox()
            {
                if (!_isDestroyed)
                    destroy();
            }


            void Chatbox::destroy()
            {
                _openButton->destroy();
                _textGroup->destroy();
            }


            void Chatbox::draw()
            {
                _rectMid->draw();
                _textGroup->draw();
                _rectTop->draw();
                _rectBot->draw();
                _openButton->draw();
            }

            void Chatbox::update()
            {
                if (_openButton->isClicked())
                    (_open) ? _setChatboxClose() : _setChatboxOpen();

                if (IsKeyReleased(KEY_ENTER)) {
                    std::vector<std::string> names = {
                        "Aelion",
                        "Arnaud",
                        "Dan13615",
                        "Dragusheen",
                        "H4rdeol",
                        "Tech0ne",
                    };
                    std::vector<std::string> messages = {
                        "Hello everyone! How are you doing?",
                        "I think we should go to the north, or maybe the east ?... No ! The west ! AHH I don't know !",
                        "I'm going to the south, I need some wood !",
                        "Can someone give me some food ? I'm starving !",
                        "UwU",
                    };
                    int randomName = rand() % names.size();
                    int randomMessage = rand() % messages.size();
                    _textGroup->addText(names[randomName], messages[randomMessage], 5, (Color){207, 205, 164, 255});
                }
            }


            void Chatbox::_setChatboxOpen()
            {
                _rectTop->setPosX(0);
                _rectMid->setPosX(0);
                _rectBot->setPosX(0);
                _openButton->setPosX(_width + 8);
                _openButton->setText("<");

                _textGroup->setPosX(10);
                _open = true;
            }

            void Chatbox::_setChatboxClose()
            {
                _rectTop->setPosX(-_width);
                _rectMid->setPosX(-_width);
                _rectBot->setPosX(-_width);
                _openButton->setPosX(8);
                _openButton->setText(">");

                _textGroup->setPosX(-_width + 10);
                _open = false;
            }
        }
    }
}