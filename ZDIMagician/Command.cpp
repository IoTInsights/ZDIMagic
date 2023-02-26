//
// Created by rex on 26.02.2023.
//

#include "cJSON.h"

#include "Command.h"
#include "MagicException.h"

Command::Command(const std::string & name)
{
    m_pResultObject;
    m_pObject = cJSON_CreateObject();
    cJSON * pCommandName = cJSON_CreateString(name.c_str());

    cJSON_AddItemToObject(m_pObject, "command", pCommandName);
}

Command::~Command()
{
    cJSON_Delete(m_pObject);
    cJSON_Delete(m_pResultObject);
}

std::string Command::getCommandString()
{
    return cJSON_Print(m_pObject);
}

void Command::setResultString(const std::string & result)
{
    cJSON_Delete(m_pResultObject);

    m_pResultObject = cJSON_Parse(result.c_str());

    if (nullptr == m_pResultObject) {
        const char * error_ptr = cJSON_GetErrorPtr();
        if (nullptr != error_ptr) {
            throw MagicException(std::string("Error Parsing Command Result at: ") + error_ptr);
        }
        else {
            throw MagicException("Error Parsing Command Result");
        }
    }
}
