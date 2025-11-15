#include "../Matrix/Matrix.hpp"

void gaussianElimination(Sq_Matrix& A);

void gaussianElimination(const Sq_Matrix& A, Sq_Matrix& U);

void gaussianElimination(const Sq_Matrix& A, Sq_Matrix& U, Sq_Matrix& M);

void gaussianEliminationPartialPermutation(Sq_Matrix& A, int* &p);

void gaussianEliminationPartialPermutation(const Sq_Matrix& A, Sq_Matrix& U, int* &p);

void gaussianEliminationPartialPermutation(const Sq_Matrix& A, Sq_Matrix& U, Sq_Matrix& M, int* &p);

void gaussianEliminationCompletePermutation(Sq_Matrix& A, int* &p, int* &q);

void gaussianEliminationCompletePermutation(const Sq_Matrix& A, Sq_Matrix& U, int* &p, int* &q);

void gaussianEliminationCompletePermutation(const Sq_Matrix& A, Sq_Matrix& U, Sq_Matrix& M, int* &p, int* &q);

Sq_Matrix* getMultiplicators(const Sq_Matrix& A);