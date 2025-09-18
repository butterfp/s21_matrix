#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
    if (!result || rows <= 0 || columns <= 0) {
        if (result) {
            result->matrix = NULL;
            result->rows = 0;
            result->columns = 0;
        }
        return S21_ERROR;
    }

    result->rows = rows;
    result->columns = columns;

    result->matrix = calloc(rows, sizeof(double *));
    if (!result->matrix) return S21_ERROR;

    for (int i = 0; i < rows; i++) {
        result->matrix[i] = calloc(columns, sizeof(double));
        if (!result->matrix[i]) {
            for (int j = 0; j < i; j++) {
                free(result->matrix[j]);
            }
            free(result->matrix);
            result->matrix = NULL;
            result->rows = 0;
            result->columns = 0;
            return S21_ERROR;
        }
    }

    return S21_OK;
}

void s21_remove_matrix(matrix_t *A) {
    if (!A || !A->matrix) return;

    for (int i = 0; i < A->rows; i++) {
        free(A->matrix[i]);
    }
    free(A->matrix);

    A->matrix = NULL;
    A->rows = 0;
    A->columns = 0;
}
