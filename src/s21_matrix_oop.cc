#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() : rows_(3), cols_(3) { AllocateMatrix(); }

S21Matrix::S21Matrix(int rows, int cols) {
  if (rows < 1 || cols < 1) {
    throw std::invalid_argument(
        "Number of rows and number of columns must be positive integers");
  }

  rows_ = rows;
  cols_ = cols;

  AllocateMatrix();
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_), cols_(other.cols_) {
  AllocateMatrix();
  CopyMatrix(other);
}

S21Matrix::S21Matrix(S21Matrix&& other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
}

S21Matrix::~S21Matrix() { ClearMatrix(); }

void S21Matrix::AllocateMatrix() {
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]{};
  }
}

void S21Matrix::FillWithZeros() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = 0;
    }
  }
}

void S21Matrix::CopyMatrix(const S21Matrix& other) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

void S21Matrix::ClearMatrix() {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }

    delete[] matrix_;
    matrix_ = nullptr;
  }
}

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  const double kEpsilon = 1e-07;

  bool status = true;

  if (rows_ != other.rows_ || cols_ != other.cols_) {
    status = false;
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        if (fabs(matrix_[i][j] - other.matrix_[i][j]) > kEpsilon) {
          status = false;
          break;
        }
      }
    }
  }

  return status;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  SumSubMatrix(other, SumOrSubOperation::kSum);
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  SumSubMatrix(other, SumOrSubOperation::kSub);
}

void S21Matrix::SumSubMatrix(const S21Matrix& other, SumOrSubOperation op) {
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
  if (rows_ != cols_) {
    throw std::invalid_argument("Matrix is not square matrix");
  }

  if (rows_ < 2) {
    throw std::invalid_argument(
        "Number of rows and columns must be greater than 1");
  }

  S21Matrix result(rows_, cols_);

  S21Matrix tmp(rows_ - 1, cols_ - 1);
  double minor = 0;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      tmp.FillWithZeros();
      tmp = GetMinorMatrix(i, j);
      minor = tmp.Determinant();
      result.matrix_[i][j] = minor * pow(-1, i + j);
    }
  }

  return result;
}

double S21Matrix::Determinant() {
  if (rows_ != cols_) {
    throw std::invalid_argument("Matrix is not square matrix");
  }

  double result = 0;

  if (rows_ == 1) {
    result = matrix_[0][0];
  } else if (rows_ == 2) {
    result = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  } else {
    S21Matrix tmp(rows_ - 1, cols_ - 1);
    double minor = 0;

    for (int j = 0; j < cols_; j++) {
      int i = 0;
      tmp.FillWithZeros();
      tmp = GetMinorMatrix(i, j);
      result = tmp.Determinant() * matrix_[i][j] * pow((-1), i + j);
      minor += result;
    }
    result = minor;
  }

  return result;
}

S21Matrix S21Matrix::GetMinorMatrix(int row, int col) {
  S21Matrix tmp(rows_ - 1, cols_ - 1);

  int row_offset = 0;
  for (int i = 0; i < tmp.rows_; i++) {
    int col_offset = 0;
    if (i == row) {
      row_offset = 1;
    }
    for (int j = 0; j < tmp.cols_; j++) {
      if (j == col) {
        col_offset = 1;
      }
      tmp.matrix_[i][j] = matrix_[i + row_offset][j + col_offset];
    }
  }

  return tmp;
}

S21Matrix S21Matrix::InverseMatrix() {
  if (rows_ != cols_) {
    throw std::invalid_argument("Matrix is not square matrix");
  }

  S21Matrix result(rows_, cols_);

  if (rows_ == 1 && cols_ == 1) {
    result.matrix_[0][0] = 1 / matrix_[0][0];
  } else {
    double det = Determinant();

    if (det == 0) {
      throw std::invalid_argument("Determinant equals 0");
    }

    S21Matrix trans(rows_, cols_);

    trans = CalcComplements().Transpose();
    trans.MulNumber(1 / det);
    result = trans;
  }

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
  SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double& num) {
  MulNumber(num);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return *this;
}

bool S21Matrix::operator==(const S21Matrix& other) { return EqMatrix(other); }

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (rows_ == other.rows_ && cols_ == other.cols_) {
    if (*this == other) {
      return *this;
    }
  }

  ClearMatrix();

  rows_ = other.rows_;
  cols_ = other.cols_;

  AllocateMatrix();

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
    throw std::invalid_argument("Index is out of range");
  }

  return matrix_[row][col];
}

int S21Matrix::GetRows() const { return rows_; }

int S21Matrix::GetCols() const { return cols_; }

void S21Matrix::SetRows(int rows) {
  if (rows < 1) {
    throw std::invalid_argument("Number of rows must be positive integer");
  }

  if (rows == rows_) {
    return;
  }

  S21Matrix tmp(rows, cols_);
  int filled_rows = 0;

  if (rows < rows_) {
    filled_rows = rows;

  } else {
    filled_rows = rows_;
  }

  for (int i = 0; i < filled_rows; i++) {
    for (int j = 0; j < cols_; j++) {
      tmp.matrix_[i][j] = matrix_[i][j];
    }
  }

  *this = tmp;
}

void S21Matrix::SetCols(int cols) {
  if (cols < 1) {
    throw std::invalid_argument("Number of columns must be positive integer");
  }

  if (cols == cols_) {
    return;
  }

  S21Matrix tmp(rows_, cols);
  int filled_cols = 0;

  if (cols < cols_) {
    filled_cols = cols;

  } else {
    filled_cols = cols_;
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < filled_cols; j++) {
      tmp.matrix_[i][j] = matrix_[i][j];
    }
  }

  *this = tmp;
}