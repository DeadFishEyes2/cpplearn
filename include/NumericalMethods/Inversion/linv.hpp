#pragma once
#include "../../Matrix/Sq_Matrix.hpp"

// Computes the inverse of a lower triangular matrix L
// L: Lower triangular matrix of size n x n
// L_inv: Inverse matrix of size n x n (output)
void linv(const Sq_Matrix& L, Sq_Matrix& L_inv);
