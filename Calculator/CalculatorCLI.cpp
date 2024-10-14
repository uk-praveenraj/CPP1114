#include "Calculator.h"
#include <iostream>

int main() {
    Calculator calc;
    double operand1, operand2;
    char oper;

    std::cout << "Enter the operation:" << std::endl;
    std::cout << "(eg: 1 + 2 ) Supported operators are +, -, / and *" << std::endl;
    std::cin >> operand1 >> oper >> operand2;

    if(!std::cin.good()){
        std::cout << "Invalid inputs!" << std::endl;
        return 1;
    }
    try {
        double result;
        switch (oper) {
            case '+': result = calc.add(operand1, operand2); break;
            case '-': result = calc.subtract(operand1, operand2); break;
            case '*': result = calc.multiply(operand1, operand2); break;
            case '/': result = calc.divide(operand1, operand2); break;
            default: 
                std::cout << "Invalid choice!" << std::endl;
                return 1;
        }
        std::cout << "Result: " << result << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}