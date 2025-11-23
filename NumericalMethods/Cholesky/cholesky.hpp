#pragma once
#include "../../Matrix/Sq_Matrix.hpp"

// A = L * L'
void chol(Sq_Matrix& A);
void chol(const Sq_Matrix& A, Sq_Matrix& L);