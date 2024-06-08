#include "s21_matrix.h"
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int res = INCORRECTMATRIX;
  result->rows = rows;
  result->columns = columns;

  if (rows > 0 && columns > 0) {
    result->matrix = malloc(sizeof(double *) * rows);

    for (int i = 0; i < rows; ++i) {
      result->matrix[i] = malloc(columns * sizeof(double));
    }
    res = OK;
  }
  return res;
}
