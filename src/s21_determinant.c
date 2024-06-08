#include "s21_matrix.h"
int s21_determinant(matrix_t *A, double *result) {
  int err = empty_matrix(A);
  *result = 0;
  double det = 0;
  matrix_t matrix_det;
  if (result == NULL) err = INCORRECTMATRIX;
  if (err == 0) {
    if (A->rows != A->columns) {
      err = ERROR;
    } else {
      if (A->rows == 1) {
        *result = A->matrix[0][0];
      } else {
        for (int j = 0; j < A->rows; j++) {
          minor_matrix(A, 0, j, &matrix_det);
          err = s21_determinant(&matrix_det, &det);
          *result += A->matrix[0][j] * pow(-1, j) * det;
          s21_remove_matrix(&matrix_det);
        }
      }
    }
  }
  return err;
}
