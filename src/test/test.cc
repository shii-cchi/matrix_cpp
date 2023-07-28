#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

TEST(CreateMatrix_1, Throw) {
  EXPECT_THROW(S21Matrix matrix_a(0, 0), std::invalid_argument);
}

TEST(CreateMatrix_2, Throw) {
  EXPECT_THROW(S21Matrix matrix_a(0, 1), std::invalid_argument);
}

TEST(CreateMatrix_3, Throw) {
  EXPECT_THROW(S21Matrix matrix_a(1, 0), std::invalid_argument);
}

TEST(CreateMatrix_4, True) {
  S21Matrix matrix_a(1, 1);
  matrix_a(0, 0) = 7;

  S21Matrix matrix_b(matrix_a);
  S21Matrix matrix_c(std::move(matrix_a));

  ASSERT_TRUE(matrix_b == matrix_c);
}

TEST(EqMatrix_1, True) {
  S21Matrix matrix_a;
  S21Matrix matrix_b;
  ASSERT_TRUE(matrix_a == matrix_b);
}

TEST(EqMatrix_2, False) {
  S21Matrix matrix_a(3, 3);
  S21Matrix matrix_b(2, 3);
  ASSERT_FALSE(matrix_a == matrix_b);
}

TEST(EqMatrix_3, True) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);

  matrix_a(0, 0) = 1;
  matrix_b(0, 0) = 1;

  ASSERT_TRUE(matrix_a == matrix_b);
}

TEST(EqMatrix_4, False) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);

  matrix_a(0, 0) = 1;
  matrix_b(0, 0) = 2;

  ASSERT_FALSE(matrix_a == matrix_b);
}

TEST(SumMatrix_1, Throw) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(3, 2);
  EXPECT_THROW(matrix_a += matrix_b, std::invalid_argument);
}

TEST(SumMatrix_2, Throw) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 3);
  EXPECT_THROW(matrix_a += matrix_b, std::invalid_argument);
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

  ASSERT_TRUE((matrix_a += matrix_b) == matrix_c);
}

TEST(SumMatrix_4, True) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);
  S21Matrix matrix_c(2, 2);

  matrix_a(0, 0) = 7;
  matrix_b(0, 0) = 1;
  matrix_b(0, 1) = 2;
  matrix_c(0, 0) = 8;
  matrix_c(0, 1) = 2;

  ASSERT_TRUE((matrix_a + matrix_b) == matrix_c);
}

TEST(SumMatrix_5, Throw) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 3);
  EXPECT_THROW(matrix_a + matrix_b, std::invalid_argument);
}

TEST(SubMatrix_1, Throw) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(3, 2);
  EXPECT_THROW(matrix_a -= matrix_b, std::invalid_argument);
}

TEST(SubMatrix_2, Throw) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 3);
  EXPECT_THROW(matrix_a -= matrix_b, std::invalid_argument);
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

  ASSERT_TRUE((matrix_a -= matrix_b) == matrix_c);
}

TEST(SubMatrix_4, True) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);
  S21Matrix matrix_c(2, 2);

  matrix_a(0, 0) = 7;
  matrix_b(0, 0) = 1;
  matrix_b(0, 1) = 2;
  matrix_c(0, 0) = 6;
  matrix_c(0, 1) = -2;

  ASSERT_TRUE((matrix_a - matrix_b) == matrix_c);
}

TEST(SubMatrix_5, Throw) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 3);
  EXPECT_THROW(matrix_a - matrix_b, std::invalid_argument);
}

TEST(MulNumber_1, True) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);

  matrix_a(0, 0) = 1;
  matrix_a(0, 1) = 2;
  matrix_b(0, 0) = 2;
  matrix_b(0, 1) = 4;

  ASSERT_TRUE((matrix_a *= 2) == matrix_b);
}

TEST(MulNumber_2, True) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);

  matrix_a(0, 0) = 1;
  matrix_a(0, 1) = 2;
  matrix_b(0, 0) = 2;
  matrix_b(0, 1) = 4;

  ASSERT_TRUE(matrix_a * 2 == matrix_b);
}

TEST(MulMatrix_1, Throw) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(3, 3);
  EXPECT_THROW(matrix_a *= matrix_b, std::invalid_argument);
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

  ASSERT_TRUE((matrix_a *= matrix_b) == matrix_c);
}

