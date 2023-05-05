#include "s21_matrix_oop.h"

// int main() {

//     S21Matrix matrix_A(3, 3);
//     matrix_A.OutputMatrix();

//     return 0;
// }

S21Matrix::S21Matrix() {

    rows_ = 0;
    cols_ = 0;
    matrix_ = nullptr;
}

S21Matrix::S21Matrix(int rows, int cols) {

    rows_ = rows;
    cols_ = cols;

    if (rows < 1 || cols < 1) {
        throw std::invalid_argument("Rows and cols must be positive integers");
    }

    CreateMatrix();
}

void S21Matrix::CreateMatrix() {

    matrix_ = new double* [rows_];
    for (int i = 0; i < rows_; i++) {
        matrix_[i] = new double [cols_];
    }
}

S21Matrix::S21Matrix(const S21Matrix& other) {

    rows_ = other.rows_;
    cols_ = other.cols_;
    matrix_ = other.matrix_;
}

S21Matrix::S21Matrix(S21Matrix&& other) {
    
    rows_ = other.rows_;
    cols_ = other.cols_;
    matrix_ = other.matrix_;

    other.rows_ = 0;
    other.cols_ = 0;
    other.matrix_ = nullptr;
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

bool S21Matrix::EqMatrix(const S21Matrix& other) {

    bool status = true;

    if (rows_ == other.rows_ && cols_ == other.cols_) {
        for (int i = 0; i < rows_; i++) {
            for (int j = 0; j < cols_; j++) {

                if (fabs(matrix_[i][j] - other.matrix_[i][j]) > EPS) {
                    status = false;
                    break;
                }
            }
        }
    } else {
        status = false;
    }
    
    return status;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {

    this->SumSubMatrix(other, PLUS);
}

void S21Matrix::SubMatrix(const S21Matrix& other) {

    this->SumSubMatrix(other, MINUS);
}

void S21Matrix::SumSubMatrix(const S21Matrix& other, int sign) {

    if (rows_ == other.rows_ && cols_ == other.cols_) {

        for (int i = 0; i < rows_; i++) {
            for (int j = 0; j < cols_; j++) {

                matrix_[i][j] = matrix_[i][j] + sign * other.matrix_[i][j];
            }
        }
    } else {
        throw std::invalid_argument("Different matrix dimensions");
    }    
}

void S21Matrix::MulNumber(const double num) {

    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            matrix_[i][j] *= num;
        }
    }
}

// void MulMatrix(const S21Matrix& other);

// S21Matrix Transpose();

// S21Matrix CalcComplements();

// double Determinant();

// S21Matrix InverseMatrix();

double &S21Matrix::operator()(int row, int col) const {

  if (row < 0 || col < 0 || row >= rows_ || col >= cols_) {
    throw std::invalid_argument("Rows and cols must be positive integers");
  }

  return matrix_[row][col];
}

// void S21Matrix::OutputMatrix() {

//     for (int i = 0; i < rows_; i++) {
//         for (int j = 0; j < cols_; j++) {
//             std::cout << matrix_[i][j];
//         }
//         std::cout << std::endl;
//     }
// }

// void S21Matrix::ClearMatrix() {

//     for (int i = 0; i < rows_; i++) {
//         for (int j = 0; j < cols_; j++) {
//             matrix_[i][j] = 0;
//         }
//     }
// }