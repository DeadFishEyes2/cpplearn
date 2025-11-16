#pragma once
#include "../../Matrix/Sq_Matrix.hpp"

// Solves the lower triangular system Lx = b
// L: Lower triangular matrix of size n x n
// b: Right-hand side vector of size n
// x: Solution vector of size n (output)
void ltris(const Sq_Matrix& L, const float* b, float* x);
