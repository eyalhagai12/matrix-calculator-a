#include <iostream>
#include <vector>

namespace zich
{
	class Matrx;

} // namespace zich

class Matrix
{
private:
	std::vector<std::vector<double>> mat; // matrix data structure

public:
	// constructor and destructor
	Matrix(std::vector<double> values, int rows, int columns);
	~Matrix();

	// real value addition operators (+)
	Matrix operator+(const double &value) const;
	Matrix &operator+=(const double &value);
	const Matrix operator+() const;
	friend Matrix operator+(const int &value, const Matrix &mat);

	// matrix addition operators (+)
	Matrix operator+(const Matrix &mat) const;
	Matrix &operator+=(const Matrix &mat);

	// real value subtraction operators (-)
	Matrix operator-(const double &value) const;
	Matrix &operator-=(const double &value);
	const Matrix operator-() const;
	friend Matrix operator-(const int &value, const Matrix &mat);

	// matrix subtraction operators (-)
	Matrix operator-(const Matrix &mat) const;
	Matrix &operator-=(const Matrix &mat);

	// real value multiplaction operators (*)
	Matrix operator*(const double &value) const;
	Matrix &operator*=(const double &value);
	friend Matrix operator*(const int &value, const Matrix &mat);

	// matrix multiplaction operators (*)
	Matrix operator*(const Matrix &mat) const;
	Matrix &operator*=(const Matrix &mat);

	// comparison operators (<, >, <=, >=, ==, !=)
	bool operator<(const Matrix &mat) const;
	bool operator>(const Matrix &mat) const;
	bool operator<=(const Matrix &mat) const;
	bool operator>=(const Matrix &mat) const;
	bool operator==(const Matrix &mat) const;
	bool operator!=(const Matrix &mat) const;

	// increment and decrement operators
	Matrix &operator++();	 // prefix (++x)
	Matrix &operator++(int); // postfix (x++)
	Matrix &operator--();	 // prefix (--x)
	Matrix &operator--(int); // postfix (x--)

	// input and output operators
	friend std::ostream &operator<<(std::ostream &out, const Matrix &mat);
	friend std::istream &operator>>(std::istream &in, const Matrix &mat);
};