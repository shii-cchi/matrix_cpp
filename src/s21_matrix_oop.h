#ifndef CPP1_S21_MATRIXPLUS_S21_MATRIX_OOP_H_
#define CPP1_S21_MATRIXPLUS_S21_MATRIX_OOP_H_

#include <cmath>
#include <stdexcept>

enum class SumOrSubOperation { kSum = 1, kSub = -1 };

class S21Matrix {
 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix &other);
  S21Matrix(S21Matrix &&other);
  ~S21Matrix();

  bool EqMatrix(const S21Matrix &other);
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix &other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  S21Matrix operator+(const S21Matrix &other) const;
  S21Matrix operator-(const S21Matrix &other) const;
  S21Matrix operator*(const double &num) const;
  S21Matrix operator*(const S21Matrix &other) const;
  bool operator==(const S21Matrix &other);
  S21Matrix &operator=(const S21Matrix &other);
  S21Matrix &operator+=(const S21Matrix &other);
  S21Matrix &operator-=(const S21Matrix &other);
  S21Matrix &operator*=(const double &num);
  S21Matrix &operator*=(const S21Matrix &other);
  double &operator()(int row, int col) const;

  int GetRows() const;
  int GetCols() const;
  void SetRows(int rows);
  void SetCols(int cols);

 private:
  int rows_, cols_;
  double **matrix_;

  void AllocateMatrix();
  void FillWithZeros();
  void CopyMatrix(const S21Matrix &other);
  void ClearMatrix();

  void SumSubMatrix(const S21Matrix &other, SumOrSubOperation op);
  S21Matrix GetMinorMatrix(int row, int col);
};

#endif  // CPP1_S21_MATRIXPLUS_S21_MATRIX_OOP_H_