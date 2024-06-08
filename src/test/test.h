#ifndef SRC_TEST
#define SRC_TEST

#include <check.h>
#include <time.h>
// #include <unistd.h>

#include "../s21_matrix.h"
Suite *suite_create_matrix(void);       // 100 %
Suite *suite_sum_matrix(void);          // 100 %
Suite *suite_transpose_matrix(void);    // 100 %
Suite *suite_mult_matrix(void);         // 100 %
Suite *suite_mult_number_matrix(void);  // 100%
Suite *suite_eq_matrix(void);           // 100 %
Suite *suite_sub_matrix(void);          // 100 %
Suite *suite_determinant(void);         // 100 %
Suite *suite_calc_complements(void);    // 100 %
Suite *suite_inverse_matrix(void);      // 100 %

void run_test(void);
void run_testcase(Suite *testcase);
double get_rand(double min, double max);

#endif
