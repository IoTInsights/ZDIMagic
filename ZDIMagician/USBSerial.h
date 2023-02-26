//
// Created by rex on 26.02.2023.
//

#ifndef ZDIMAGICIAN_USBSERIAL_H
#define ZDIMAGICIAN_USBSERIAL_H

#if defined(__linux__)

#else
#include "windows.h"

#endif

#include <string>

class USBSerial {
public:
    explicit USBSerial(const std::string & port);
    ~USBSerial();

    void writeByte(uint8_t byte);
    uint8_t readByte();

private:
#if defined(__linux__)

#else
    HANDLE m_PortHandle;

#endif
};


#endif //ZDIMAGICIAN_USBSERIAL_H
