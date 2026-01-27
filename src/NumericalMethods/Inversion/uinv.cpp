#include "uinv.hpp"
#include "../UTRIS/utris.hpp"

void uinv(const Sq_Matrix& U, Sq_Matrix& U_inv) {
    int n = U.getNumRows();
    
    float* e = new float[n];
    float* col = new float[n];

    for (int j = 0; j < n; ++j) {
        // Create e_j
        for (int i = 0; i < n; ++i) {
            e[i] = (i == j) ? 1.0f : 0.0f;
        }

        // Solve U * col = e_j
        utris(U, e, col);

        // Copy col to U_inv column j
        for (int i = 0; i < n; ++i) {
            U_inv[i][j] = col[i];
        }
    }

    delete[] e;
    delete[] col;
}
