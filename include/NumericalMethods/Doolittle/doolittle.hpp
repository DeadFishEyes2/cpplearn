#pragma once
#include "../../Matrix/Sq_Matrix.hpp"

void doolittle(Sq_Matrix& A);
void doolittle(const Sq_Matrix& A, Sq_Matrix& L, Sq_Matrix& U);