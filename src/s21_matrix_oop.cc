#include "s21_matrix_oop.h"

int main() {

    S21Matrix matrix_A;

    return 0;
}

S21Matrix::S21Matrix() {

    rows_ = 0;
    cols_ = 0;
    matrix_ = nullptr;
}

S21Matrix::S21Matrix(int rows, int cols) {

    rows_ = rows;
    cols_ = cols;

    if (rows < 1 || cols < 1) {
        throw std::invalid_argument("Incorrect argument, rows and cols must be positive integers");
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

// bool EqMatrix(const S21Matrix& other);

// void SumMatrix(const S21Matrix& other);

// void SubMatrix(const S21Matrix& other);

// void MulNumber(const double num);

// void MulMatrix(const S21Matrix& other);

// S21Matrix Transpose();

// S21Matrix CalcComplements();

// double Determinant();

// S21Matrix InverseMatrix();

void S21Matrix::ClearMatrix(S21Matrix&& m) {

    for (int i = 0; i < m.rows_; i++) {
        for (int j = 0; j < m.cols_; j++) {
            m.matrix_[i][j] = 0;
        }
    }
}