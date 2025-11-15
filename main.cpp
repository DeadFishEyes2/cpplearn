#include "Matrix/Matrix.hpp"
#include "NumericalMethods/nm.hpp"
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

    int* p = nullptr;
    int* q = nullptr;
    Sq_Matrix U, M;
    gaussianEliminationCompletePermutation(A, U, M, p, q);

    std::cout << "\nMatrix U:\n";
    U.consolePrint();

    std::cout << "\nMatrix M:\n";
    M.consolePrint();

    for (int i = 0; i < 2; i++){
        A.swapRows(i, p[i]);
    }
    
    Sq_Matrix* N = getMultiplicators(M);
    for (int i = 0; i < 2; i++){
        A = N[i]*A;
    }
    for (int i = 0; i < 2; i++){
        A.swapCols(i, q[i]);
    }

    std::cout << "\nMatrix M*P*A*Q:\n";
    A.consolePrint();

    return 0;
}
