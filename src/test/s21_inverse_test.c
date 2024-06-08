#include "test.h"
START_TEST(inverse_matrix_1) {
  matrix_t A = {0}, B = {0}, C = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  C.matrix[0][0] = 1;
  C.matrix[0][1] = -1;
  C.matrix[0][2] = 1;
  C.matrix[1][0] = -38;
  C.matrix[1][1] = 41;
  C.matrix[1][2] = -34;
  C.matrix[2][0] = 27;
  C.matrix[2][1] = -29;
  C.matrix[2][2] = 24;
  s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(s21_eq_matrix(&B, &C), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(inverse_matrix_2) {
  matrix_t A = {0}, B = {0}, C = {0};
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &C);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 4;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[1][3] = 1;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  A.matrix[2][3] = 3;
  A.matrix[3][0] = 3;
  A.matrix[3][1] = 7;
  A.matrix[3][2] = 2;
  A.matrix[3][3] = 4;
  s21_inverse_matrix(&A, &B);
  C.matrix[0][0] = -0.125;
  C.matrix[0][1] = 0.19166666;
  C.matrix[0][2] = 0.325;
  C.matrix[0][3] = -0.16666666;
  C.matrix[1][0] = -0.125;
  C.matrix[1][1] = 0.05833333;
  C.matrix[1][2] = -0.075;
  C.matrix[1][3] = 0.16666666;
  C.matrix[2][0] = 0.125;
  C.matrix[2][1] = 0.675;
  C.matrix[2][2] = 0.275;
  C.matrix[2][3] = -0.5;
  C.matrix[3][0] = 0.25;
  C.matrix[3][1] = -0.58333333;
  C.matrix[3][2] = -0.25;
  C.matrix[3][3] = 0.33333333;
  ck_assert_int_eq(s21_eq_matrix(&B, &C), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(inverse_matrix_3) {
  matrix_t A, B;
  s21_create_matrix(3, 4, &A);
  ck_assert_int_eq(s21_inverse_matrix(&A, &B), ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_matrix_4) {
  matrix_t A = {0}, B = {0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  int check = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(check, ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(inverse_matrix_5) {
  matrix_t A = {0}, B = {0};
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 5;
  int check = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(check, OK);
  ck_assert_double_eq(0.2, B.matrix[0][0]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(inverse_matrix_6) {
  matrix_t A = {0}, B = {0};
  s21_create_matrix(-2, 1, &A);
  int check = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(check, INCORRECTMATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// START_TEST(s21_inverse_1) {
//   matrix_t A, C;
//   s21_create_matrix(3, 3, &A);
//   s21_create_matrix(3, 3, &C);
//   C.matrix[0][0] = 1.0;
//   C.matrix[0][1] = -1.0;
//   C.matrix[0][2] = 1.0;
//   C.matrix[1][0] = -38.0;
//   C.matrix[1][1] = 41.0;
//   C.matrix[1][2] = -34.0;
//   C.matrix[2][0] = 27.0;
//   C.matrix[2][1] = -29.0;
//   C.matrix[2][2] = 24.0;
//   A.matrix[0][0] = 2.0;
//   A.matrix[0][1] = 5.0;
//   A.matrix[0][2] = 7.0;
//   A.matrix[1][0] = 6.0;
//   A.matrix[1][1] = 3.0;
//   A.matrix[1][2] = 4.0;
//   A.matrix[2][0] = 5.0;
//   A.matrix[2][1] = -2.0;
//   A.matrix[2][2] = -3.0;
//   matrix_t B;
//   s21_inverse_matrix(&A, &B);
//   int res = s21_eq_matrix(&B, &C);
//   ck_assert_int_eq(res, 1);
//   s21_remove_matrix(&A);
//   s21_remove_matrix(&B);
//   s21_remove_matrix(&C);
// }
// END_TEST

// START_TEST(test_one_by_one) {
//   matrix_t m = {0};
//   matrix_t result = {0};
//   int codec = s21_create_matrix(1, 1, &m);
//   if (codec) {
//     m.matrix[0][0] = 1431.12312331;
//     int code = s21_inverse_matrix(&m, &result);
//     ck_assert_int_eq(result.matrix[0][0] == (1.0 / m.matrix[0][0]), 1);
//     ck_assert_int_eq(code, OK);
//     s21_remove_matrix(&m);
//     s21_remove_matrix(&result);
//   }
// }
// END_TEST

// START_TEST(test_zero_det) {
//   matrix_t m = {0};
//   matrix_t result = {0};
//   int codec = s21_create_matrix(1, 1, &m);
//   if (codec) {
//     int code = s21_inverse_matrix(&m, &result);
//     ck_assert_int_eq(code, ERROR);
//     s21_remove_matrix(&m);
//   }
// }
// END_TEST

// START_TEST(test_incorrect) {
//   matrix_t m = {0};
//   matrix_t result = {0};
//   int code = s21_inverse_matrix(&m, &result);
//   ck_assert_int_eq(code, INCORRECTMATRIX);
// }
// END_TEST

// START_TEST(determinant) {
//   const int size = 2;
//   matrix_t m = {0};
//   s21_create_matrix(size, size, &m);
//   m.matrix[0][0] = 1;
//   m.matrix[0][1] = 1;
//   m.matrix[1][0] = 1;
//   m.matrix[1][1] = 1;

//   matrix_t result = {0};
//   int code = s21_inverse_matrix(&m, &result);
//   ck_assert_int_eq(code, ERROR);

//   s21_remove_matrix(&m);
// }
// END_TEST

// START_TEST(test_not_sqare) {
//   matrix_t m = {0};
//   matrix_t result = {0};
//   int codec = s21_create_matrix(1, 4, &m);
//   if (codec) {
//     int code = s21_inverse_matrix(&m, &result);
//     ck_assert_int_eq(code, ERROR);
//     s21_remove_matrix(&m);
//   }
// }
// END_TEST

// START_TEST(test_normal) {
//   matrix_t m = {0};
//   matrix_t expected = {0};
//   int codec1, codec2;
//   codec1 = s21_create_matrix(3, 3, &m);
//   if (codec1) codec2 = s21_create_matrix(3, 3, &expected);

//   if (codec1 && codec2) {
//     m.matrix[0][0] = 2;
//     m.matrix[0][1] = 5;
//     m.matrix[0][2] = 7;

//     m.matrix[1][0] = 6;
//     m.matrix[1][1] = 3;
//     m.matrix[1][2] = 4;

//     m.matrix[2][0] = 5;
//     m.matrix[2][1] = -2;
//     m.matrix[2][2] = -3;

//     expected.matrix[0][0] = 1;
//     expected.matrix[0][1] = -1;
//     expected.matrix[0][2] = 1;

//     expected.matrix[1][0] = -38;
//     expected.matrix[1][1] = 41;
//     expected.matrix[1][2] = -34;

//     expected.matrix[2][0] = 27;
//     expected.matrix[2][1] = -29;
//     expected.matrix[2][2] = 24;
//     matrix_t result = {0};
//     int code = s21_inverse_matrix(&m, &result);

//     ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
//     ck_assert_int_eq(code, OK);

//     s21_remove_matrix(&m);
//     s21_remove_matrix(&result);
//     s21_remove_matrix(&expected);
//   }
// }
// END_TEST

// START_TEST(inverse) {

//   const int size = 3;
//   matrix_t m = {0};
//   s21_create_matrix(size, size, &m);

//   m.matrix[0][0] = 2;
//   m.matrix[0][1] = 5;
//   m.matrix[0][2] = 7;
//   m.matrix[1][0] = 6;
//   m.matrix[1][1] = 3;
//   m.matrix[1][2] = 4;
//   m.matrix[2][0] = 5;
//   m.matrix[2][1] = -2;
//   m.matrix[2][2] = -3;

//   matrix_t res = {0};
//   s21_inverse_matrix(&m, &res);

//   matrix_t expected = {0};
//   s21_create_matrix(size, size, &expected);
//   expected.matrix[0][0] = 1;
//   expected.matrix[0][1] = -1;
//   expected.matrix[0][2] = 1;
//   expected.matrix[1][0] = -38;
//   expected.matrix[1][1] = 41;
//   expected.matrix[1][2] = -34;
//   expected.matrix[2][0] = 27;
//   expected.matrix[2][1] = -29;
//   expected.matrix[2][2] = 24;

//   ck_assert_int_eq(s21_eq_matrix(&expected, &res), SUCCESS);

//   s21_remove_matrix(&expected);
//   s21_remove_matrix(&res);
//   s21_remove_matrix(&m);
// }
// END_TEST

Suite *suite_inverse_matrix(void) {
  Suite *s = suite_create("suite_inverse_matrix");
  TCase *tc = tcase_create("case_inverse_matrix");

  //   tcase_add_test(tc, inverse);
  //   tcase_add_test(tc, s21_inverse_1);
  //   tcase_add_test(tc, determinant);

  //   tcase_add_test(tc, test_normal);
  //   tcase_add_test(tc, test_not_sqare);
  //   tcase_add_test(tc, test_zero_det);
  //   tcase_add_test(tc, test_incorrect);
  //   tcase_add_test(tc, test_one_by_one);
  tcase_add_test(tc, inverse_matrix_1);
  tcase_add_test(tc, inverse_matrix_2);
  tcase_add_test(tc, inverse_matrix_3);
  tcase_add_test(tc, inverse_matrix_4);
  tcase_add_test(tc, inverse_matrix_5);
  tcase_add_test(tc, inverse_matrix_6);
  suite_add_tcase(s, tc);
  return s;
}