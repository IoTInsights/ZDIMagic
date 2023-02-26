//
// Created by rex on 26.02.2023.
//

#include "Command.h"
#include "Magician.h"
#include "Parameter.h"

Magician::Magician (const Parameter & parameter) : m_Parameter(parameter), m_Commander(m_Parameter)
{
}

void Magician::doMagic()
{
    switch (m_Parameter.getCommand()) {
        case Parameter::Command::info:
            printfInfo();
            break;

        case Parameter::Command::dump:
            dumpMemory();
            break;

        case Parameter::Command::read:
            readMemory();
            break;

        case Parameter::Command::write:
            writeMemory();
            break;

        case Parameter::Command::flash:
            writeFlash();
            break;

        default:
            break;
    }
}

void Magician::printfInfo()
{
    Command command("info");

    m_Commander.execute(command);


}

void Magician::dumpMemory()
{
}

void Magician::readMemory()
{
}

void Magician::writeMemory()
{
}

void Magician::writeFlash()
{
}
