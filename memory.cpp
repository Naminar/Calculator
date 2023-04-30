#include "memory.hpp"

template<typename T>
void Memory<T>::dump() {
    std::cout << "----------------------------------------" << std::endl;

    std::cout << "x = " << std::setprecision(10) << roundStack[0] << std::endl;
    std::cout << "y = " << std::setprecision(10) << registers[0] << std::endl;

    std::cout << "roundStack: " << std::endl;
    for (auto&& i : roundStack) {
        std::cout << std::setprecision(10) << i << std::endl;
    }

    std::cout << "registers: " << std::endl;
    for (auto&& i : registers) {
        std::cout << std::setprecision(10) << i << std::endl;
    }

    std::cout << "----------------------------------------" << std::endl;
}



/*int main() {
    Memory<double> mem;

    try {
        mem.storeDigit(2);
        mem.dump();

        mem.storeDigit(3);
        mem.dump();

        mem.storeDigit(8, true);
        mem.dump();

        mem.storeDigit(9, true);
        mem.dump();

        mem.storeDigit(6);
        mem.dump();

        mem.storeDigit(6, true);
        mem.dump();
        //mem.squareRoot();
        //mem.reciprocal();
        //mem.divide();
        //mem.ln();
    }
    catch (std::exception &error) {
        std::cout << error.what() << std::endl;
    }

    return 0;
}  */
