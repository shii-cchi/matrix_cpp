#include "../s21_matrix_oop.h"
#include <gtest/gtest.h>

TEST(CreateMatrix_1, Throw) {
  EXPECT_THROW(S21Matrix matrix_a(0, 0), std::invalid_argument);
}

TEST(CreateMatrix_2, Throw) {
  EXPECT_THROW(S21Matrix matrix_a(0, 1), std::invalid_argument);
}

TEST(CreateMatrix_3, Throw) {
  EXPECT_THROW(S21Matrix matrix_a(1, 0), std::invalid_argument);
}

TEST(EqMatrix_1, True) {
  S21Matrix matrix_a(3, 3);
  S21Matrix matrix_b(3, 3);
  ASSERT_TRUE(matrix_a == matrix_b);
}

TEST(EqMatrix_2, False) {
  S21Matrix matrix_a(3, 3);
  S21Matrix matrix_b(2, 3);
  ASSERT_FALSE(matrix_a == matrix_b);
}

TEST(EqMatrix_3, False) {
  S21Matrix matrix_a(3, 3);
  S21Matrix matrix_b(3, 2);
  ASSERT_FALSE(matrix_a == matrix_b);
}

TEST(EqMatrix_4, True) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);

  matrix_a(0, 0) = 1;
  matrix_b(0, 0) = 1;

  ASSERT_TRUE(matrix_a == matrix_b);
}

TEST(EqMatrix_5, FALSE) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);

  matrix_a(0, 0) = 1;
  matrix_b(0, 0) = 2;

  ASSERT_FALSE(matrix_a == matrix_b);
}

TEST(SumMatrix_1, Throw) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(3, 2);
  EXPECT_THROW(matrix_a.SumMatrix(matrix_b), std::invalid_argument);
}

TEST(SumMatrix_2, Throw) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 3);
  EXPECT_THROW(matrix_a.SumMatrix(matrix_b), std::invalid_argument);
}

TEST(SumMatrix_3, True) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);
  S21Matrix matrix_c(2, 2);

  matrix_a(0, 0) = 7;
  matrix_b(0, 0) = 1;
  matrix_b(0, 1) = 2;
  matrix_c(0, 0) = 8;
  matrix_c(0, 1) = 2;

  matrix_a.SumMatrix(matrix_b);

  ASSERT_TRUE(matrix_a == matrix_c);
}

TEST(op_plus_1, Throw) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(3, 2);
  EXPECT_THROW(matrix_a + matrix_b, std::invalid_argument);
}

TEST(op_plus_2, Throw) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 3);
  EXPECT_THROW(matrix_a + matrix_b, std::invalid_argument);
}

TEST(op_plus_3, True) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);
  S21Matrix matrix_c(2, 2);

  matrix_a(0, 0) = 7;
  matrix_b(0, 0) = 1;
  matrix_b(0, 1) = 2;
  matrix_c(0, 0) = 8;
  matrix_c(0, 1) = 2;

  matrix_a + matrix_b;

  ASSERT_TRUE(matrix_a == matrix_c);
}

TEST(SubMatrix_1, Throw) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(3, 2);
  EXPECT_THROW(matrix_a.SubMatrix(matrix_b), std::invalid_argument);
}

TEST(SubMatrix_2, Throw) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 3);
  EXPECT_THROW(matrix_a.SubMatrix(matrix_b), std::invalid_argument);
}

TEST(SubMatrix_3, True) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);
  S21Matrix matrix_c(2, 2);

  matrix_a(0, 0) = 7;
  matrix_b(0, 0) = 1;
  matrix_b(0, 1) = 2;
  matrix_c(0, 0) = 6;
  matrix_c(0, 1) = -2;

  matrix_a.SubMatrix(matrix_b);

  ASSERT_TRUE(matrix_a == matrix_c);
}

TEST(op_minus_1, Throw) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(3, 2);
  EXPECT_THROW(matrix_a - matrix_b, std::invalid_argument);
}

TEST(op_minus_2, Throw) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 3);
  EXPECT_THROW(matrix_a - matrix_b, std::invalid_argument);
}

TEST(op_minus_3, True) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);
  S21Matrix matrix_c(2, 2);

  matrix_a(0, 0) = 7;
  matrix_b(0, 0) = 1;
  matrix_b(0, 1) = 2;
  matrix_c(0, 0) = 6;
  matrix_c(0, 1) = -2;

  matrix_a - matrix_b;

  ASSERT_TRUE(matrix_a == matrix_c);
}

TEST(MulNumber_1, True) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);

  matrix_a(0, 0) = 1;
  matrix_a(0, 1) = 2;
  matrix_b(0, 0) = 2;
  matrix_b(0, 1) = 4;

  matrix_a.MulNumber(2);

  ASSERT_TRUE(matrix_a == matrix_b);
}

TEST(op_mul_numb_1, True) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);

  matrix_a(0, 0) = 1;
  matrix_a(0, 1) = 2;
  matrix_b(0, 0) = 2;
  matrix_b(0, 1) = 4;

  matrix_a * 2;

  ASSERT_TRUE(matrix_a == matrix_b);
}

TEST(MulMatrix_1, Throw) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(3, 3);
  EXPECT_THROW(matrix_a.MulMatrix(matrix_b), std::invalid_argument);
}

