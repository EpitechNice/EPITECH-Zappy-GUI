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
    #include "SharedMemory.hpp"

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

                    /**
                     * @brief Get the shared memory
                     *
                     * @return `shared_memory` The shared memory
                     */
                    std::shared_ptr<Zappy::Server::SharedMemory> shared_memory = nullptr;

                protected:
                private:
                    Ref() = default;
                    ~Ref() = default;
            };
        }
    }
}

#endif /* !REF_HPP_ */
