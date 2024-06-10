/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Main
*/

#include <iostream>

#include "Parsing.hpp"
#include "SceneManager.hpp"
#include "CommunicationServer.hpp"

int main(int argc, char **argv)
{
    try {
        srand(time(NULL));
        Zappy::GUI::Parsing parsing(argc, argv);
        std::cout << "Port: " << parsing.getPort() << std::endl;
        std::cout << "Machine: " << parsing.getMachine() << std::endl;
        auto serverCommunication = Zappy::GUI::ServerCommunication(parsing.getMachine(), parsing.getPort());
        if (serverCommunication.connectToServer()) {
            std::cout << "server connected " << std::endl;
            serverCommunication.startCommunication();
            serverCommunication.addCommand("GRAPHIC\r\n");
            serverCommunication.addCommand("msz\r\n");
            serverCommunication.addCommand("bct 1 1\r\n");
        } else {
            std::cerr << "Failed to connect to the server" << std::endl;
            return 1;
        }
        // Zappy::GUI::SceneManager sceneManager;
        // sceneManager.run();
        while (1){
            
        }
    } catch (const Zappy::GUI::Parsing::ParsingError &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        std::cerr << ">> Use -help for help." << std::endl;
        return 84;
    } catch (const Zappy::GUI::Parsing::Help &e) {
        e.what();
        return 0;
    } catch (const std::exception &e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
        return 84;
    }
    return 0;
}


////Test I18nHelper
//   #include "I18nHelper.hpp"

// int main() {
//     Zappy::GUI::I18n::I18nHelper* i18nHelper = Zappy::GUI::I18n::I18nHelper::getInstance();

//     try {
//         i18nHelper->setCurrentLocale(Zappy::GUI::I18n::SupportedLocale::fr_FR);
//         std::string translation = i18nHelper->getTranslation("[menu.start_title]");
//         std::cout << ">>> Translation in " << i18nHelper->getLocaleValue(i18nHelper->getCurrentLocale()) << " for [menu.start_title] : '" << translation << "'" << std::endl;

//         i18nHelper->setCurrentLocale(Zappy::GUI::I18n::SupportedLocale::en_GB);
//         translation = i18nHelper->getTranslation("[menu.start_title]");
//         std::cout << ">>> Translation in " << i18nHelper->getLocaleValue(i18nHelper->getCurrentLocale()) << " for [menu.start_title] : '" << translation << "'" << std::endl;

//         i18nHelper->setCurrentLocale(Zappy::GUI::I18n::SupportedLocale::jp_JP);
//         translation = i18nHelper->getTranslation("Ceci n'est pas une clé de traduction.");
//         std::cout << ">>> Translation in " << i18nHelper->getLocaleValue(i18nHelper->getCurrentLocale()) << " for \"Ceci n'est pas une clé de traduction.\" : '" << translation << "'" << std::endl;
//         translation = i18nHelper->getTranslation("[UwU]");
//         std::cout << ">>> Translation in " << i18nHelper->getLocaleValue(i18nHelper->getCurrentLocale()) << " for [UwU] : '" << translation << "'" << std::endl;

//     } catch (const std::exception& e) {
//         std::cerr << "An error occurred: " << e.what() << std::endl;
//     }
//     delete i18nHelper;
//     return 0;
// }
