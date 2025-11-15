#include "../Matrix/Matrix.hpp"

void gaussianEliminate(Sq_Matrix& A);

void gaussianEliminate(const Sq_Matrix& A, Sq_Matrix& U);

void gaussianEliminate(const Sq_Matrix& A, Sq_Matrix& U, Sq_Matrix& M);

void gaussianEliminatePartialPermutation(Sq_Matrix& A, int* &p);

void gaussianEliminatePartialPermutation(const Sq_Matrix& A, Sq_Matrix& U, int* &p);

void gaussianEliminatePartialPermutation(const Sq_Matrix& A, Sq_Matrix& U, Sq_Matrix& M, int* &p);

Sq_Matrix* getMultiplicators(const Sq_Matrix& A);