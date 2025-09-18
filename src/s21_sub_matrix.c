#include <s21_matrix.h>

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    if (!A || !B || !result) return S21_ERROR;
    if (s21_eq_size(A, B) == FAILURE) return S21_ERROR;

    if (s21_create_matrix(A->rows, A->columns, result) != S21_OK) return S21_ERROR;

    for (int i = 0; i < A->rows; i++) {
        if (!A->matrix[i] || !B->matrix[i]) {
            s21_remove_matrix(result);
            return S21_ERROR;
        }
        for (int j = 0; j < A->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
    }

    return S21_OK;
}
