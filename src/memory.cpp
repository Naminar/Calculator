#include "../include/memory.hpp"

bool isEqual(double num1, double num2) {
    const double epsilon = 10e-5;
    return ((num1 - num2) < epsilon);
}

bool isZero(double num) { return isEqual(num, 0); }



int digitCount(double num) {
    int body = int(num);
    
    int counter = 0;
    while (body != 0) { ++counter; body /= 10;}
    while (num - int(num) != 0) { ++counter; num *= 10; }
    return counter;
}

Number standard(double num) {
    Number tmp; 
    tmp.body = num;

    std::cout << digitCount(tmp.body) << std::endl;

    int counter = digitCount(tmp.body);
    if (counter > 8) {
        if (tmp.body > 10) {
            while (int(tmp.body) / 10 != 0) {
                tmp.body *= std::pow(10, -1);
                tmp.power += 1;
            }
        }
        else if (tmp.body < 1) {
            while (int(tmp.body) == 0) {
                tmp.body *= std::pow(10, 1);
                tmp.power -= 1;
            }
        }
    }
    return tmp;
}



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
