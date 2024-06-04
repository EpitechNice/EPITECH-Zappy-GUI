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
                int heightPartMini = heightPart / 4;

                _rectTopBackground = std::make_unique<Rectangle>(std::make_pair(-_width, 0), std::make_pair(_width, heightPart), (Color){68, 69, 64, 255});
                _rectTop = std::make_unique<Rectangle>(std::make_pair(-_width, heightPart - heightPartMini), std::make_pair(_width, heightPartMini), (Color){112, 108, 79, 255});
                _rectMid = std::make_unique<Rectangle>(std::make_pair(-_width, 0), std::make_pair(_width, height), (Color){68, 69, 64, 255});
                _rectBot = std::make_unique<Rectangle>(std::make_pair(-_width, height - heightPart), std::make_pair(_width, heightPart), (Color){112, 108, 79, 255});
                _rectTopBackground->setStroke(1, BLACK);
                _rectMid->setStroke(3, BLACK);
                _rectBot->setStroke(1, BLACK);

                _openButton = std::make_unique<Button>(std::make_pair(0, 0), std::make_pair(-5, -40), ">", 30, ORANGE);
                _openButton->disableBubble();
                std::pair<float, float> buttonSize = _openButton->getSize();
                _openButton->setPos(std::make_pair(8, height / 2 - buttonSize.second / 2));
                std::pair<float, float> openButtonSize = _openButton->getSize();
                std::pair<float, float> openButtonPos = _openButton->getPos();
                _notifCircle = std::make_unique<Circle>(std::make_pair(openButtonSize.first + openButtonPos.first, openButtonPos.second), 4, RED);

                std::vector<std::string> names = {
                    "Server",
                    "Global",
                };
                int gap = 5;
                int width = (_width - 40 - gap * (names.size() - 1)) / names.size();
                int heightButton = heightPart - heightPartMini;
                int y = -_width * 2 + 20;
                for (auto &name : names) {
                    _chats.push_back(std::make_tuple(
                        name,
                        std::make_unique<ButtonClassic>(std::make_pair(y, heightPartMini), std::make_pair(width, heightButton), name, 20, (Color){55, 56, 40, 255}),
                        std::make_unique<TextGroupDraggable>(std::make_pair(-_width + 10, heightPart + 10), std::make_pair(_width - 20, height - heightPart * 2), 20),
                        std::make_unique<Circle>(std::make_pair(y + width, heightPartMini), 4, (Color){255, 0, 0, 255}),
                        0
                    ));
                    y += width + gap;
                }
                _chatIndex = 0;
                std::get<BUTTON>(_chats[_chatIndex])->setColor((Color){112, 108, 79, 255});
                std::get<BUTTON>(_chats[_chatIndex])->disableState();
                _open = false;
                _hasNotif = false;
            }

            Chatbox::~Chatbox()
            {
                if (!_isDestroyed)
                    destroy();
            }


            void Chatbox::destroy()
            {
                _openButton->destroy();
                for (auto &chat : _chats) {
                    std::get<BUTTON>(chat)->destroy();
                    std::get<TEXT_GROUP>(chat)->destroy();
                }
            }


            void Chatbox::draw()
            {
                _rectMid->draw();
                std::get<TEXT_GROUP>(_chats[_chatIndex])->draw();
                _rectTopBackground->draw();
                for (auto &chat : _chats) {
                    std::get<BUTTON>(chat)->draw();
                    if (std::get<NOTIF_COUNT>(chat) > 0)
                        std::get<NOTIF>(chat)->draw();
                }
                _rectTop->draw();
                _rectBot->draw();
                _openButton->draw();
                if (_hasNotif && !_open)
                    _notifCircle->draw();
            }

            void Chatbox::update()
            {
                _updateChatbox();
                std::get<TEXT_GROUP>(_chats[_chatIndex])->update();
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
                    int randomChat = rand() % _chats.size();
                    addMessage(messages[randomMessage], names[randomName], std::get<NAME>(_chats[randomChat]));
                }
            }

            void Chatbox::addMessage(const std::string &message, const std::string &name, const std::string &tabName)
            {
                _hasNotif = true;
                for (std::size_t i = 0; i < _chats.size(); i++) {
                    if (std::get<NAME>(_chats[i]) == tabName) {
                        std::get<TEXT_GROUP>(_chats[i])->addText(name, message, 5, (Color){207, 205, 164, 255});
                        if ((int)i != _chatIndex)
                            std::get<NOTIF_COUNT>(_chats[i])++;
                        break;
                    }
                }
            }

            bool Chatbox::mouseIsOn() const
            {
                bool isOn = _openButton->isHover() || _openButton->isClicked();
                if (_open)
                    isOn = GetMouseX() < _width ? true : isOn;
                return isOn;
            }


            void Chatbox::_setChatboxOpen()
            {
                _rectTopBackground->setPosX(0);
                _rectTop->setPosX(0);
                _rectMid->setPosX(0);
                _rectBot->setPosX(0);
                _openButton->setPosX(_width + 8);
                _openButton->setText("<");

                for (auto &chat : _chats) {
                    std::get<BUTTON>(chat)->modPosX(_width * 2);
                    std::get<TEXT_GROUP>(chat)->setPosX(10);
                    std::get<NOTIF>(chat)->modPosX(_width * 2);
                }
                _open = true;
                _hasNotif = false;
            }

            void Chatbox::_setChatboxClose()
            {
                _rectTopBackground->setPosX(-_width * 2);
                _rectTop->setPosX(-_width * 2);
                _rectMid->setPosX(-_width * 2);
                _rectBot->setPosX(-_width * 2);
                _openButton->setPosX(8);
                _openButton->setText(">");

                for (auto &chat : _chats) {
                    std::get<BUTTON>(chat)->modPosX(-_width * 2);
                    std::get<TEXT_GROUP>(chat)->setPosX(-_width * 2 + 10);
                    std::get<NOTIF>(chat)->modPosX(-_width * 2);
                }
                _open = false;
                for (auto &chat : _chats)
                    if (std::get<NOTIF_COUNT>(chat) > 0)
                        _hasNotif = true;
            }


            void Chatbox::_updateChatbox()
            {
                int newIndex = _chatIndex;
                for (std::size_t i = 0; i < _chats.size(); i++)
                    if (std::get<BUTTON>(_chats[i])->isClicked())
                        newIndex = i;
                if (newIndex != _chatIndex) {
                    _chatIndex = newIndex;
                    for (auto &chat : _chats) {
                        std::get<BUTTON>(chat)->enableState();
                        std::get<BUTTON>(chat)->setColor((Color){55, 56, 40, 255});
                    }
                    std::get<BUTTON>(_chats[_chatIndex])->disableState();
                    std::get<BUTTON>(_chats[_chatIndex])->setColor((Color){112, 108, 79, 255});
                    std::get<NOTIF_COUNT>(_chats[_chatIndex]) = 0;
                }
            }
        }
    }
}