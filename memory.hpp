#include <iostream>
#include <cmath>
#include <algorithm>
#include <array>
#include <iomanip>
#include <stdexcept>

bool isEqual(double num1, double num2) {
    const double epsilon = 10e-5;
    return ((num1 - num2) < epsilon);
}

bool isZero(double num) { return isEqual(num, 0); }

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

void storePower(int number) { roundStack[0] *= std::pow(10, number); }

// "P" instructions:

void storeRegister(int place) { registers[place] = roundStack[0]; }
void loadRegister(int place) { roundStack[0] = registers[place]; }

void rightRotate() { std::rotate(roundStack.rbegin(), roundStack.rbegin() + 1, roundStack.rend()); }
void leftRotate()  { std::rotate(roundStack.begin(), roundStack.begin() + 1, roundStack.end()); }

void sinus()   { isZero(sin(roundStack[0])) ? roundStack[0] = 0 : roundStack[0] = sin(roundStack[0]); }
void cosinus() { isZero(cos(roundStack[0])) ? roundStack[0] = 0 : roundStack[0] = cos(roundStack[0]); }

void ln()       {
    if (roundStack[0] <= 0) throw std::invalid_argument("ln of not positive number");
    roundStack[0] = log(roundStack[0]);
}

void pi()       { roundStack[0] = 3.1415926; }
void expPower() { roundStack[0] = std::exp2f(roundStack[0]); } // -

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

struct Number {

double body  = 0;
int power = 0;

// Number operator+=(Number& rhs) const {
//     Number tmp;
//     tmp.body = body * std::pow(10, power) + rhs.body * std::pow(10, rhs.power);
//     tmp.standard();
//     return tmp;
// }

// Number operator+(Number& rhs) const {
//     Number tmp(*this); tmp += rhs; return tmp;
// }

// Number operator-=(Number& rhs) const {
//     Number tmp;
//     tmp.body = body * std::pow(10, power) - rhs.body * std::pow(10, rhs.power);
//     tmp.standard();
//     return tmp;
// }

// Number operator-(Number& rhs) const {
//     Number tmp(*this); tmp -= rhs; return tmp;
// }

// Number operator*=(Number& rhs) const {
//     Number tmp; 
//     tmp.body = body * std::pow(10, power) * rhs.body * std::pow(10, rhs.power);
//     tmp.standard();
//     return tmp;
// }

// Number operator*(Number& rhs) const {
//     Number tmp(*this); tmp *= rhs; return tmp;
// } 

// Number operator/=(Number& rhs) const {
//     Number tmp;
//     tmp.body = body * std::pow(10, power) / rhs.body * std::pow(10, rhs.power);
//     tmp.standard();
//     return tmp;
// }

// Number operator/(Number& rhs) const {
//     Number tmp(*this); tmp /= rhs; return tmp;
// }

// void standard() {
//     if (body / std::pow(10, 8)) {
//         int powSign = 0;
//         if (body > 10)     powSign = 1;
//         else if (body < 1) powSign = -1;

//         while (int(body) / 10 != 0) {
//             body *= std::pow(10, -powSign);
//             power += powSign;
//         }
//     }
// }

};

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
