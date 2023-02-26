//
// Created by rex on 26.02.2023.
//

#include "MagicException.h"

MagicException::MagicException(const std::string & message)
{
    m_message = message;
}

const char * MagicException::what() const noexcept
{
    return m_message.c_str();
}
