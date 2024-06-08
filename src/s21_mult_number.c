#include "s21_matrix.h"
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int res = INCORRECTMATRIX;
  if (empty_matrix(A) == 0) {
    res = s21_create_matrix(A->rows, A->columns, result);
    if (!res) {
      for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] * number;
        }
      }
    }
  }

  return res;
}
