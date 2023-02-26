//
// Created by rex on 26.02.2023.
//

#ifndef ZDIMAGICIAN_COMMANDER_H
#define ZDIMAGICIAN_COMMANDER_H

#include "USBSerial.h"

class Command;
class Parameter;

class Commander {
public:
    explicit Commander(const Parameter & parameter);

    void execute(Command & command);

private:
    const Parameter     & m_Parameter;
    USBSerial           m_USBSerial;
};


#endif //ZDIMAGICIAN_COMMANDER_H