TEST(MulMatrix_2, True) {
  S21Matrix matrix_a(2, 3);
  S21Matrix matrix_b(3, 2);
  S21Matrix matrix_c(2, 2);

  matrix_a(0, 0) = 1;
  matrix_a(0, 1) = 2;
  matrix_b(0, 0) = 3;
  matrix_b(0, 1) = 4;

  matrix_c(0, 0) = 3;
  matrix_c(0, 1) = 4;

  matrix_a.MulMatrix(matrix_b);

  ASSERT_TRUE(matrix_a == matrix_c);
}

TEST(op_mul_matrix_1, Throw) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(3, 3);
  EXPECT_THROW(matrix_a * matrix_b, std::invalid_argument);
}

TEST(op_mul_matrix_2, True) {
  S21Matrix matrix_a(2, 3);
  S21Matrix matrix_b(3, 2);
  S21Matrix matrix_c(2, 2);

  matrix_a(0, 0) = 1;
  matrix_a(0, 1) = 2;
  matrix_b(0, 0) = 3;
  matrix_b(0, 1) = 4;

  matrix_c(0, 0) = 3;
  matrix_c(0, 1) = 4;

  matrix_a * matrix_b;

  ASSERT_TRUE(matrix_a == matrix_c);
}

TEST(Transpose_1, True) {
  S21Matrix matrix_a(2, 3);
  S21Matrix matrix_b(3, 2);

  matrix_a(0, 0) = 1;
  matrix_a(0, 1) = 2;
  matrix_a(0, 2) = 3;

  matrix_b(0, 0) = 1;
  matrix_b(1, 0) = 2;
  matrix_b(2, 0) = 3;

  S21Matrix matrix_c = matrix_a.Transpose();

  ASSERT_TRUE(matrix_b == matrix_c);
}

TEST(Determinant_1, True) {
  S21Matrix matrix_a(2, 2);

  matrix_a(0, 0) = 1;
  matrix_a(0, 1) = 2;
  matrix_a(1, 0) = 3;
  matrix_a(1, 1) = 4;

  ASSERT_TRUE(matrix_a.Determinant() == -2);
}

TEST(Determinant_2, True) {
  S21Matrix matrix_a(1, 1);

  matrix_a(0, 0) = 7;

  ASSERT_TRUE(matrix_a.Determinant() == 7);
}

TEST(Determinant_3, True) {
  S21Matrix matrix_a(3, 3);

  matrix_a(0, 0) = 1;
  matrix_a(0, 1) = 2;
  matrix_a(0, 2) = 2;
  matrix_a(1, 0) = 3;
  matrix_a(1, 1) = 4;
  matrix_a(1, 2) = 4;
  matrix_a(2, 0) = 4;
  matrix_a(2, 1) = 5;
  matrix_a(2, 2) = 6;

  ASSERT_TRUE(matrix_a.Determinant() == -2);
}

TEST(Determinant_4, Throw) {
  S21Matrix matrix_a(2, 3);

  EXPECT_THROW(matrix_a.Determinant(), std::invalid_argument);
}

TEST(CalcComplements_1, Throw) {
  S21Matrix matrix_a(2, 3);

  EXPECT_THROW(matrix_a.CalcComplements(), std::invalid_argument);
}

TEST(CalcComplements_2, Throw) {
  S21Matrix matrix_a(1, 1);

  EXPECT_THROW(matrix_a.CalcComplements(), std::invalid_argument);
}

TEST(CalcComplements_3, True) {
  S21Matrix matrix_a(3, 3);
  S21Matrix matrix_b(3, 3);

  matrix_a(0, 0) = 1;
  matrix_a(0, 1) = 2;
  matrix_a(0, 2) = 3;
  matrix_a(1, 0) = 0;
  matrix_a(1, 1) = 4;
  matrix_a(1, 2) = 2;
  matrix_a(2, 0) = 5;
  matrix_a(2, 1) = 2;
  matrix_a(2, 2) = 1;

  matrix_b(0, 0) = 0;
  matrix_b(0, 1) = 10;
  matrix_b(0, 2) = -20;
  matrix_b(1, 0) = 4;
  matrix_b(1, 1) = -14;
  matrix_b(1, 2) = 8;
  matrix_b(2, 0) = -8;
  matrix_b(2, 1) = -2;
  matrix_b(2, 2) = 4;

  ASSERT_TRUE(matrix_b == matrix_a.CalcComplements());
}

TEST(InverseMatrix_1, Throw) {
  S21Matrix matrix_a(2, 3);

  EXPECT_THROW(matrix_a.InverseMatrix(), std::invalid_argument);
}

TEST(InverseMatrix_2, Throw) {
  S21Matrix matrix_a(2, 2);

  EXPECT_THROW(matrix_a.InverseMatrix(), std::invalid_argument);
}

TEST(InverseMatrix_3, True) {
  S21Matrix matrix_a(3, 3);
  S21Matrix matrix_b(3, 3);

  matrix_a(0, 0) = 2;
  matrix_a(0, 1) = 5;
  matrix_a(0, 2) = 7;
  matrix_a(1, 0) = 6;
  matrix_a(1, 1) = 3;
  matrix_a(1, 2) = 4;
  matrix_a(2, 0) = 5;
  matrix_a(2, 1) = -2;
  matrix_a(2, 2) = -3;

  matrix_b(0, 0) = 1;
  matrix_b(0, 1) = -1;
  matrix_b(0, 2) = 1;
  matrix_b(1, 0) = -38;
  matrix_b(1, 1) = 41;
  matrix_b(1, 2) = -34;
  matrix_b(2, 0) = 27;
  matrix_b(2, 1) = -29;
  matrix_b(2, 2) = 24;

  ASSERT_TRUE(matrix_b == matrix_a.InverseMatrix());
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

