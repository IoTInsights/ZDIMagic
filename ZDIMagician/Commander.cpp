//
// Created by rex on 26.02.2023.
//

#include <string>

#include "Command.h"
#include "Commander.h"
#include "Parameter.h"

Commander::Commander(const Parameter & parameter) : m_Parameter(parameter), m_USBSerial(m_Parameter.getPort())
{
}

void Commander::execute(Command & command)
{
    std::string command_string = command.getCommandString();

    for (uint8_t byte : command_string) {
        m_USBSerial.writeByte(byte);
    }

    std::string result_string;
    uint32_t level = 0;
    uint8_t received = 0;

    while ((level > 0) || (result_string.length() == 0)) {
        received = m_USBSerial.readByte();
        if (received == '{') {
            level += 1;
        }
        if (level > 0) {
            result_string += (char)received;
            if (received == '}') {
                level -= 1;
            }
        }
    }

    command.setResultString(result_string);
}
