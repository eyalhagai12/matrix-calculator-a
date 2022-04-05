#include <iostream>
#include <vector>
#include "Matrix.hpp"

// constructor and destructor
std::vector<double> empty(1, 0.0);
Matrix::Matrix(std::vector<double>, int rows, int columns) {}
Matrix::~Matrix() {}

// real value addition operators (+)
Matrix Matrix::operator+(const double &value) const {return Matrix(empty, 1, 1);}
Matrix &Matrix::operator+=(const double &value) {return *this;}
const Matrix Matrix::operator+() const {return *this;}
Matrix operator+(const double &value, const Matrix &mat) {return Matrix(empty, 1, 1);}

// matrix addition operators (+)
Matrix Matrix::operator+(const Matrix &mat) const {return Matrix(empty, 1, 1);}
Matrix &Matrix::operator+=(const Matrix &mat) {return *this;}

// real value subtraction operators (-)
Matrix Matrix::operator-(const double &value) const {return Matrix(empty, 1, 1);}
Matrix &Matrix::operator-=(const double &value) {return *this;}
const Matrix Matrix::operator-() const {return *this;}
Matrix operator-(const double &value, const Matrix &mat) {return Matrix(empty, 1, 1);}

// matrix subtraction operators (-)
Matrix Matrix::operator-(const Matrix &mat) const {return Matrix(empty, 1, 1);}
Matrix &Matrix::operator-=(const Matrix &mat) {return *this;}

// real value multiplaction operators (*)
Matrix Matrix::operator*(const double &value) const {return Matrix(empty, 1, 1);}
Matrix &Matrix::operator*=(const double &value) {return *this;}
Matrix operator*(const double &value, const Matrix &mat) {return Matrix(empty, 1, 1);}

// matrix multiplaction operators (*)
Matrix Matrix::operator*(const Matrix &mat) const {return Matrix(empty, 1, 1);}
Matrix &Matrix::operator*=(const Matrix &mat) {return *this;}

// comparison operators (<, >, <=, >=, ==, !=)
bool Matrix::operator>(const Matrix &mat) const {return false;}
bool Matrix::operator<(const Matrix &mat) const {return false;}
bool Matrix::operator<=(const Matrix &mat) const {return false;}
bool Matrix::operator>=(const Matrix &mat) const {return false;}
bool Matrix::operator==(const Matrix &mat) const {return false;}
bool Matrix::operator!=(const Matrix &mat) const {return false;}

// increment and decrement operators
Matrix &Matrix::operator++() {return *this;}    // prefix (++x)
Matrix &Matrix::operator++(int) {return *this;} // postfix (x++)
Matrix &Matrix::operator--() {return *this;}    // prefix (--x)
Matrix &Matrix::operator--(int) {return *this;} // postfix (x--)

// input and output operators
std::ostream &operator<<(std::ostream &out, const Matrix &mat) {return out;}
std::istream &operator>>(std::istream &in, const Matrix &mat) {return in;}