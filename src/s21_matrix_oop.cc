#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() {
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}

S21Matrix::S21Matrix(int rows, int cols) {
  if (rows < 1 || cols < 1) {
    throw std::invalid_argument("Rows and cols must be positive integers");
  }

  rows_ = rows;
  cols_ = cols;

  CreateMatrix();
  ClearMatrix();
}

S21Matrix::S21Matrix(const S21Matrix& other) {
  rows_ = other.rows_;
  cols_ = other.cols_;

  CreateMatrix();
  this->CopyMatrix(other);
}

S21Matrix::S21Matrix(S21Matrix&& other) {
  rows_ = other.rows_;
  cols_ = other.cols_;

  CreateMatrix();
  ClearMatrix();
  this->CopyMatrix(other);

  other.~S21Matrix();
}

S21Matrix::~S21Matrix() {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
  }

  delete[] matrix_;
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}

void S21Matrix::CreateMatrix() {
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
  }
}

void S21Matrix::CopyMatrix(const S21Matrix& other) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  bool status = true;

  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("Different matrix dimensions");
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (fabs(matrix_[i][j] - other.matrix_[i][j]) > EPS) {
        status = false;
        break;
      }
    }
  }

  return status;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  this->SumSubMatrix(other, Operation::Sum);
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  this->SumSubMatrix(other, Operation::Sub);
}

void S21Matrix::SumSubMatrix(const S21Matrix& other, Operation op) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("Different matrix dimensions");
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] =
          matrix_[i][j] + static_cast<int>(op) * other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_) {
    throw std::invalid_argument(
        "Different number of columns of the first matrix and rows of the "
        "second matrix");
  }

  S21Matrix result(rows_, other.cols_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      for (int k = 0; k < cols_; k++) {
        result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }

  *this = result;
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix result(cols_, rows_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      result.matrix_[j][i] = matrix_[i][j];
    }
  }

  return result;
}

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_ || rows_ < 2) {
    throw std::invalid_argument(
        "Matrix is not square matrix or number of rows and columns is less "
        "than 2");
  }

  S21Matrix result(rows_, cols_);

  S21Matrix tmp(rows_ - 1, cols_ - 1);
  double minor = 0;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      tmp.ClearMatrix();
      tmp = this->SplitMatrix(i, j);
      minor = tmp.Determinant();
      result.matrix_[i][j] = minor * pow(-1, i + j);
    }
  }

  return result;
}

double S21Matrix::Determinant() {
  double result = 0;

  if (rows_ != cols_) {
    throw std::invalid_argument("Matrix is not square matrix");
  }

  if (rows_ == 1) {
    result = matrix_[0][0];
  } else if (rows_ == 2) {
    result = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  } else {
    S21Matrix tmp(rows_ - 1, cols_ - 1);
    double minor = 0;

    for (int j = 0; j < cols_; j++) {
      int i = 0;
      tmp.ClearMatrix();
      tmp = this->SplitMatrix(i, j);
      result = tmp.Determinant() * matrix_[i][j] * pow((-1), i + j);
      minor += result;
    }
    result = minor;
  }

  return result;
}

S21Matrix S21Matrix::SplitMatrix(int row, int col) {
  S21Matrix tmp(rows_ - 1, cols_ - 1);

  int n = 0;
  for (int i = 0; i < tmp.rows_; i++) {
    int m = 0;
    if (i == row) {
      n = 1;
    }
    for (int j = 0; j < tmp.cols_; j++) {
      if (j == col) {
        m = 1;
      }
      tmp.matrix_[i][j] = matrix_[i + n][j + m];
    }
  }

  return tmp;
}

S21Matrix S21Matrix::InverseMatrix() {
  if (rows_ != cols_) {
    throw std::invalid_argument("Matrix is not square matrix");
  }

  double det = this->Determinant();

  if (det == 0) {
    throw std::invalid_argument("Determinant equals 0");
  }

  S21Matrix minors(rows_, cols_), trans(rows_, cols_), result(rows_, cols_);

  minors = this->CalcComplements();
  trans = minors.Transpose();
  trans.MulNumber(1 / det);
  result = trans;

  return result;
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
  S21Matrix tmp(*this);
  tmp.SumMatrix(other);
  return tmp;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) const {
  S21Matrix tmp(*this);
  tmp.SubMatrix(other);
  return tmp;
}

S21Matrix S21Matrix::operator*(const double& num) const {
  S21Matrix tmp(*this);
  tmp.MulNumber(num);
  return tmp;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) const {
  S21Matrix tmp(*this);
  tmp.MulMatrix(other);
  return tmp;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  this->SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  this->SubMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double& num) {
  this->MulNumber(num);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  this->MulMatrix(other);
  return *this;
}

bool S21Matrix::operator==(const S21Matrix& other) {
  return this->EqMatrix(other);
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  this->~S21Matrix();

  rows_ = other.rows_;
  cols_ = other.cols_;

  CreateMatrix();

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }

  return *this;
}

double& S21Matrix::operator()(int row, int col) const {
  if (row < 0 || col < 0) {
    throw std::invalid_argument("Index must be non-negative integer");
  }

  if (row >= rows_ || col >= cols_) {
    throw std::invalid_argument("Index is outside the matrix");
  }

  return matrix_[row][col];
}

void S21Matrix::ClearMatrix() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = 0;
    }
  }
}