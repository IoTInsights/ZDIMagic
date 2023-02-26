//
// Created by rex on 26.02.2023.
//

#ifndef ZDIMAGICIAN_COMMAND_H
#define ZDIMAGICIAN_COMMAND_H

#include <string>

typedef struct cJSON cJSON;

class Command {
public:
    explicit Command(const std::string & name);
    ~Command();

    std::string getCommandString();
    void setResultString(const std::string & result);

private:
    cJSON * m_pObject;
    cJSON * m_pResultObject;
};


#endif //ZDIMAGICIAN_COMMAND_H
