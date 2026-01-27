#include "utris.hpp"

void utris(const Sq_Matrix& U, const float* b, float* x) {
    int n = U.getNumRows();

    // Backward substitution
    for (int i = n - 1; i >= 0; --i) {
        float sum = 0.0f;
        for (int j = i + 1; j < n; ++j) {
            sum += U[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / U[i][i];
    }
}
