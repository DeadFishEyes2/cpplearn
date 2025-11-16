#include "doolittle.hpp"
#include <stdexcept>

void doolittle(Sq_Matrix& A){
    int n = A.getNumRows();

    for (int k = 0; k < n; k++){
        for (int j = k; j < n; j++){
            float sum = 0;
            for (int i = 0; i < k; i++)
                sum += A[k][i]*A[i][j];
            A[k][j] -= sum;
        }
        if (A[k][k] == 0)
            throw std::invalid_argument("Encoutered a 0 element on the diagonal");
        if (k == n-1)
            break;
        for (int i = k+1; i < n; i++){
            float sum = 0;
            for (int j = 0; j < k; j++)
                sum += A[i][j]*A[j][k];
            A[i][k] = (A[i][k] - sum)/A[k][k];
        }
    }
}

void doolittle(const Sq_Matrix& A, Sq_Matrix& L, Sq_Matrix& U){
    int n = A.getNumRows();
    U = A;
    doolittle(U);
    L.zero(n);

    for (int i = 0; i < n; i++){
        L[i][i] = 1;
        for (int j = 0; j < i; j++){
            L[i][j] = U[i][j];
            U[i][j] = 0;
        }
    }
}