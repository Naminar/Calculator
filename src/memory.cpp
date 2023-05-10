#include "../include/memory.hpp"

bool isEqual(double num1, double num2) {
    const double epsilon = 10e-5;
    return ((num1 - num2) < epsilon);
}

bool isZero(double num) { return isEqual(num, 0); }

auto splitString(const std::string& str) {
    auto pos = str.find('e');
    if (pos != str.npos) {
        std::string prefix {str.begin(), str.begin() + pos};
        std::string suffix {str.begin() + pos + 1, str.end()};
        return Number{std::stod(prefix), std::stoi(suffix)};
    }
    else {
        return Number{std::stod(str), 0};
    }
}

Number standard(double num) {
    // int body = int(num);
    
    // int counter = 0;
    // while (body != 0) { std::cout << "counting body\n";++counter; body /= 10;}
    // while (num - int(num) != 0) { 
    //     ++counter; num *= 10; }
    // return counter;

    std::stringstream ss;
    ss.setf(std::ios::fixed);
    ss << std::setprecision(100) << num;

    auto str = ss.str();
    auto pos = str.find('.');
    std::stringstream nss;

    if ((pos > 7) || (str[0] == '0' and pos == 1 and str.find_first_not_of('0', 2) != str.npos)) {
        std::cout << "scientific form\n";
        nss.setf(std::ios::scientific);
        nss << num;
    } 
    else {
        std::cout << "normal form\n";
        nss.setf(std::ios::fixed);
        nss << std::setprecision(8 - pos) << num;
    }  

    // std::cout << "scientific form\n";
    // nss.setf(std::ios::scientific);
    // nss << num;

    // auto eshka = str.find('e');
    // std::string suffix {str.begin() + eshka + 1, str.end()};
    // if (std::stoi(suffix) > 7 || std::stoi(suffix) < -7) {
    //     std::string prefix {str.begin(), str.begin() + eshka};
    //     return Number{std::stod(prefix), std::stoi(suffix)};
    // }
    // else {
    //     return Number{std::stod(str), 0};
    // }

    return splitString(nss.str());

    // std::cout << "ss.str() = " << nss.str() << std::endl;
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
