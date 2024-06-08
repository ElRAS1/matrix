#include "s21_matrix.h"
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = SUCCESS;

  if (A->columns == B->columns && A->rows == B->rows && empty_matrix(A) == 0 &&
      empty_matrix(B) == 0) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-07) {
          res = FAILURE;
        }
      }
    }
  } else {
    res = FAILURE;
  }

  return res;
}
