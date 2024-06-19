/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** Ref
*/

#ifndef REF_HPP_
    #define REF_HPP_

    #include <memory>

    #include "Ressources.hpp"

namespace Zappy {
    namespace GUI {
        namespace Ressources {
            /**
             * @brief Reference to the ressources
             *
             * @note this class is a singleton
             */
            class Ref {
                public:
                    /**
                     * @brief Get the Ref object
                     */
                    static Ref *get();

                    /**
                     * @brief Get the ressources
                     *
                     * @return `ressources` The ressources
                     */
                    std::shared_ptr<Ressources> ressources = std::make_shared<Ressources>();

                protected:
                private:
                    Ref() = default;
                    ~Ref() = default;
            };
        }
    }
}

#endif /* !REF_HPP_ */