TEST(MulMatrix_3, Throw) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(3, 3);
  EXPECT_THROW(matrix_a * matrix_b, std::invalid_argument);
}

TEST(MulMatrix_4, True) {
  S21Matrix matrix_a(2, 3);
  S21Matrix matrix_b(3, 2);
  S21Matrix matrix_c(2, 2);

  matrix_a(0, 0) = 1;
  matrix_a(0, 1) = 2;
  matrix_b(0, 0) = 3;
  matrix_b(0, 1) = 4;

  matrix_c(0, 0) = 3;
  matrix_c(0, 1) = 4;

  ASSERT_TRUE(matrix_a * matrix_b == matrix_c);
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

TEST(InverseMatrix_4, TRUE) {
  S21Matrix matrix_a(1, 1);
  matrix_a(0, 0) = 5;

  ASSERT_TRUE(matrix_a.InverseMatrix()(0, 0) == 0.2);
}

TEST(op_bracket_1, Throw) {
  S21Matrix matrix_a(2, 2);

  EXPECT_THROW(matrix_a(-1, 1), std::invalid_argument);
}

TEST(op_bracket_2, Throw) {
  S21Matrix matrix_a(2, 2);

  EXPECT_THROW(matrix_a(1, -1), std::invalid_argument);
}

TEST(op_bracket_3, Throw) {
  S21Matrix matrix_a(2, 2);

  EXPECT_THROW(matrix_a(2, 1), std::invalid_argument);
}

TEST(op_bracket_4, Throw) {
  S21Matrix matrix_a(2, 2);

  EXPECT_THROW(matrix_a(1, 2), std::invalid_argument);
}

TEST(op_copy, TRUE) {
  S21Matrix matrix_a(2, 2);
  matrix_a(0, 0) = 2;
  matrix_a(0, 1) = 5;
  matrix_a(1, 0) = 6;
  matrix_a(1, 1) = 3;

  S21Matrix matrix_b(2, 2);
  matrix_b(0, 0) = 2;
  matrix_b(0, 1) = 5;
  matrix_b(1, 0) = 6;
  matrix_b(1, 1) = 3;

  S21Matrix matrix_c(2, 2);
  matrix_c(0, 0) = 2;
  matrix_c(0, 1) = 5;
  matrix_c(1, 0) = 6;
  matrix_c(1, 1) = 3;

  matrix_a = matrix_b;

  ASSERT_TRUE(matrix_a == matrix_c);
}

TEST(GetRows_1, True) {
  S21Matrix matrix_a(2, 3);

  ASSERT_TRUE(matrix_a.GetRows() == 2);
}

TEST(GetCols_1, True) {
  S21Matrix matrix_a(2, 3);

  ASSERT_TRUE(matrix_a.GetCols() == 3);
}

TEST(SetRows_1, True) {
  S21Matrix matrix_a(3, 3);
  matrix_a(0, 0) = 2;
  matrix_a(0, 1) = 5;
  matrix_a(0, 2) = 7;
  matrix_a(1, 0) = 6;
  matrix_a(1, 1) = 3;
  matrix_a(1, 2) = 4;
  matrix_a(2, 0) = 5;
  matrix_a(2, 1) = -2;
  matrix_a(2, 2) = -3;

  S21Matrix matrix_b(2, 3);
  matrix_b(0, 0) = 2;
  matrix_b(0, 1) = 5;
  matrix_b(0, 2) = 7;
  matrix_b(1, 0) = 6;
  matrix_b(1, 1) = 3;
  matrix_b(1, 2) = 4;

  matrix_a.SetRows(2);

  ASSERT_TRUE(matrix_a == matrix_b);
}

TEST(SetRows_2, True) {
  S21Matrix matrix_a(3, 3);
  matrix_a(0, 0) = 2;
  matrix_a(0, 1) = 5;
  matrix_a(0, 2) = 7;
  matrix_a(1, 0) = 6;
  matrix_a(1, 1) = 3;
  matrix_a(1, 2) = 4;
  matrix_a(2, 0) = 5;
  matrix_a(2, 1) = -2;
  matrix_a(2, 2) = -3;

  S21Matrix matrix_b(4, 3);
  matrix_b(0, 0) = 2;
  matrix_b(0, 1) = 5;
  matrix_b(0, 2) = 7;
  matrix_b(1, 0) = 6;
  matrix_b(1, 1) = 3;
  matrix_b(1, 2) = 4;
  matrix_b(2, 0) = 5;
  matrix_b(2, 1) = -2;
  matrix_b(2, 2) = -3;
  matrix_b(3, 0) = 0;
  matrix_b(3, 1) = 0;
  matrix_b(3, 2) = 0;

  matrix_a.SetRows(4);

  ASSERT_TRUE(matrix_a == matrix_b);
}

TEST(SetRows_3, Throw) {
  S21Matrix matrix_a(2, 2);

  EXPECT_THROW(matrix_a.SetRows(-1), std::invalid_argument);
}

TEST(SetRows_4, TRUE) {
  S21Matrix matrix_a(2, 2);
  matrix_a(0, 0) = 2;
  matrix_a(0, 1) = 5;
  matrix_a(1, 0) = 6;
  matrix_a(1, 1) = 3;

  S21Matrix matrix_b(2, 2);
  matrix_b(0, 0) = 2;
  matrix_b(0, 1) = 5;
  matrix_b(1, 0) = 6;
  matrix_b(1, 1) = 3;

  matrix_a.SetRows(2);

  ASSERT_TRUE(matrix_a == matrix_b);
}

TEST(SetCols_1, True) {
  S21Matrix matrix_a(3, 3);
  matrix_a(0, 0) = 2;
  matrix_a(0, 1) = 5;
  matrix_a(0, 2) = 7;
  matrix_a(1, 0) = 6;
  matrix_a(1, 1) = 3;
  matrix_a(1, 2) = 4;
  matrix_a(2, 0) = 5;
  matrix_a(2, 1) = -2;
  matrix_a(2, 2) = -3;

  S21Matrix matrix_b(3, 2);
  matrix_b(0, 0) = 2;
  matrix_b(0, 1) = 5;
  matrix_b(1, 0) = 6;
  matrix_b(1, 1) = 3;
  matrix_b(2, 0) = 5;
  matrix_b(2, 1) = -2;

  matrix_a.SetCols(2);

  ASSERT_TRUE(matrix_a == matrix_b);
}

TEST(SetCols_2, True) {
  S21Matrix matrix_a(3, 3);
  matrix_a(0, 0) = 2;
  matrix_a(0, 1) = 5;
  matrix_a(0, 2) = 7;
  matrix_a(1, 0) = 6;
  matrix_a(1, 1) = 3;
  matrix_a(1, 2) = 4;
  matrix_a(2, 0) = 5;
  matrix_a(2, 1) = -2;
  matrix_a(2, 2) = -3;

  S21Matrix matrix_b(3, 4);
  matrix_b(0, 0) = 2;
  matrix_b(0, 1) = 5;
  matrix_b(0, 2) = 7;
  matrix_b(0, 3) = 0;
  matrix_b(1, 0) = 6;
  matrix_b(1, 1) = 3;
  matrix_b(1, 2) = 4;
  matrix_b(1, 3) = 0;
  matrix_b(2, 0) = 5;
  matrix_b(2, 1) = -2;
  matrix_b(2, 2) = -3;
  matrix_b(2, 3) = 0;

  matrix_a.SetCols(4);

  ASSERT_TRUE(matrix_a == matrix_b);
}

TEST(SetCols_3, Throw) {
  S21Matrix matrix_a(2, 2);

  EXPECT_THROW(matrix_a.SetCols(-1), std::invalid_argument);
}

TEST(SetCols_4, TRUE) {
  S21Matrix matrix_a(2, 2);
  matrix_a(0, 0) = 2;
  matrix_a(0, 1) = 5;
  matrix_a(1, 0) = 6;
  matrix_a(1, 1) = 3;

  S21Matrix matrix_b(2, 2);
  matrix_b(0, 0) = 2;
  matrix_b(0, 1) = 5;
  matrix_b(1, 0) = 6;
  matrix_b(1, 1) = 3;

  matrix_a.SetCols(2);

  ASSERT_TRUE(matrix_a == matrix_b);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
