#include "Matrix/Matrix.hpp"
#include "NumericalMethods/Gauss/gauss.hpp"
#include "NumericalMethods/Crout/crout.hpp"
#include "NumericalMethods/Doolittle/doolittle.hpp"
#include <iostream>

int main() {
    
    // Example matrix
    float buf[] = {
        1, 2, 1,
        1, -2, 3,
        2, 1, 1
    };

    Sq_Matrix A(3, buf);

    std::cout << "Initial matrix A:\n";
    A.consolePrint();

    Sq_Matrix L, U;
    doolittle(A, L, U);

    std::cout << "Matrix L:\n";
    L.consolePrint();

    std::cout << "Matrix U:\n";
    U.consolePrint();
    
    std::cout << "Matrix L*U:\n";
    (L*U).consolePrint();

    return 0;
}
