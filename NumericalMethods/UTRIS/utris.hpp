#pragma once
#include "../../Matrix/Sq_Matrix.hpp"

// Solves the upper triangular system Ux = b
// U: Upper triangular matrix of size n x n
// b: Right-hand side vector of size n
// x: Solution vector of size n (output)
void utris(const Sq_Matrix& U, const float* b, float* x);
