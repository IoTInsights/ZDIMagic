//
// Created by rex on 26.02.2023.
//

#ifndef ZDIMAGICIAN_MAGICIAN_H
#define ZDIMAGICIAN_MAGICIAN_H

#include "Commander.h"

class Parameter;

class Magician {
public:
    explicit Magician (const Parameter & parameter);

    void doMagic();

private:
    void printfInfo();
    void dumpMemory();
    void readMemory();
    void writeMemory();
    void writeFlash();

private:
    const Parameter     & m_Parameter;
    Commander           m_Commander;
};


#endif //ZDIMAGICIAN_MAGICIAN_H
