#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res = OK;
  if (empty_matrix(A)) res = INCORRECTMATRIX;
  if (A->rows != A->columns) res = ERROR;
  if (res != ERROR && res != INCORRECTMATRIX) {
    res = s21_create_matrix(A->rows, A->columns, result);
  }
  if (A->rows == 1 && res == OK) {
    result->matrix[0][0] = 1;
  } else if (res == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        double det = 0;
        matrix_t minor_m;
        minor_matrix(A, i, j, &minor_m);
        s21_determinant(&minor_m, &det);
        s21_remove_matrix(&minor_m);
        result->matrix[i][j] = powf(-1, i + j) * det;
      }
    }
  }
  return res;
}
