//
// Created by rex on 26.02.2023.
//

#ifndef ZDIMAGICIAN_PARAMETER_H
#define ZDIMAGICIAN_PARAMETER_H

#include <string>

class Parameter {
public:
    enum class Command {
        unknown,
        dump,
        read,
        write,
        flash,
        info
    };

public:
    Parameter(int argc, char** argv);

    inline Command getCommand() const { return m_Command; }
    inline const std::string & getPort() const { return m_Port; }
    inline uint32_t getAddress() const { return m_Address; }
    inline uint32_t getLength() const { return m_Length; }

private:
    Command         m_Command;
    std::string     m_Port;
    uint32_t        m_Address;
    uint32_t        m_Length;
};

#endif //ZDIMAGICIAN_PARAMETER_H
