/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** Exceptions
*/

#ifndef EXCEPTIONS_HPP
    #define EXCEPTIONS_HPP

    #include <iostream>
    #include <sstream>
    #include <cxxabi.h>

    #define EXCEPTION_INFOS {std::string(__FUNCTION__), {std::string(__FILE__), __LINE__}}

namespace Exceptions
{
    /**
      * Class used to declare custom Exceptions
      *
      * @anchor exceptions
      */
    class Exception: public std::exception
    {
        protected:
            std::string _what;
            std::pair<std::string, std::pair<std::string, std::size_t>> _position;
        public:
            Exception(std::string what = "An exception occured !",
                      std::pair<std::string, std::pair<std::string, std::size_t>> position = {"", {"", 0}});
            std::string getClassName() const;
            std::pair<std::string, std::pair<std::string, std::size_t>> getInfos() const;
            const char* what() const noexcept override;
            friend std::ostream& operator<<(std::ostream& os, const Exceptions::Exception& obj);
    };

    class UnknownLocale: public Exceptions::Exception
    {
        public:
            UnknownLocale(std::string what = "Locale non supported.",
                             std::pair<std::string, std::pair<std::string, std::size_t>> position = {"", {"", 0}}):
            Exceptions::Exception(what, position)
            {}
    };

    class TranslationFileNotFound: public Exceptions::Exception
    {
        public:
            TranslationFileNotFound(std::string what = "Translation file not found.",
                             std::pair<std::string, std::pair<std::string, std::size_t>> position = {"", {"", 0}}):
            Exceptions::Exception(what, position)
            {}
    };

    class UnknownTranslationKey: public Exceptions::Exception
    {
        public:
            UnknownTranslationKey(std::string what = "Translation key not found.",
                             std::pair<std::string, std::pair<std::string, std::size_t>> position = {"", {"", 0}}):
            Exceptions::Exception(what, position)
            {}
    };
    class ConnexionServeurFail: public Exceptions::Exception
    {
    public:
        ConnexionServeurFail(std::string what = "Connection to server failed",
                            std::string serverAddress = "",
                            int serverPort = 0)
            : Exceptions::Exception(what + " (Server Adress: " + serverAddress + ", serveur Port: " + std::to_string(serverPort) + ")")
        {}
    };
}

#endif
