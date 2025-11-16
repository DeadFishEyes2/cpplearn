#include "Matrix/Matrix.hpp"
#include "NumericalMethods/Gauss/gauss.hpp"
#include "NumericalMethods/Crout/crout.hpp"
#include "NumericalMethods/Doolittle/doolittle.hpp"
#include "NumericalMethods/Cholesky/cholesky.hpp"
#include <iostream>
#include <stdexcept>

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

    std::cout << "Matrix A':\n";
    A.t().consolePrint();

    std::cout << "Positively defined matrix A:\n";
    A =  A.t() * A ;
    A.consolePrint();
    
    try{
        Sq_Matrix L;
        chol(A, L);
        std::cout << "Matrix L:\n";
        L.consolePrint();

        std::cout << "Matrix LL':\n";
        (L*L.t()).consolePrint();
    } catch (std::exception& e){
        std::cout << "ERROR: " << e.what() << std::endl;
    }
    

    return 0;
}
