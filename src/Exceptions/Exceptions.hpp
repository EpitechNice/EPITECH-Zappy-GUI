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
        public:
            /**
             * @brief Construct a new Exception object
             *
             * @param what The message of the exception. Default is "An exception occured !"
             * @param position The position of the exception. Default is {"", {"", 0}}
             */
            Exception(std::string what = "An exception occured !", std::pair<std::string, std::pair<std::string, std::size_t>> position = {"", {"", 0}});

            /**
             * @brief Get the class name of the exception
             *
             * @return `std::string` The class name of the exception
             */
            std::string getClassName() const;

            /**
             * @brief Get the position of the exception
             *
             * @return `std::pair<std::string, std::pair<std::string, std::size_t>>` The position of the exception
             */
            std::pair<std::string, std::pair<std::string, std::size_t>> getInfos() const;

            /**
             * @brief Get the message of the exception
             *
             * @return `const char*` The message of the exception
             */
            const char* what() const noexcept override;

            /**
             * @brief Get the message of the exception
             *
             * @note This function is friend with the `std::ostream` class
             *
             * @return `std::string` The message of the exception
             */
            friend std::ostream& operator<<(std::ostream& os, const Exceptions::Exception& obj);

        protected:
            std::string _what;
            std::pair<std::string, std::pair<std::string, std::size_t>> _position;
    };

    /**
     * @brief Exception thrown in case of an unknown locale
     *
     * @note This class derives from the `Exception` class
     */
    class UnknownLocale: public Exceptions::Exception
    {
        public:
            /**
             * @brief Construct a new Unknown Locale object
             *
             * @param what The message of the exception. Default is "Locale non supported."
             * @param position The position of the exception. Default is {"", {"", 0}}
             *
             * @warning This exception will be thrown using the `Exception` class
             */
            UnknownLocale(std::string what = "Locale non supported.", std::pair<std::string, std::pair<std::string, std::size_t>> position = {"", {"", 0}});
    };

    /**
     * @brief Exception thrown in case of an unknown font
     *
     * @note This class derives from the `Exception` class
     */
    class TranslationFileNotFound: public Exceptions::Exception
    {
        public:
            /**
             * @brief Construct a new Translation File Not Found object
             *
             * @param what The message of the exception. Default is "Translation file not found."
             * @param position The position of the exception. Default is {"", {"", 0}}
             *
             * @warning This exception will be thrown using the `Exception` class
             */
            TranslationFileNotFound(std::string what = "Translation file not found.", std::pair<std::string, std::pair<std::string, std::size_t>> position = {"", {"", 0}});
    };

    /**
     * @brief Exception thrown in case of an unknown translation key
     *
     * @note This class derives from the `Exception` class
     */
    class UnknownTranslationKey: public Exceptions::Exception
    {
        public:
            /**
             * @brief Construct a new Unknown Translation Key object
             *
             * @param what The message of the exception. Default is "Translation key not found."
             * @param position The position of the exception. Default is {"", {"", 0}}
             *
             * @warning This exception will be thrown using the `Exception` class
             */
            UnknownTranslationKey(std::string what = "Translation key not found.", std::pair<std::string, std::pair<std::string, std::size_t>> position = {"", {"", 0}});
    };

    /**
     * @brief Exception thrown in case of a failed connection to the server
     *
     * @note This class derives from the `Exception` class
     */
    class ConnexionServeurFail: public Exceptions::Exception
    {
        public:
            /**
             * @brief Construct a new Connexion Serveur Fail object
             *
             * @param what The message of the exception. Default is "Connection to server failed"
             * @param serverAddress The address of the server. Default is ""
             * @param serverPort The port of the server. Default is 0
             *
             * @warning This exception will be thrown using the `Exception` class
             */
            ConnexionServeurFail(std::string what = "Connection to server failed", std::string serverAddress = "", int serverPort = 0);
    };
}

#endif
