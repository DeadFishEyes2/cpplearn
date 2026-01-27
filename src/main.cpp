#include "Matrix.hpp"
#include "gauss.hpp"
#include "crout.hpp"
#include "doolittle.hpp"
#include "cholesky.hpp"
#include "utris.hpp"
#include "ltris.hpp"
#include "linv.hpp"
#include "uinv.hpp"
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
        
        float b[] = {1, 2, 3};
        float x[] = {0, 0, 0};
        
        Sq_Matrix L_inv(3);
        linv(L, L_inv);
        // A = L * L'
        // A * x = b
        // L * L' * x = b   
        // L' * x = L_inv * b   
        float* L_inv_b = L_inv * b;
        utris(L.t(), L_inv_b, x);

        std::cout << "Solution x:\n";
        for (int i = 0; i < 3; i++) {
            std::cout << "x[" << i << "]: " << x[i] << std::endl;
        }
        delete[] L_inv_b;

        float* Res = A * x;
        for (int i = 0; i < 3; i++) {
            std::cout << "Res[" << i << "]: " << Res[i] << " (expected " << b[i] << ")" << std::endl;
        }
        delete[] Res;

    } catch (std::exception& e){
        std::cout << "ERROR: " << e.what() << std::endl;
    }

    
    

    return 0;
}
