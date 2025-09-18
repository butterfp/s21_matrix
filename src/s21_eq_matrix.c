#include <s21_matrix.h>


int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    if (s21_eq_size(A, B) == FAILURE) return FAILURE;  

    for (int i = 0; i < A->rows; ++i) {
        if (!A->matrix[i] || !B->matrix[i]) return FAILURE;
        for (int j = 0; j < A->columns; ++j) {
            double da = A->matrix[i][j];
            double db = B->matrix[i][j];
            if (fabs(da - db) > EPS) return FAILURE;
        }
    }
    return SUCCESS;
}
