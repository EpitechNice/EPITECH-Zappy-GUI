/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** IComponent
*/

#ifndef INTERFACE_COMPONENT_HPP_
    #define INTERFACE_COMPONENT_HPP_

    #include <raylib.h>
    #include <iostream>

namespace Zappy {
    namespace GUI {
        namespace Component {
            /**
             * @brief Interface for all components
             */
            class IComponent {
                public:
                    virtual ~IComponent() = default;

                    /**
                     * @brief Destroy the component
                     *
                     * @warning This function should be called in the raylib context
                     */
                    virtual void destroy() = 0;

                    /**
                     * @brief Draw the component
                     *
                     * @warning This function should be called in the raylib context
                     */
                    virtual void draw() = 0;

                    /**
                     * @brief Resize the component
                     *
                     * @warning This function should be called in the raylib context
                     */
                    virtual void resize() = 0;

                    /**
                     * @brief Set the reference of the component
                     *
                     * @warning This function should be called in the raylib context
                     */
                    virtual void setRef() = 0;

                    /**
                     * @brief Get the position of the component
                     *
                     * @return `float` The position on the X axis
                     */
                    virtual float getPosX() const = 0;

                    /**
                     * @brief Get the position of the component
                     *
                     * @return `float` The position on the Y axis
                     */
                    virtual float getPosY() const = 0;

                    /**
                     * @brief Get the position of the component
                     *
                     * @return `float` The position on the Z axis
                     */
                    virtual float getPosZ() const = 0;

                    /**
                     * @brief Set the position of the component
                     *
                     * @param x The new position on the X axis
                     */
                    virtual void setPosX(float x) = 0;

                    /**
                     * @brief Set the position of the component
                     *
                     * @param y The new position on the Y axis
                     */
                    virtual void setPosY(float y) = 0;

                    /**
                     * @brief Set the position of the component
                     *
                     * @param z The new position on the Z axis
                     */
                    virtual void setPosZ(float z) = 0;

                    /**
                     * @brief Modify the position of the component
                     *
                     * @param x The value to add to the current position on the X axis
                     */
                    virtual void modPosX(float x) = 0;

                    /**
                     * @brief Modify the position of the component
                     *
                     * @param y The value to add to the current position on the Y axis
                     */
                    virtual void modPosY(float y) = 0;

                    /**
                     * @brief Modify the position of the component
                     *
                     * @param z The value to add to the current position on the Z axis
                     */
                    virtual void modPosZ(float z) = 0;


                    /**
                     * @brief Get the size of the component
                     *
                     * @return `float` The size on the X axis
                     */
                    virtual float getSizeX() const = 0;

                    /**
                     * @brief Get the size of the component
                     *
                     * @return `float` The size on the Y axis
                     */
                    virtual float getSizeY() const = 0;

                    /**
                     * @brief Get the size of the component
                     *
                     * @return `float` The size on the Z axis
                     */
                    virtual float getSizeZ() const = 0;


                    /**
                     * @brief Set the size of the component
                     *
                     * @param x The new size on the X axis
                     */
                    virtual void setSizeX(float x) = 0;

                    /**
                     * @brief Set the size of the component
                     *
                     * @param y The new size on the Y axis
                     */
                    virtual void setSizeY(float y) = 0;

                    /**
                     * @brief Set the size of the component
                     *
                     * @param z The new size on the Z axis
                     */
                    virtual void setSizeZ(float z) = 0;

                    /**
                     * @brief Modify the size of the component
                     *
                     * @param x The value to add to the current size on the X axis
                     */
                    virtual void modSizeX(float x) = 0;

                    /**
                     * @brief Modify the size of the component
                     *
                     * @param y The value to add to the current size on the Y axis
                     */
                    virtual void modSizeY(float y) = 0;

                    /**
                     * @brief Modify the size of the component
                     *
                     * @param z The value to add to the current size on the Z axis
                     */
                    virtual void modSizeZ(float z) = 0;


                    /**
                     * @brief Get the color of the component
                     *
                     * @return `Color` The color of the component
                     */
                    virtual Color getColor() const = 0;

                    /**
                     * @brief Set the color of the component
                     *
                     * @param color The new color of the component
                     */
                    virtual void setColor(Color color) = 0;

                protected:
                private:
            };
        }
    }
}


#endif /* !INTERFACE_COMPONENT_HPP_ */
