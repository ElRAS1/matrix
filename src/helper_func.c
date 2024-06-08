#include "s21_matrix.h"

// void init_matrix(matrix_t *A, int shift) {
//   int x = shift;
//   for (int i = 0; i < A->rows; i++) {
//     for (int j = 0; j < A->columns; j++) {
//       A->matrix[i][j] = x;
//       x += 2;
//     }
//   }
// }
// void print_matrix(matrix_t *A) {
//   for (int i = 0; i < A->rows; i++) {
//     for (int j = 0; j < A->columns; j++) {
//       printf("%lf ", A->matrix[i][j]);
//     }
//     printf("\n");
//   }
// }

int empty_matrix(matrix_t *matrix) {
  int res = 0;
  if (matrix == NULL || matrix->matrix == NULL || matrix->rows <= 0 ||
      matrix->columns <= 0) {
    res = 1;
  }
  return res;
}

int minor_matrix(matrix_t *A, int row, int column, matrix_t *result) {
  int res = s21_create_matrix(A->rows - 1, A->columns - 1, result);

  if (!res) {
    for (int i = 0, x = 0; i < A->rows; i++) {
      if (i != row) {
        for (int j = 0, y = 0; j < A->columns; j++) {
          if (j != column) {
            result->matrix[x][y] = A->matrix[i][j];
            y++;
          }
        }
        x++;
      }
    }
  }

  return res;
}
