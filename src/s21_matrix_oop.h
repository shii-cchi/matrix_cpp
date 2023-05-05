#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_

#include <stdexcept>
#include <iostream>
#include <cmath>

#define EPS 1e-07

#define PLUS 1
#define MINUS -1

class S21Matrix {
    private:
        int rows_, cols_;
        double **matrix_;

    public:
        S21Matrix();
        S21Matrix(int rows, int cols);
        S21Matrix(const S21Matrix& other);
        S21Matrix(S21Matrix&& other);
        ~S21Matrix();

        void CreateMatrix();

        bool EqMatrix(const S21Matrix& other);
        void SumMatrix(const S21Matrix& other);
        void SubMatrix(const S21Matrix& other);
        void SumSubMatrix(const S21Matrix& other, int sign);

        void MulNumber(const double num);
        // void MulMatrix(const S21Matrix& other);
        // S21Matrix Transpose();
        // S21Matrix CalcComplements();
        // double Determinant();
        // S21Matrix InverseMatrix();


        double &operator()(int row, int col) const;
        // void OutputMatrix();
        // void ClearMatrix();
};

#endif  // SRC_S21_MATRIX_OOP_H_