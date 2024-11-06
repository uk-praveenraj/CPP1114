#include <iostream>

// Template to calculate factorial at compile time
template<int N>
struct Factorial {
    static const int value = N * Factorial<N - 1>::value;
};

// Specialization for the base case
template<>
struct Factorial<0> {
    static const int value = 1;
};

int main() {
    // Calculate factorial of 5 at compile-time
    std::cout << "Factorial of 5 is: " << Factorial<5>::value << std::endl;
    return 0;
}