#include <iostream>
#include <cmath>
#include <algorithm>
#include <array>
#include <numbers>
#include <iomanip>
#include <stdexcept>

template<typename T = double>
class Memory final {
public:

T get_result() { return roundStack[0]; } // get X
void store(T number) { roundStack[0] = number; } // store in X

void storeDigit(T number, bool isFloat = false) {
    if (int(number) / 10 != 0 || number < 0) throw std::invalid_argument("not a digit");

    static bool frac = false;

    static int counter = 1;
    if (!isFloat) {
        if (frac == true) roundStack[0] = 0;
        roundStack[0] = roundStack[0] * 10 + number;
        counter = 1;
    }
    else {
        roundStack[0] = roundStack[0] + number * std::pow(10, -counter);
        ++counter;
    }
    frac = isFloat;
}

// "P" instructions:

void storeRegister(int place) { registers[place] = roundStack[0]; }
void loadRegister(int place) { roundStack[0] = registers[place]; }

void rightRotate() { std::rotate(roundStack.rbegin(), roundStack.rbegin() + 1, roundStack.rend()); }
void leftRotate()  { std::rotate(roundStack.begin(), roundStack.begin() + 1, roundStack.end()); }

void sinus()    { roundStack[0] = sin(roundStack[0]); }
void cosinus()  { roundStack[0] = cos(roundStack[0]); }
void ln()       {
    if (roundStack[0] <= 0) throw std::invalid_argument("ln of not positive number");
    roundStack[0] = log(roundStack[0]);
}

void pi()       { roundStack[0] = std::numbers::pi; }
void expPower() { roundStack[0] = std::exp2f(roundStack[0]); }

//
void plus()   { roundStack[0] = roundStack[0] + registers[0]; }
void minus()  { roundStack[0] = roundStack[0] - registers[0]; }
void dot()    { roundStack[0] = roundStack[0] * registers[0]; }
void divide() {
    if (registers[0] == 0) throw std::invalid_argument("division on zero");
    roundStack[0] = roundStack[0] / registers[0];
}

void opposite() { roundStack[0] = -roundStack[0]; } // "-"

// "F" instructions:

void reciprocal() {
    if (roundStack[0] == 0) throw std::invalid_argument("can't make reciprocal number for zero - division on zero");
    roundStack[0] = 1 / roundStack[0];
}
void square() { roundStack[0] = std::pow(roundStack[0], 2); }

void squareRoot() {
    if (roundStack[0] < 0) throw std::invalid_argument("sqrt of negative number");
    roundStack[0] = std::sqrt(roundStack[0]);
}

void power() { roundStack[0] = std::pow(roundStack[0], registers[0]); }

void swapXY() {
    T tmp = registers[0];
    registers[0]  = roundStack[0];
    roundStack[0] = tmp;
}

void dump();

void resetRoundStack() { for (auto itb = roundStack.begin(), ite = roundStack.end(); itb != ite; ++itb) *itb = 0; }
void resetRegisters()  { for (auto itb = registers.begin(),  ite = registers.end();  itb != ite; ++itb) *itb = 0; }
void reset() { resetRoundStack(); resetRegisters(); } 

//private:

public:

std::array<T, 7> roundStack{};
std::array<T, 7> registers{};

};
