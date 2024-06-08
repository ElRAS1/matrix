#ifndef SRC_S21_MATRIX_H
#define SRC_S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0
#define OK 0
#define INCORRECTMATRIX 1
#define ERROR 2

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

// создание и удаление матрицы.
int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

// сравнение матриц
int s21_eq_matrix(matrix_t *A, matrix_t *B);

// сумма и разность матриц
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// произведение матриц и умножение матрицы на число
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// минор матрицы и матрица алгебраических дополнений
int s21_calc_complements(matrix_t *A, matrix_t *result);

// транспонирование матрицы
int s21_transpose(matrix_t *A, matrix_t *result);

// определитель матрицы
int s21_determinant(matrix_t *A, double *result);

// обратная матрица
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// support func
void print_matrix(matrix_t *A);
void init_matrix(matrix_t *A, int shift);
int empty_matrix(matrix_t *matrix);
int minor_matrix(matrix_t *A, int row, int column, matrix_t *result);

#endif