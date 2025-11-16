#pragma once

class Sq_Matrix{
    protected:
        int num_rows = 0;
        float* data = nullptr;

    public:
        Sq_Matrix();
        Sq_Matrix(int _num_rows, const float* buffer = nullptr);
        Sq_Matrix(const Sq_Matrix&);
        ~Sq_Matrix();

        //the operator[i] return a pointer to the i-th row position in data, this allows for Matrix[i][j] to return this->data[i][j]
        float* operator[](int);
        const float* operator[](int) const;
        
        //deletes the matrix on the left and replaces it with the one on the right, element by element
        Sq_Matrix& operator=(const Sq_Matrix&);
        
        //matrix multiplication
        Sq_Matrix operator*(const Sq_Matrix&) const;

        //empties the data from this Matrix and replaces it with the buffer
        void setData(int, const float* = nullptr);
        
        //Creates an I matrix of size n
        void eye(int n = -1);
        //Creates an O matrix of size n
        void zero(int n = -1);

        //getters
        int getNumRows() const;
        int getNumCols() const;
        int getMaxOnRow(int, int = 0, int = -1) const;
        int getMaxOnColumn(int, int = 0, int = -1) const;
        void getMaxOnMatrix(int&, int&, int = 0, int = 0, int = -1, int = -1);
        
        //inplace swaps, first term is the index swapped and the second is the swapper
        void swapRows(int, int);
        void swapCols(int, int);

        //transpose
        Sq_Matrix t() const;
        
        //prints the data in the console
        void consolePrint();
};