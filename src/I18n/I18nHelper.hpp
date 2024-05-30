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
                en_GB,
                jp_JP
            };

            class I18nHelper
            {
                private:
                //Singleton, check if it's correct
                    static I18nHelper* _instance;
                    I18nHelper(): _currentLocale(SupportedLocale::en_GB) {
                        this->loadTranslations();
                    };

                //Basic attributes
                    SupportedLocale _currentLocale;
                    std::map<std::string, std::string> _translations;

                //Key/Value of supported locale : using for catch translation file of current locale
                    const std::map<SupportedLocale, std::string> _supportedLocaleMap = {
                        {SupportedLocale::fr_FR, "fr_FR"},
                        {SupportedLocale::en_GB, "en_GB"},
                        {SupportedLocale::jp_JP, "jp_JP"}
                    };

                protected:


                public:
                //Singleton
                    I18nHelper(const I18nHelper& other) = delete;
                    ~I18nHelper() = default;

                    static I18nHelper* getInstance();

                //Load translation file of current locale into a map attribute
                //Called at begin & when we change current locale
                //translation.txt must be formatted like this (on one line -> to improve ?): [key] = "value"
                    void loadTranslations();

                    SupportedLocale getCurrentLocale();
                    std::string getLocaleValue(SupportedLocale locale);
                //Method to call when we want to display a string
                //key parameter : translation key put on code
                //Return value of translation key
                    std::string getTranslation(std::string key);

                    void setCurrentLocale(SupportedLocale locale);

            };
        }
    }
}

#endif /* I18NHELPER_HPP */