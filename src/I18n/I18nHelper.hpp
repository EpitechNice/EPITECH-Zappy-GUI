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
    #include "Path.hpp"

namespace Zappy
{
    namespace GUI
    {
        namespace I18n
        {
            /**
            * @brief Application supported locale
            *
            * @note Locale values follow i18n normalization
            * @note `fr_FR` designed french language from France
            * @note `en_GB` designed english language from Great Britain
            *
            * @warning To add a new application language : you must add locale values in this enumeration
            */
            enum class SupportedLocale
            {
                fr_FR,
                en_GB
            };

            class I18nHelper
            {
                private:
                    static I18nHelper* _instance;
                    /**
                     * @brief I18nHelper constructor
                     *
                     * @note Supported locale is stocked in _currentLocale attribute in english language from Great Britain by default
                     * @note Constructor load translations (all application displayed texts) in english language from Great Britain by default
                     *
                     * @warning I18nHelper is a singleton
                     */
                    I18nHelper(): _currentLocale(SupportedLocale::en_GB) {
                        this->loadTranslations();
                    };

                    SupportedLocale _currentLocale;
                    std::map<std::string, std::string> _translations;

                    /**
                    * @brief Application supported locale map
                    *
                    * @note Locale values follow i18n normalization
                    * @note `fr_FR` designed french language from France
                    * @note `en_GB` designed englsh language from Great Britain
                    *
                    * @warning To add a new application language : you must add locale values/locale values in string in this map
                    */
                    const std::map<SupportedLocale, std::string> _supportedLocaleMap = {
                        {SupportedLocale::fr_FR, "fr_FR"},
                        {SupportedLocale::en_GB, "en_GB"}
                    };

                protected:


                public:
                    I18nHelper(const I18nHelper& other) = delete;
                    ~I18nHelper();

                    /**
                     * @brief Get the instance of I18nHelper
                     *
                     * @note This function ensures that there is only one instance of the class (create an instance or return the current instance of the class)
                     */
                    static I18nHelper* getInstance();

                    /**
                     * @brief Set all application displayed texts in _translations attribute wich is a map of key/value
                     *
                     * @note All translations are retrieved from the "current_supported_locale.txt" file in the /lang/ folder
                     * @note If no translation key is found, the text will be displayed as is
                     * @note This function parse translation file with regex : translation files must follow nomenclature [key] = "value"
                     *
                     * @warning This function is called automatically in the constructor and each time the language is changed
                     */
                    void loadTranslations();

                    /**
                     * @brief Get current locale
                     *
                     * @note This function allows to get current locale from SupportedLocale enumeration
                     */
                    SupportedLocale getCurrentLocale();

                    /**
                     * @brief Get supported locale in string
                     *
                     * @note This function allows to get supported locale in string
                     * @note This function is used to retrieved translation file
                     *
                     * @param locale The locale from SupportedLocale enumeration to convert on string
                     */
                    std::string getLocaleValue(SupportedLocale locale);

                    /**
                     * @brief Get translation text from translation key
                     *
                     * @note This function must be called when display text
                     * @note This function is used to retrieved translation file
                     *
                     * @param key The key translation
                     */
                    std::string getTranslation(std::string key);

                    /**
                     * @brief Change current locale
                     *
                     * @note Change current application language
                     * @note Load translations associated
                     *
                     * @param locale New current locale to set
                     */
                    void setCurrentLocale(SupportedLocale locale);
            };
        }
    }
}

#endif /* I18NHELPER_HPP */