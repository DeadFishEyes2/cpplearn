#include "../../Matrix/Matrix.hpp"

// M*A = U
void gaussianElimination(Sq_Matrix& A);
void gaussianElimination(const Sq_Matrix& A, Sq_Matrix& U);
void gaussianElimination(const Sq_Matrix& A, Sq_Matrix& U, Sq_Matrix& M);

// M*P*A = U
void gaussianEliminationPartialPermutation(Sq_Matrix& A, int* &p);
void gaussianEliminationPartialPermutation(const Sq_Matrix& A, Sq_Matrix& U, int* &p);
void gaussianEliminationPartialPermutation(const Sq_Matrix& A, Sq_Matrix& U, Sq_Matrix& M, int* &p);

// M*P*A*Q = U
void gaussianEliminationCompletePermutation(Sq_Matrix& A, int* &p, int* &q);
void gaussianEliminationCompletePermutation(const Sq_Matrix& A, Sq_Matrix& U, int* &p, int* &q);
void gaussianEliminationCompletePermutation(const Sq_Matrix& A, Sq_Matrix& U, Sq_Matrix& M, int* &p, int* &q);

Sq_Matrix* getMultiplicators(const Sq_Matrix& A);