/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** ComponentTextGroupDraggable
*/

#ifndef COMPONENT_TEXT_GROUP_DRAGGABLE_HPP_
    #define COMPONENT_TEXT_GROUP_DRAGGABLE_HPP_

    #include <raylib.h>
    #include <memory>

    #include "ComponentTextGroup.hpp"
    #include "AComponent.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            /**
             * @brief TextGroupDraggable component
             */
            class TextGroupDraggable: public AComponent {
                public:
                    /**
                     * @brief Construct a new TextGroupDraggable object
                     *
                     * @param pos The position of the component
                     * @param size The size of the component
                     * @param gap The gap between texts
                     *
                     * @warning This function should be called in the raylib context
                     */
                    TextGroupDraggable(std::pair<int, int> pos, std::pair<int, int> size, int gap);

                    /**
                     * @brief Draw the TextGroupDraggable
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void draw() override;

                    /**
                     * @brief Resize the TextGroupDraggable
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void resize() override;

                    /**
                     * @brief Set the Pos X object
                     *
                     * @param x The new x position
                     */
                    void setPosX(float x) override;

                    /**
                     * @brief Update the TextGroupDraggable
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void update();

                    /**
                     * @brief Add a text to the TextGroupDraggable
                     *
                     * @param name The name of the text
                     * @param text The text to add
                     * @param gap The gap between texts
                     * @param color The color of the text
                     */
                    void addText(std::string name, std::string text, int gap, Color color);

                protected:
                private:
                    int _gap;
                    bool _isDragged;
                    std::pair<int, int> _dragOffset;
                    std::unique_ptr<TextGroup> _textGroup;

                    void _updateTextsPos();
                    void _setDragOffset();
                    void _endDrag();
            };
        }
    }
}

#endif /* !COMPONENT_TEXT_GROUP_DRAGGABLE_HPP_ */
