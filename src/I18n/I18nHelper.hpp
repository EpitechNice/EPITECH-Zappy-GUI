/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** Internationalization
*/

#ifndef I18NHELPER_HPP
    #define I18NHELPER_HPP

    #include <string>
    #include <vector>
    #include <map>
    #include <iostream>
    #include <fstream>
    #include <regex>
    #include "Exceptions.hpp"

namespace Zappy
{
    namespace GUI
    {
        namespace I18n
        {
            enum class SupportedLocale
            {
                fr_FR,
                en_GB
            };

            class I18nHelper
            {
                private:
                    static I18nHelper* _instance;
                    I18nHelper(): _currentLocale(SupportedLocale::en_GB) {
                        this->loadTranslations();
                    };

                    SupportedLocale _currentLocale;
                    std::map<std::string, std::string> _translations;

                    const std::map<SupportedLocale, std::string> _supportedLocaleMap = {
                        {SupportedLocale::fr_FR, "fr_FR"},
                        {SupportedLocale::en_GB, "en_GB"}
                    };

                protected:


                public:
                    I18nHelper(const I18nHelper& other) = delete;
                    ~I18nHelper();

                    static I18nHelper* getInstance();

                    void loadTranslations();

                    SupportedLocale getCurrentLocale();
                    std::string getLocaleValue(SupportedLocale locale);
                    std::string getTranslation(std::string key);

                    void setCurrentLocale(SupportedLocale locale);
            };
        }
    }
}

#endif /* I18NHELPER_HPP */