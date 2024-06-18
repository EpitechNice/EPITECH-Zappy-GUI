/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** AComponent
*/

#ifndef ABSTRACT_COMPONENT_HPP_
    #define ABSTRACT_COMPONENT_HPP_

    #include <iostream>
    #include <IComponent.hpp>

namespace Zappy {
    namespace GUI {
        namespace Component {
            /**
             * @brief Abstract class for all components
             */
            class AComponent: public IComponent {
                public:
                    AComponent() = default;
                    ~AComponent();

                    /**
                     * @brief Destroy the component
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void destroy() override;

                    /**
                     * @brief Draw the component
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void draw() override;

                    /**
                     * @brief Resize the component
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void resize() override;

                    /**
                     * @brief Set the reference of the component
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void setRef() override;


                    /**
                     * @brief Get the position of the component
                     *
                     * @return `float` The position on the X axis
                     */
                    float getPosX() const override;

                    /**
                     * @brief Get the position of the component
                     *
                     * @return `float` The position on the Y axis
                     */
                    float getPosY() const override;

                    /**
                     * @brief Get the position of the component
                     *
                     * @return `float` The position on the Z axis
                     */
                    float getPosZ() const override;

                    /**
                     * @brief Set the position of the component
                     *
                     * @param x The new position on the X axis
                     */
                    void setPosX(float x) override;

                    /**
                     * @brief Set the position of the component
                     *
                     * @param y The new position on the Y axis
                     */
                    void setPosY(float y) override;

                    /**
                     * @brief Set the position of the component
                     *
                     * @param z The new position on the Z axis
                     */
                    void setPosZ(float z) override;

                    /**
                     * @brief Modify the position of the component
                     *
                     * @param x The value to add to the current position on the X axis
                     */
                    void modPosX(float x) override;

                    /**
                     * @brief Modify the position of the component
                     *
                     * @param y The value to add to the current position on the Y axis
                     */
                    void modPosY(float y) override;

                    /**
                     * @brief Modify the position of the component
                     *
                     * @param z The value to add to the current position on the Z axis
                     */
                    void modPosZ(float z) override;

                    /**
                     * @brief Get the size of the component
                     *
                     * @return `float` The size on the X axis
                     */
                    float getSizeX() const override;

                    /**
                     * @brief Get the size of the component
                     *
                     * @return `float` The size on the Y axis
                     */
                    float getSizeY() const override;

                    /**
                     * @brief Get the size of the component
                     *
                     * @return `float` The size on the Z axis
                     */
                    float getSizeZ() const override;

                    /**
                     * @brief Set the size of the component
                     *
                     * @param x The new size on the X axis
                     */
                    void setSizeX(float x) override;

                    /**
                     * @brief Set the size of the component
                     *
                     * @param y The new size on the Y axis
                     */
                    void setSizeY(float y) override;

                    /**
                     * @brief Set the size of the component
                     *
                     * @param z The new size on the Z axis
                     */
                    void setSizeZ(float z) override;

                    /**
                     * @brief Modify the size of the component
                     *
                     * @param x The value to add to the current size on the X axis
                     */
                    void modSizeX(float x) override;

                    /**
                     * @brief Modify the size of the component
                     *
                     * @param y The value to add to the current size on the Y axis
                     */
                    void modSizeY(float y) override;

                    /**
                     * @brief Modify the size of the component
                     *
                     * @param z The value to add to the current size on the Z axis
                     */
                    void modSizeZ(float z) override;


                    /**
                     * @brief Get the color of the component
                     *
                     * @return `Color` The color of the component
                     */
                    Color getColor() const override;

                    /**
                     * @brief Set the color of the component
                     *
                     * @param color The new color of the component
                     */
                    void setColor(Color color) override;

                protected:
                    bool _isDestroyed = false;
                    float _posX = 0;
                    float _posY = 0;
                    float _posZ = 0;
                    float _sizeX = 0;
                    float _sizeY = 0;
                    float _sizeZ = 0;
                    Color _color = WHITE;

                    float _refSizeX = -1;
                    float _refSizeY = -1;
                    float _refPosX = -1;
                    float _refPosY = -1;
                    float _refHeight = -1;
                    float _refWidth = -1;

                private:
            };
        }
    }
}

#endif /* !ABSTRACT_COMPONENT_HPP_ */
