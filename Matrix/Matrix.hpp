#pragma once
#include "Sq_Matrix.hpp"

class Matrix: public Sq_Matrix{
    protected:
        int num_rows = 0;
        int num_cols = 0;
        float* data = nullptr;

    public:
        Matrix();
        Matrix(int _num_rows, int _num_columns, const float* buffer = nullptr);
        Matrix(const Matrix&);
        ~Matrix();

        //the operator[i] return a pointer to the i-th row position in data, this allows for Matrix[i][j] to return this->data[i][j]
        float* operator[](int);
        const float* operator[](int) const;
        
        //deletes the matrix on the left and replaces it with the one on the right, element by element
        Matrix& operator=(const Matrix&);
        
        //matrix multiplication
        Matrix operator*(Matrix&);

        //empties the data from this Matrix and replaces it with the buffer
        void setData(int, int, const float* = nullptr);
        
        //Creates an I matrix of size n
        void eye(int);

        //getters
        int getNumRows() const;
        int getNumCols() const;
        
        //inplace swaps, first term is the index swapped and the second is the swapper
        void swapRows(int, int);
        void swapCols(int, int);
        
        //prints the data in the console
        void consolePrint();
};