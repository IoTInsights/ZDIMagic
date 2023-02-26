//
// Created by rex on 26.02.2023.
//

#include "MagicException.h"
#include "USBSerial.h"

USBSerial::USBSerial(const std::string & port)
{
#if defined(__linux__)

#else
    std::string filename = R"(\\.\)" + port;
    m_PortHandle = CreateFile(filename.c_str(), GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

    if (INVALID_HANDLE_VALUE == m_PortHandle) {
        throw MagicException(std::string("Unable to open port: ") + port);
    }
#endif
}

USBSerial::~USBSerial()
{
#if defined(__linux__)

#else
    CloseHandle(m_PortHandle);
#endif
}

void USBSerial::writeByte(uint8_t byte)
{
#if defined(__linux__)

#else
    DWORD written;

    if(!WriteFile(m_PortHandle, &byte, 1, &written, NULL))
    {
        throw MagicException("Unable to write to USB Device");
    }
#endif
}

uint8_t USBSerial::readByte()
{
    uint8_t result = 0;

#if defined(__linux__)

#else
    DWORD result_length;

    if(!ReadFile(m_PortHandle, &result, 1, &result_length, NULL))
    {
        throw MagicException("Unable to read from USB Device");
    }
#endif

    return result;
}
