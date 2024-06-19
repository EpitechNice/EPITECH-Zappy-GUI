/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** Exceptions
*/

#include "Exceptions.hpp"

namespace Exceptions
{
    Exception::Exception(std::string what, std::pair<std::string, std::pair<std::string, std::size_t>> position)
        : _what(what), _position(position)
    {
        this->_position = position;
        std::stringstream ss;
        ss << "[" << this->getClassName();
        if (this->getInfos().first != "")
            ss << " - " <<
            this->getInfos().second.first.substr(this->getInfos().second.first.find_last_of("/\\") + 1) <<
            ":" << this->getInfos().second.second <<
            " in " << this->getInfos().first;
        ss << "] " << this->what();
        this->_what = ss.str();
    }

    std::string Exception::getClassName() const
    {
        int status = -4;
        const char* name = typeid(*this).name();
        char* _out = abi::__cxa_demangle(name, NULL, NULL, &status);
        if (status != 0 && _out)
            free(_out);
        if (status != 0)
            return std::string(name);
        std::string out(_out);
        free(_out);
        return out;
    }

    std::pair<std::string, std::pair<std::string, std::size_t>> Exception::getInfos() const
    {
        return this->_position;
    }

    const char* Exception::what() const noexcept
    {
        return this->_what.c_str();
    }

    std::ostream& operator<<(std::ostream& os, const Exceptions::Exception& obj)
    {
        os << obj.what();
        return os;
    }
}

namespace Exceptions
{
    UnknownLocale::UnknownLocale(std::string what, std::pair<std::string, std::pair<std::string, std::size_t>> position)
        : Exception(what, position)
    {
    }

    TranslationFileNotFound::TranslationFileNotFound(std::string what, std::pair<std::string, std::pair<std::string, std::size_t>> position)
        : Exception(what, position)
    {
    }

    UnknownTranslationKey::UnknownTranslationKey(std::string what, std::pair<std::string, std::pair<std::string, std::size_t>> position)
        : Exception(what, position)
    {
    }

    ConnexionServeurFail::ConnexionServeurFail(std::string what, std::string serverAdress, int serverPort)
    {
        std::string msg = what + " (Adress: " + serverAdress + ", Port: " + std::to_string(serverPort) + ")";
        throw Exception(msg);
    }
}