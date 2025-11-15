#include "nm.hpp"
#include "assert.h"
#include <stdexcept>

void gaussianEliminate(Sq_Matrix& A){
    int n = A.getNumCols();

    for (int k = 0; k < n-1; k++){
        if (A[k][k] == 0)
            throw std::invalid_argument("Element on the diagonal is 0");

        for (int i = k+1; i < n; i++){
            A[i][k] = A[i][k]/A[k][k];
        }
        for (int i = k+1; i < n; i++){
            for (int j = k+1; j < n; j++){
                A[i][j] = A[i][j] - A[i][k]*A[k][j];
            }
        }
    }
}

void gaussianEliminate(const Sq_Matrix& A, Sq_Matrix& U){
    U = A;
    gaussianEliminate(U);
}

void separateUM(Sq_Matrix& U, Sq_Matrix& M){
    int n = U.getNumCols();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            U[i][j] = 0;
        }
    }
    
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            M[i][j] = 0;
        }
    }
}

void gaussianEliminate(const Sq_Matrix& A, Sq_Matrix& U, Sq_Matrix& M){
    U = A;
    gaussianEliminate(U);
    M = U;
    separateUM(U, M);
}

void gaussianEliminatePartialPermutation(Sq_Matrix &A, int* &p){
    int n = A.getNumRows();
    
    if (p != nullptr){
        delete[] p;
    }
    p = new int[n-1];

    for (int k = 0; k < n-1; k++){
        p[k] = A.getMaxOnColumn(k, k);
        A.swapRows(p[k], k);

        if (A[k][k] == 0){
            throw std::invalid_argument("All elements under and including the diagonal are 0 for one of the columns");
        }

        for (int i = k+1; i < n; i++){
            A[i][k] = A[i][k]/A[k][k];
        }
        for (int i = k+1; i < n; i++){
            for (int j = k+1; j < n; j++){
                A[i][j] = A[i][j] - A[i][k]*A[k][j];
            }
        }
    }
}

void gaussianEliminatePartialPermutation(const Sq_Matrix& A, Sq_Matrix& U, int* &p){
    U = A;
    gaussianEliminatePartialPermutation(U, p);
}

void gaussianEliminatePartialPermutation(const Sq_Matrix& A, Sq_Matrix& U, Sq_Matrix& M, int* &p){
    U = A;
    gaussianEliminatePartialPermutation(U,p);
    M = U;
    separateUM(U, M);
}

Sq_Matrix* getMultiplicators(const Sq_Matrix& A){
    int n = A.getNumCols();
    Sq_Matrix* M = new Sq_Matrix[n-1];
    for (int k = 0; k < n-1; k++){
        M[k].eye(n);

        for (int i = k+1; i < n; i++){
            M[k][i][k] = -A[i][k];
        }
    }
    return M;
}