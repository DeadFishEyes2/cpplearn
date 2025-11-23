#pragma once
#include "../../Matrix/Sq_Matrix.hpp"

// Computes the inverse of an upper triangular matrix U
// U: Upper triangular matrix of size n x n
// U_inv: Inverse matrix of size n x n (output)
void uinv(const Sq_Matrix& U, Sq_Matrix& U_inv);
