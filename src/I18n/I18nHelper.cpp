/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** Internationalization
*/

#include "I18nHelper.hpp"

namespace Zappy
{
    namespace GUI
    {
        namespace I18n
        {
            I18nHelper* I18nHelper::_instance = nullptr;

            I18nHelper::~I18nHelper()
            {
                if (!this->_translations.empty()) {
                    this->_translations.clear();
                }
            }

            I18nHelper* I18nHelper::getInstance()
            {
                if (_instance == nullptr) {
                    _instance = new I18nHelper();
                    return _instance;
                } else {
                    return _instance;
                }
            }

            void I18nHelper::loadTranslations()
            {
                std::string filepath;
                std::ifstream translationFile;
                std::string line;
                std::regex pattern(R"((\[.*?\])\s*=\s*\"(.*?)\")");

                try {
                    filepath = "lang/" + this->getLocaleValue(_currentLocale) + "/translations.txt";
                } catch (const std::exception &e) {
                    throw Exceptions::TranslationFileNotFound("Error when trying to find translation file: " + std::string(e.what()), EXCEPTION_INFOS);
                }

                translationFile.open(filepath);
                if (!translationFile.is_open()) {
                    throw Exceptions::TranslationFileNotFound("Error when opening translation file: " + filepath);
                }

                if (!this->_translations.empty()) {
                    this->_translations.clear();
                }

                while (getline(translationFile, line)) {
                    std::smatch matches;
                    if (std::regex_search(line, matches, pattern)) {
                        std::string key = matches[1].str();
                        std::string value = matches[2].str();
                        this->_translations[key] = value;
                    }
                }
                translationFile.close();
//TODO : Debug (to delete)
                // for (const auto& translation : this->_translations) {
                //     std::cout << "DEBUG | " << translation.first << " = '" << translation.second << "'" << std::endl;
                // }
            }

            SupportedLocale I18nHelper::getCurrentLocale()
            {
                return this->_currentLocale;
            }

            std::string I18nHelper::getLocaleValue(SupportedLocale locale)
            {
                for (auto const& supportedLocale : this->_supportedLocaleMap) {
                    if (locale == supportedLocale.first)
                        return supportedLocale.second;
                }
                throw Exceptions::UnknownLocale("Error when getting value from SupportedLocale: Locale non supported.", EXCEPTION_INFOS);
            }

            std::string I18nHelper::getTranslation(std::string key)
            {
                for (auto const& translation : this->_translations) {
                    if (key == translation.first) {
                        return translation.second;
                    }
                }
                return key;
            }

            void I18nHelper::setCurrentLocale(SupportedLocale locale)
            {
                this->_currentLocale = locale;
                this->loadTranslations();
            }
        }
    }
}