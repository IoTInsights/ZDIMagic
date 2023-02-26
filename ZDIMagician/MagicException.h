//
// Created by rex on 26.02.2023.
//

#ifndef ZDIMAGICIAN_MAGICEXCEPTION_H
#define ZDIMAGICIAN_MAGICEXCEPTION_H

#include <exception>
#include <string>

class MagicException : public std::exception {
public:
    MagicException(const std::string & message);
    virtual const char * what() const noexcept override;

private:
    std::string m_message;
};


#endif //ZDIMAGICIAN_MAGICEXCEPTION_H
