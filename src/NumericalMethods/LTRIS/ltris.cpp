#include "ltris.hpp"

void ltris(const Sq_Matrix& L, const float* b, float* x) {
    int n = L.getNumRows();

    // Forward substitution
    for (int i = 0; i < n; ++i) {
        float sum = 0.0f;
        for (int j = 0; j < i; ++j) {
            sum += L[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / L[i][i];
    }
}
