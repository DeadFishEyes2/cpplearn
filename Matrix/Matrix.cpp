#include "Matrix.hpp"
#include "assert.h"
#include <iostream>
#include <exception>

Matrix::Matrix() = default;

void Matrix::setData(int _num_rows, int _num_columns, const float* buffer) {
    assert(_num_rows >= 0 && _num_columns >= 0);

    // If one dimension is zero, so must the other, and buffer must be null
    if (_num_rows == 0 || _num_columns == 0) {
        assert(buffer == nullptr);
    }

    delete[] this->data;

    num_rows = _num_rows;
    num_cols = _num_columns;

    data = new float[num_rows * num_cols];

    if (buffer) {
        // Copy from buffer
        for (int i = 0; i < num_rows * num_cols; i++)
            data[i] = buffer[i];
    } else {
        // Initialize to zero
        for (int i = 0; i < num_rows * num_cols; i++)
            data[i] = 0.0f;
    }
}

Matrix::Matrix(int _num_rows, int _num_columns, const float* buffer){
    setData(_num_rows, _num_columns, buffer);
}

Matrix::Matrix(const Matrix& other): Matrix(other.num_rows, other.num_cols, other.data){}

Matrix::~Matrix(){
    delete[] data;
}

float* Matrix::operator[](int i){
    return &data[i*num_cols];
}

const float* Matrix::operator[](int i) const{
    return &data[i*num_cols];
}

Matrix Matrix::operator*(Matrix& other){
    if (this->num_cols != other.num_rows){
        throw std::invalid_argument("Matrix multiplication needs matching dimensions");
    }
    Matrix Res {this->num_rows, other.num_cols};
    for (int i = 0; i < this->num_rows; i++){
        for (int j = 0; j < other.num_cols; j++){
            Res[i][j] = 0;
            for (int k = 0; k < this->num_cols; k++){
                Res[i][j] += (*this)[i][k] * other[k][j];
            }
        }
    }
    return Res;
}

Matrix& Matrix::operator=(const Matrix& other){
    if (this == &other)
        return *this;

    setData(other.num_rows, other.num_cols, other.data);
    
    return *this;
}

void Matrix::consolePrint() {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            std::cout << (*this)[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

int Matrix::getNumRows() const{
    return num_rows;
}

int Matrix::getNumCols() const{
    return num_cols;
}

void Matrix::eye(int n){
    setData(n, n);
    for (int i = 0; i < n; i++){
        (*this)[i][i] = 1;
    }
}

void Matrix::swapRows(int swapped_index, int swapper_index){
    for (int i = 0; i < num_cols; i++){
        std::swap((*this)[swapped_index][i],(*this)[swapper_index][i]);
    }
}

void Matrix::swapCols(int swapped_index, int swapper_index){
    for (int i = 0; i < num_rows; i++){
        std::swap((*this)[i][swapped_index],(*this)[i][swapper_index]);
    }
}