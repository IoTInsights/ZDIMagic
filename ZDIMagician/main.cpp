
#include <exception>
#include <iostream>

#include "Magician.h"
#include "Parameter.h"

int main(int argc, char** argv) {
    try {
        Parameter parameter(argc, argv);

        Magician magician(parameter);
        magician.doMagic();
    }
    catch (std::exception & e) {
        std::cerr << "Operation failed: " << e.what() << std::endl;
    }

    return 0;
}
