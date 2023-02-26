//
// Created by rex on 26.02.2023.
//

#include "quick_arg_parser.hpp"

#include "MagicException.h"
#include "Parameter.h"

struct Input : MainArguments<Input> {
    std::string command = option("command", 'c', "Command") = "";
    uint32_t address    = option("address", 'a', "Memory Address") = 0xffffffff;
    uint32_t length     = option("length", 'l', "Length of Memory Block") = 0;
    std::string port    = option("port", 'p', "COM Port") = "";
    std::string infile  = option("infile", 'i', "Input File") = "";
    std::string outfile = option("outfile", 'o', "Output File") = "";

    inline static std::string version = "1.0";
    static std::string help(const std::string& programName) {
        return "Usage:\n" + programName + " FILE (SECONDARY_FILE)";
    }
};

Parameter::Parameter(int argc, char** argv)
{
    Input in{{argc, argv}};

    if (in.port.length() == 0) {
        throw MagicException("Need the serial port for the ZDI Flasher");
    }
    if (in.command.length() == 0) {
        throw MagicException("Need command to know what to do");
    }

    switch (in.command[0]) {
        case 'd':
            m_Command = Command::dump;
            break;

        case 'r':
            m_Command = Command::read;
            break;

        case 'w':
            m_Command = Command::write;
            break;

        case 'f':
            m_Command = Command::flash;
            break;

        case 'i':
            m_Command = Command::info;
            break;

        default:
            m_Command = Command::unknown;
            break;
    }

    if (m_Command == Command::unknown) {
        throw MagicException(std::string("Invalid command: ") + in.command);
    }

    m_Port = in.port;
    m_Address = in.address;
    m_Length = in.length;
}
