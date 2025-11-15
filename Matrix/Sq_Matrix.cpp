#include "Sq_Matrix.hpp"
#include "assert.h"
#include <iostream>
#include <exception>

Sq_Matrix::Sq_Matrix() = default;

void Sq_Matrix::setData(int _num_rows, const float* buffer) {
    assert(_num_rows >= 0);

    // If one dimension is zero, so must the other, and buffer must be null
    if (_num_rows == 0) {
        assert(buffer == nullptr);
    }

    delete[] this->data;

    num_rows = _num_rows;

    data = new float[num_rows * num_rows];

    if (buffer) {
        // Copy from buffer
        for (int i = 0; i < num_rows * num_rows; i++)
            data[i] = buffer[i];
    } else {
        // Initialize to zero
        for (int i = 0; i < num_rows * num_rows; i++)
            data[i] = 0.0f;
    }
}

Sq_Matrix::Sq_Matrix(int _num_rows, const float* buffer){
    setData(_num_rows, buffer);
}

Sq_Matrix::Sq_Matrix(const Sq_Matrix& other): Sq_Matrix(other.num_rows, other.data){}

Sq_Matrix::~Sq_Matrix(){
    delete[] data;
}

float* Sq_Matrix::operator[](int i){
    return &data[i*num_rows];
}

const float* Sq_Matrix::operator[](int i) const{
    return &data[i*num_rows];
}

Sq_Matrix Sq_Matrix::operator*(Sq_Matrix& other){
    if (this->num_rows != other.num_rows){
        throw std::invalid_argument("Matrix multiplication needs matching dimensions");
    }
    Sq_Matrix Res {this->num_rows};
    for (int i = 0; i < this->num_rows; i++){
        for (int j = 0; j < other.num_rows; j++){
            Res[i][j] = 0;
            for (int k = 0; k < this->num_rows; k++){
                Res[i][j] += (*this)[i][k] * other[k][j];
            }
        }
    }
    return Res;
}

Sq_Matrix& Sq_Matrix::operator=(const Sq_Matrix& other){
    if (this == &other)
        return *this;

    setData(other.num_rows, other.data);
    
    return *this;
}

void Sq_Matrix::consolePrint() {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_rows; j++) {
            std::cout << (*this)[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

int Sq_Matrix::getNumRows() const{
    return num_rows;
}

int Sq_Matrix::getNumCols() const{
    return num_rows;
}

int Sq_Matrix::getMaxOnRow(int row, int starting_column, int ending_column) const{
    if (ending_column == -1)
        ending_column = num_rows-1;

    int best_column = starting_column;
    int best_max = abs((*this)[row][best_column]);
    for (int i = starting_column+1; i <= ending_column; i++){
        if (abs((*this)[row][i]) > best_max){
            best_column = i;
            best_max = abs((*this)[row][i]);
        }
    }
    return best_column;
}

int Sq_Matrix::getMaxOnColumn(int column, int starting_row, int ending_row) const{
    if (ending_row == -1)
        ending_row = num_rows-1;

    int best_row = starting_row;
    int best_max = abs((*this)[best_row][column]);
    for (int i = starting_row+1; i <= ending_row; i++){
        if (abs((*this)[i][column]) > best_max){
            best_row = i;
            best_max = abs((*this)[i][column]);
        }
    }
    return best_row;
}

void Sq_Matrix::eye(int n){
    setData(n);
    for (int i = 0; i < n; i++){
        (*this)[i][i] = 1;
    }
}

void Sq_Matrix::swapRows(int swapped_index, int swapper_index){
    for (int i = 0; i < num_rows; i++){
        std::swap((*this)[swapped_index][i],(*this)[swapper_index][i]);
    }
}

void Sq_Matrix::swapCols(int swapped_index, int swapper_index){
    for (int i = 0; i < num_rows; i++){
        std::swap((*this)[i][swapped_index],(*this)[i][swapper_index]);
    }
}