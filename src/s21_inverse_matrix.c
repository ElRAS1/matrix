#include "s21_matrix.h"
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int status = OK;
  if (empty_matrix(A)) status = INCORRECTMATRIX;

  if (A->rows != A->columns && status != INCORRECTMATRIX) status = ERROR;

  if (status == OK) {
    s21_create_matrix(A->rows, A->columns, result);
    double det_a = 0;
    status = s21_determinant(A, &det_a);
    if (det_a == 0) {
      status = ERROR;
    }
    if (status == OK) {
      if (A->rows == 1 && A->columns == 1) {
        result->matrix[0][0] = 1.0 / det_a;
      } else {
        matrix_t temp = {0}, temp_2 = {0};
        status = s21_calc_complements(A, &temp);
        if (status == OK) {
          status = s21_transpose(&temp, &temp_2);
          s21_remove_matrix(&temp);
          if (status == OK) {
            s21_remove_matrix(result);
            s21_mult_number(&temp_2, 1.0 / det_a, result);
            s21_remove_matrix(&temp_2);
          }
        }
      }
    }
  }
  return status;
}
