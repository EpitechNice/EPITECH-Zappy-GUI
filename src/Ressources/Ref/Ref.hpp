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
            class Ref {
                public:
                    static Ref *get();
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
