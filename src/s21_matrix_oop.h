#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_

//-std=c++17 standart

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

        bool EqMatrix(const S21Matrix& other);
        void SumMatrix(const S21Matrix& other);
        void SubMatrix(const S21Matrix& other);
        void MulNumber(const double num);
        void MulMatrix(const S21Matrix& other);
        S21Matrix Transpose();
        S21Matrix CalcComplements();
        double Determinant();
        S21Matrix InverseMatrix();
}

#endif  // SRC_S21_MATRIX_OOP_H_