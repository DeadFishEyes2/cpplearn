#include "crout.hpp"
#include <stdexcept>

void crout(Sq_Matrix& A){
    int n = A.getNumRows();
    if (A[0][0]){
        throw std::invalid_argument("One of the elements of L's diagonal is 0");
    }
    for (int j = 1; j < n; j++){
        A[0][j] = A[0][j]/A[0][0];
    }
    for (int k = 1; k < n; k++){
        for (int i = k; i < n; i++){
            float sum = 0;
            for (int l = 0; l < k; l++)
                sum += A[i][l]*A[l][k];
            A[i][k] = A[i][k] - sum;
        }
        if (A[k][k]){
            throw std::invalid_argument("One of the elements of L's diagonal is 0");
        }
        if (k == n-1)
            break;
        for (int j = k+1; j < n; j++){
            float sum = 0;
            for (int l = 0; l < k; l++)
                sum += A[k][l]*A[l][j];
            A[k][j] = (A[k][j] - sum)/A[k][k];
        }
    }
}

void crout(const Sq_Matrix& A, Sq_Matrix& L, Sq_Matrix& U){
    int n = A.getNumRows();
    L = A;
    crout(L);
    U.zero(n);

    for (int i = 0; i < n; i++){
        U[i][i] = 1;
        for (int j = i+1; j < n; j++){
            U[i][j] = L[i][j];
            L[i][j] = 0;
        }
    }
}