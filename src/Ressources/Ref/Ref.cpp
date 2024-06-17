/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** Ref
*/

#include "Ref.hpp"

namespace Zappy {
    namespace GUI {
        namespace Ressources {
            Ref *Ref::get()
            {
                static Ref ref;
                return &ref;
            }
        }
    }
}