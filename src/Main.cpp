/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Main
*/

#include <iostream>

#include "Parsing.hpp"
#include "SceneManager.hpp"

// int main(int argc, char **argv)
// {
//     try {
//         srand(time(NULL));
//         Zappy::GUI::Parsing parsing(argc, argv);
//         std::cout << "Port: " << parsing.getPort() << std::endl;
//         std::cout << "Machine: " << parsing.getMachine() << std::endl;
//         Zappy::GUI::SceneManager sceneManager;
//         sceneManager.run();
//     } catch (const Zappy::GUI::Parsing::ParsingError &e) {
//         std::cerr << "Error: " << e.what() << std::endl;
//         std::cerr << ">> Use -help for help." << std::endl;
//         return 84;
//     } catch (const Zappy::GUI::Parsing::Help &e) {
//         e.what();
//         return 0;
//     } catch (const std::exception &e) {
//         std::cerr << "Unexpected error: " << e.what() << std::endl;
//         return 84;
//     }
//     return 0;
// }


//Test I18nHelper
  #include "I18nHelper.hpp"

int main() {
    Zappy::GUI::I18n::I18nHelper* i18nHelper = Zappy::GUI::I18n::I18nHelper::getInstance();

    try {
        i18nHelper->setCurrentLocale(Zappy::GUI::I18n::SupportedLocale::fr_FR);
        std::string translation = i18nHelper->getTranslation("[menu.start_title]");
        std::cout << ">>> Translation in " << i18nHelper->getLocaleValue(i18nHelper->getCurrentLocale()) << " for [menu.start_title] : '" << translation << "'" << std::endl;

        i18nHelper->setCurrentLocale(Zappy::GUI::I18n::SupportedLocale::en_GB);
        translation = i18nHelper->getTranslation("[menu.start_title]");
        std::cout << ">>> Translation in " << i18nHelper->getLocaleValue(i18nHelper->getCurrentLocale()) << " for [menu.start_title] : '" << translation << "'" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
    delete i18nHelper;
    return 0;
}
