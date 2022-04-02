namespace zich
{
	class Matrx;

} // namespace zich

class Matrix
{
private:
	vector<vector<double>> mat; // matrix data structure

public:
	Matrix(std::vector<double> values, int rows, int columns);
	~Matrix();

	// real value addition operators (+)
	Matrix operator+(const double &value) const;
	Matrix &operator+=(const double &value);
	Matrix &operator+() const;
	friend Matrix operator+(const int &value, const Matrix &mat);

	// matrix addition operators (+)
	Matrix operator+(const Matrix &mat) const;
	Matrix &operator+=(const Matrix &mat);

	// real value subtraction operators (-)
	Matrix operator-(const double &value) const;
	Matrix &operator-=(const double &value);
	Matrix &operator-() const;
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
	bool operator<(const Matrix &mat);
	bool operator>(const Matrix &mat);
	bool operator<=(const Matrix &mat);
	bool operator>=(const Matrix &mat);
	bool operator==(const Matrix &mat);
	bool operator!=(const Matrix &mat);

	// increment and decrement operators
	Matrix &operator++();	 // prefix (++x)
	Matrix &operator++(int); // postfix (x++)
	Matrix &operator--();	 // prefix (--x)
	Matrix &operator--(int); // postfix (x--)

	// input and output operators
	friend ostream &operator<<(ostream &out, const Matrix &mat);
	friend istream &operator>>(istream &in, const Matrix &mat);
};