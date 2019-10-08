//
// Created by Kelvin Lee on 2019-10-01.
//

#ifndef PAGERANK_MATRIX_HPP
#define PAGERANK_MATRIX_HPP

#include <ostream>
#include <iostream>
#include <cmath>

constexpr double THRESHOLD = 0.001;

using namespace std;

class myMatrix
{
private:
    int num_row;
    int num_col;
    double** matrix;

public:
    myMatrix();
    myMatrix(int n);
    myMatrix(int r, int c);
    myMatrix(double *arr, size_t n);
    myMatrix(const myMatrix& other); // copy ctr
    ~myMatrix();

    void set_value(int row, int col, double val);
    double get_value(int row, int col) const;
    void clear();
    friend ostream& operator<<(ostream& os, const myMatrix& mx);
    friend bool operator==(const myMatrix& lhs, const myMatrix& rhs);
    friend bool operator!=(const myMatrix& lhs, const myMatrix& rhs);
    myMatrix& operator++();
    myMatrix operator++(int);
    myMatrix& operator--();
    myMatrix operator--(int);
    myMatrix& operator=(myMatrix rhs);
    friend void mySwap(myMatrix& first, myMatrix& second);
    myMatrix& operator+=(const myMatrix& rhs);
    friend myMatrix operator+(myMatrix lhs, const myMatrix& rhs);
    myMatrix& operator-=(const myMatrix& rhs);
    friend myMatrix operator-(myMatrix lhs, const myMatrix& rhs);
    myMatrix& operator*=(const myMatrix& rhs);
    friend myMatrix operator*(myMatrix lhs, const myMatrix& rhs);
};
#endif //PAGERANK_MATRIX_HPP
