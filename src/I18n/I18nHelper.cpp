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

            I18nHelper* I18nHelper::getInstance()
            {
                if (_instance == nullptr) {
                    _instance = new I18nHelper();
                    return _instance;
                } else {
                    return _instance;
                }
            }

//TODO (1): First draft of simple parser when in .txt it was like key=value (too simple I think)
//             void I18nHelper::loadTranslations()
//             {
//                 std::string filepath;
//                 std::ifstream translationFile;
//                 std::string line;
//                 size_t separatorPos;

//                 try {
//                     filepath = "lang/" + getLocaleValue(this->_currentLocale) + "/translations.txt";
//                 } catch (const std::exception &e) {
//                     throw Exceptions::TranslationFileNotFound("Error when try find translation file: " + std::string(e.what()), EXCEPTION_INFOS);
//                 }

//                 translationFile.open(filepath);
//                 if (!translationFile.is_open())
//                     throw Exceptions::TranslationFileNotFound("Error when open translation file: " + filepath);

//                 if (!this->_translations.empty())
//                     this->_translations.clear();
//
//                 while (getline(translationFile, line)) {
//                     separatorPos = line.find('=');
//                     if (separatorPos!= std::string::npos) {
//                         std::string key = line.substr(0, separatorPos);
//                         std::string value = line.substr(separatorPos + 1);
//                         this->_translations[key] = value;
//                     }
//                 }
//                 translationFile.close();
//             }

//TODO (2): So I made this parser based on regex pattern, .txt can be like [key] = "value";
// And I think that regex could be more flexible
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
                for (const auto& translation : this->_translations) {
                    std::cout << "DEBUG | " << translation.first << " = '" << translation.second << "'" << std::endl;
                }
            }

            SupportedLocale I18nHelper::getCurrentLocale()
            {
                return this->_currentLocale;
            }

            std::string I18nHelper::getLocaleValue(SupportedLocale locale)
            {
                try {
                    for (auto const& supportedLocale : this->_supportedLocaleMap) {
                        if (locale == supportedLocale.first)
                            return supportedLocale.second;
                    }
                } catch (const std::exception &e) {
                    throw Exceptions::UnknownLocale("Error when getting value from SupportedLocale: " + std::string(e.what()), EXCEPTION_INFOS);
                }
                return "";
            }

//TODO : Verify if we want to throw an exception when translation key not found or any other way
            std::string I18nHelper::getTranslation(std::string key)
            {
                try {
                    for (auto const& translation : this->_translations) {
                        if (key == translation.first) {
                            return translation.second;
                        }
                    }
                } catch (const std::exception &e) {
                    throw Exceptions::UnknownTranslationKey("Error when getting value from translation key: " + std::string(e.what()), EXCEPTION_INFOS);
                }
                return "";
            }

            void I18nHelper::setCurrentLocale(SupportedLocale locale)
            {
                this->_currentLocale = locale;
                this->loadTranslations();
            }

        }
    }
}