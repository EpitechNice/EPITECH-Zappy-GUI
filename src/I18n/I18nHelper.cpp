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

            void I18nHelper::loadTranslations()
            {
                std::string filepath;
                std::ifstream translationFile;
                std::string line;
                size_t separatorPos;

                try {
                    filepath = "lang/" + getLocaleValue(this->_currentLocale) + "/translations.txt";
                } catch (const std::exception &e) {
                    throw Exceptions::TranslationFileNotFound("Error when try find translation file: " + std::string(e.what()), EXCEPTION_INFOS);
                }

                translationFile.open(filepath);
                if (!translationFile.is_open())
                    throw Exceptions::TranslationFileNotFound("Error when open translation file: " + filepath);

                if (!this->_translations.empty())
                    this->_translations.clear();
//TODO : To review, parser should be more complete
                while (getline(translationFile, line)) {
                    separatorPos = line.find('=');
                    if (separatorPos!= std::string::npos) {
                        std::string key = line.substr(0, separatorPos);
                        std::string value = line.substr(separatorPos + 1);
                        this->_translations[key] = value;
                    }
                }
                translationFile.close();
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

//TODO : Verify that we throw an exception when translation key not found or any other way
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