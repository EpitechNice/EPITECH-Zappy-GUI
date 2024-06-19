/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** ComponentRessources
*/

#ifndef COMPONENT_RESSOURCES_HPP_
    #define COMPONENT_RESSOURCES_HPP_

    #include <raylib.h>
    #include <memory>

    #include "ComponentModel3D.hpp"
    #include "AComponent.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            /**
             * @brief Ressources component
             */
            class Ressources: public AComponent {
                public:
                    /**
                     * @brief Construct a new Ressources object
                     *
                     * @param size The size of the ressources
                     *
                     * @warning This function should be called in the raylib context
                     */
                    Ressources(Vector3 size);

                    /**
                     * @brief Set the position on the X axis
                     *
                     * @param x The new position on the X axis
                     */
                    void setPosX(float x) override;

                    /**
                     * @brief Set the position on the Y axis
                     *
                     * @param y The new position on the Y axis
                     */
                    void setPosY(float y) override;

                    /**
                     * @brief Set the position on the Z axis
                     *
                     * @param z The new position on the Z axis
                     */
                    void setPosZ(float z) override;

                    /**
                     * @brief Draw the ressources
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void drawFood();

                    /**
                     * @brief Draw the egg
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void drawEgg();

                    /**
                     * @brief Draw the linemate
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void drawLinemate();

                    /**
                     * @brief Draw the deraumere
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void drawDeraumere();

                    /**
                     * @brief Draw the sibur
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void drawSibur();

                    /**
                     * @brief Draw the mendiane
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void drawMendiane();

                    /**
                     * @brief Draw the phiras
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void drawPhiras();

                    /**
                     * @brief Draw the thystame
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void drawThystame();

                    /**
                     * @brief Draw the zappy
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void drawZappy();

                    /**
                     * @brief Resize the ressources
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void resize() override;

                protected:
                private:
                    Vector3 _refPosFood;
                    Vector3 _refPosEgg;
                    Vector3 _refPosLinemate;
                    Vector3 _refPosDeraumere;
                    Vector3 _refPosSibur;
                    Vector3 _refPosMendiane;
                    Vector3 _refPosPhiras;
                    Vector3 _refPosThystame;
                    Vector3 _refPosZappy;

                    std::unique_ptr<Model3D> _food;
                    std::unique_ptr<Model3D> _egg;
                    std::unique_ptr<Model3D> _linemate;
                    std::unique_ptr<Model3D> _deraumere;
                    std::unique_ptr<Model3D> _sibur;
                    std::unique_ptr<Model3D> _mendiane;
                    std::unique_ptr<Model3D> _phiras;
                    std::unique_ptr<Model3D> _thystame;
                    std::unique_ptr<Model3D> _zappy;
            };
        }
    }
}

#endif /* !COMPONENT_RESSOURCES_HPP_ */
