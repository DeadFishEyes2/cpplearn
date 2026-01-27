#include "linv.hpp"
#include "../LTRIS/ltris.hpp"

void linv(const Sq_Matrix& L, Sq_Matrix& L_inv) {
    int n = L.getNumRows();
    
    float* e = new float[n];
    float* col = new float[n];

    for (int j = 0; j < n; ++j) {
        // Create e_j
        for (int i = 0; i < n; ++i) {
            e[i] = (i == j) ? 1.0f : 0.0f;
        }

        // Solve L * col = e_j
        ltris(L, e, col);

        // Copy col to L_inv column j
        for (int i = 0; i < n; ++i) {
            L_inv[i][j] = col[i];
        }
    }

    delete[] e;
    delete[] col;
}
