#include <iostream>
#include <iomanip>

double readNumber() {
    double result, base = 10;
    result = std::cin.get() - '0';
    while (std::cin.peek() != '.' && std::cin.peek() != '\n')
        result = result * 10 + (std::cin.get() - '0');
    if (std::cin.peek() == '.') std::cin.ignore();
    while (std::cin.peek() != '\n') {
        result = result + (std::cin.get() - '0') / base;
        base *= 10;
    }
    std::cin.ignore();
    return result;
}

void printFormatted(double x, double y) {
    std::cout << "The value of x is: " <<
        std::setw(12) << std::setfill('0') <<
        std::fixed << std::left << x << std::endl;
    std::cout << "The value of y is: " <<
        std::setprecision(2) << std::scientific <<
        std::right << y << std::endl;
}

