//
// Created by Kelvin Lee on 2019-10-01.
//

#include "matrix.hpp"

myMatrix::myMatrix() {
    num_row = num_col = 1;
    matrix = new double *[1];
//    matrix = new double *[num_row]; // rows
//    *matrix = new double[num_col]{0.0};
}

myMatrix::myMatrix(int n) {
    if (n <= 0)
        throw "Matrix must be initialized with a positive integer";
    num_row = num_col = n;
    matrix = new double *[num_row]; // rows
    for (int i = 0; i < n; i++)
        matrix[i] = new double[num_col] {0.0};
}

myMatrix::myMatrix(int r, int c) {
    if (r <= 0 || c <= 0)
        throw "Matrix must be initialized with a positive integer";
    num_row = r;
    num_col = c;
    matrix = new double *[num_row]; // rows
    for (int i = 0; i < num_row; i++)
        matrix[i] = new double[num_col] {0.0};
}

myMatrix::myMatrix(double *arr, size_t n) {
    if (n <= 0 || sqrt(n) - floor(sqrt(n)) != 0)
        throw "Size of array must be a perfect square and a positive integer";
    int index = 0;
    num_row = num_col = sqrt(n);
    matrix = new double *[num_row]; // rows
    for (int i = 0; i < num_row; i++)
        matrix[i] = new double[num_col]{0.0};
    for (int i = 0; i < num_row; i++) {
        for (int j = 0; j < num_col; j++) {
            matrix[i][j] = arr[index++];
        }
    }
}

myMatrix::myMatrix(const myMatrix &other) {
    num_row = other.num_row;
    num_col = other.num_col;

    if(other.matrix) {
        matrix = new double *[num_row];
        for (int i = 0; i < num_row; i++)
            matrix[i] = new double[num_col];
        for (int j = 0; j < num_row; j++) {
            for (int k = 0; k < num_col; k++) {
                matrix[j][k] = other.matrix[j][k];
            }
        }
    }
}

myMatrix::~myMatrix() {
    if(matrix) { // check if matrix is equal to null pointer
        for (int i = 0; i < num_row; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
        cout << "matrix deleted" << endl;
    }
}

void myMatrix::set_value(int row, int col, double val) {
//    if(val < 0 || val > 1000) //TODO ask what is too large and add a constexpr
//        throw "Cannot set negative or large numbers";
    matrix[row][col] = val;
}

double myMatrix::get_value(int row, int col) const {
    // TODO throw exception if integers are negative or too large?
    return matrix[row][col];
}

void myMatrix::clear() {
    for (int i = 0; i < num_row; i++) { // row
        for (int j = 0; j < num_col; j++) { // col
            set_value(i, j, 0.0);
        }
    }
}

ostream &operator<<(ostream &os, const myMatrix &mx) {
    for (int i = 0; i < mx.num_row; i++) { // row
        for (int j = 0; j < mx.num_col; j++) { // col
            os << fixed << mx.get_value(i, j) << " ";
        }
        os << endl;
    }
    return os;
}

bool operator==(const myMatrix &lhs, const myMatrix &rhs) {
    if (lhs.num_col != rhs.num_col || lhs.num_row != rhs.num_row)
        return false;
    for (int i = 0; i < lhs.num_row; i++) { // row
        for (int j = 0; j < lhs.num_col; j++) { // col
            if (abs((lhs.get_value(i, j) - rhs.get_value(i, j))) >= THRESHOLD) // checking if accurate to 0.001
                return false;
        }
    }
    return true;
}

bool operator!=(const myMatrix &lhs, const myMatrix &rhs) {
    return !(lhs == rhs);
}

myMatrix &myMatrix::operator++() //prefix ++counter
{
    for (int i = 0; i < num_row; i++) { // row
        for (int j = 0; j < num_col; j++) { // col
            double tmp = get_value(i, j);
            set_value(i, j, ++tmp);
        }
    }
    return *this;
}

myMatrix myMatrix::operator++(int) //postfix counter++
{
    myMatrix tmp(*this);
    operator++();
    return tmp;
    //TODO fix bug
}

myMatrix &myMatrix::operator--() //prefix --counter
{
    for (int i = 0; i < num_row; i++) { // row
        for (int j = 0; j < num_col; j++) { // col
            double tmp = get_value(i, j);
            set_value(i, j, --tmp);
        }
    }
    return *this;
}

myMatrix myMatrix::operator--(int) //postfix counter--
{
    myMatrix tmp(*this);
    operator--();
    return tmp;
    //TODO fix bug
}

myMatrix &myMatrix::operator=(myMatrix other) {
    mySwap(*this, other);
    return *this;
}

void mySwap(myMatrix &first, myMatrix &second) {
    using std::swap;
    swap(first.num_row, second.num_row);
    swap(first.num_col, second.num_col);
    swap(first.matrix, second.matrix);
}

myMatrix &myMatrix::operator+=(const myMatrix &rhs) {
    if (num_row != rhs.num_row || num_col != rhs.num_col)
        throw "Addition of matrices must have same size";
    for (int i = 0; i < num_row; i++) { // row
        for (int j = 0; j < num_col; j++) { // col
            set_value(i, j, matrix[i][j] + rhs.matrix[i][j]);
        }
    }
    return *this;
}

myMatrix operator+(myMatrix lhs, const myMatrix &rhs) {
    lhs += rhs;
    return lhs;
}

myMatrix &myMatrix::operator-=(const myMatrix &rhs) {
    if (num_row != rhs.num_row || num_col != rhs.num_col)
        throw "Subtraction of matrices must have same size";
    for (int i = 0; i < num_row; i++) { // row
        for (int j = 0; j < num_col; j++) { // col
            set_value(i, j, matrix[i][j] - rhs.matrix[i][j]);
        }
    }
    return *this;
}

myMatrix operator-(myMatrix lhs, const myMatrix &rhs) {
    lhs -= rhs;
    return lhs;
}

myMatrix &myMatrix::operator*=(const myMatrix &rhs) {
    if (num_col != rhs.num_row)
        throw "Multiplication of matrices must be [x][y] * [y][z]";
    myMatrix tmp{num_row, rhs.num_col}; // need a new sized matrix
    for (int i = 0; i < num_row; i++) { // this num or row
        for (int j = 0; j < rhs.num_col; j++) { // rhs num of col
            for (int k = 0; k < rhs.num_row; k++) // this num of col/rhs num of row
            {
                tmp.matrix[i][j] += matrix[i][k] * rhs.matrix[k][j];
            }
        }
    }
    return *this = tmp;
}

myMatrix operator*(myMatrix lhs, const myMatrix &rhs) {
    lhs *= rhs;
    return lhs;
}
