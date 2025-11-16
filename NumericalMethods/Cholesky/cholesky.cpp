#include "cholesky.hpp"
#include <stdexcept>
#include <math.h>

void chol(Sq_Matrix& A){
    if (A[1][1] <= 0)
        throw std::invalid_argument("Input matrix is not positively defined");

    int n = A.getNumRows();
    float sum;
    for (int k = 0; k < n; k++){

        //Diagonal element on row and column k
        sum = 0;
        for (int j = 0; j < k; j++){
            sum += A[k][j]*A[k][j];
        }
        A[k][k] = sqrt(A[k][k] - sum);
        if (A[k][k] < 0)
            throw std::invalid_argument("Input matrix is not positively defined");
        else if (A[k][k] == 0)
            throw std::invalid_argument("One of the elements on L's diagonal is 0");
        
        //Elements under the diagonal, row i, column k
        for (int i = k+1; i < n; i++){
            sum = 0;
            for (int j = 0; j < k; j++){
                sum += A[i][j]*A[k][j];
            }
            A[i][k] = (A[i][k] - sum)/A[k][k];
        }
    }

    //Filling the input matrix with 0s on the upper right corner so it turns into a lower triangular matrix
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            A[i][j] = 0;
        }
    }
}

void chol(const Sq_Matrix& A, Sq_Matrix& L){
    L = A;
    chol(L);
}