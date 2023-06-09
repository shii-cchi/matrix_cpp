#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_

#include <cmath>
#include <iostream>
#include <stdexcept>

#define EPS 1e-07

#define PLUS 1
#define MINUS -1

enum class Operation { Sum = 1, Sub = -1 };

class S21Matrix {
 private:
  int rows_, cols_;
  double **matrix_;

  void CreateMatrix();
  void CopyMatrix(const S21Matrix &other);

  void SumSubMatrix(const S21Matrix &other, Operation op);
  S21Matrix SplitMatrix(int row, int col);
  void ClearMatrix();

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
};

#endif  // SRC_S21_MATRIX_OOP_H_