#include "doctest.h"
#include "Matrix.hpp"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace zich;
using namespace std;

vector<double> operator+(vector<double> v1, vector<double> v2)
{
	// validate
	if (v1.size() != v2.size())
	{
		throw invalid_argument("Both vectors must be the same size!!!\n");
	}

	// initiate the resut vector
	size_t size = v1.size();
	vector<double> result(size, 0.0);

	// add two vectors and save to result
	for (size_t i = 0; i < size; ++i)
	{
		result[i] = v1.at(i) + v2.at(i);
	}

	return result;
}

vector<double> operator-(vector<double> v1, vector<double> v2)
{
	// validate
	if (v1.size() != v2.size())
	{
		throw invalid_argument("Both vectors must be the same size!!!\n");
	}

	// initiate the resut vector
	size_t size = v1.size();
	vector<double> result(size, 0.0);

	// subtract two vectors and save to result
	for (size_t i = 0; i < size; ++i)
	{
		result[i] = v1.at(i) - v2.at(i);
	}

	return result;
}

// print a vector (prints up to 2 decimal points)
ostream &operator<<(ostream &out, vector<double> vec)
{
	out << "[";
	for (vector<double>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		out << setprecision(2) << fixed << *it;
		if (it != vec.end() - 1)
		{
			out << "\t";
		}
	}
	out << "]" << endl;

	return out;
}

TEST_CASE("Matrix addition")
{
	// variables
	vector<double> v1 = {1.25, -1.2, 7, 5.3, -14, 3.3, -21.4, 87.5, 0.8, -8.9, -7, -6.4, 1, 29, -19.2, 0.01};
	vector<double> v2 = {3.42, 6.87, -1.9, 8.32, -9, -19, -21.4, 6.9, -0.8, 9.9, -7, -6.4, -1, 10, 38.4, 0.001};
	vector<double> v1_plus1 = {2.25, -0.2, 8, 6.3, -13, 4.3, -20.4, 88.5, 1.8, -7.9, -6, -5.4, 2, 30, -18.2, 1.01};

	// calculate the sum of v1 and v2
	vector<double> sum_vec = v1 + v2;

	// list of aspect ratios
	vector<vector<int>> aspect_ratios = {{2, 8}, {4, 4}, {8, 2}};

	// check +
	for (size_t i = 0; i < aspect_ratios.size(); i++)
	{
		vector<int> params = aspect_ratios.at(i);

		// create matrices for comparison
		Matrix a(v1, params.at(0), params.at(1));
		Matrix b(v2, params.at(0), params.at(1));
		Matrix sum(sum_vec, params.at(0), params.at(1));

		// add matrices
		Matrix result = a + b;

		// check if sum == result
		CHECK(sum == result);
	}

	// check +=
	for (size_t i = 0; i < aspect_ratios.size(); i++)
	{
		vector<int> params = aspect_ratios.at(i);

		// create matrices for comparison
		Matrix a(v1, params.at(0), params.at(1));
		Matrix b(v2, params.at(0), params.at(1));
		Matrix sum(sum_vec, params.at(0), params.at(1));

		// add using +=
		a += b;
		CHECK(sum == a);
	}

	// check ++ (postfix)
	for (size_t i = 0; i < aspect_ratios.size(); i++)
	{
		vector<int> params = aspect_ratios.at(i);

		// create matrices for comparison
		Matrix a(v1, params.at(0), params.at(1));
		Matrix b(v1_plus1, params.at(0), params.at(1));

		// add using x++ (postfix)
		a++;
		CHECK(b == a);
	}

	// check ++ (prefix)
	for (size_t i = 0; i < aspect_ratios.size(); i++)
	{
		vector<int> params = aspect_ratios.at(i);

		// create matrices for comparison
		Matrix a(v1, params.at(0), params.at(1));
		Matrix b(v1_plus1, params.at(0), params.at(1));

		// add using ++x (prefix)
		++a;
		CHECK(b == a);
	}
}

TEST_CASE("Matrix subtraction")
{
	// variables
	vector<double> v1 = {1.25, -1.2, 7, 5.3, -14, 3.3, -21.4, 87.5, 0.8, -8.9, -7, -6.4, 1, 29, -19.2, 0.01};
	vector<double> v2 = {3.42, 6.87, -1.9, 8.32, -9, -19, -21.4, 6.9, -0.8, 9.9, -7, -6.4, -1, 10, 38.4, 0.001};
	vector<double> v1_minus1 = {0.25, -2.2, 6, 4.3, -15, 2.3, -22.4, 86.5, -0.2, -9.9, -8, -7.4, 0, 28, -20.2, -1.01};

	// calculate the difference of v1 and v2
	vector<double> sub_vec = v1 - v2;

	// list of aspect ratios
	vector<vector<int>> aspect_ratios = {{2, 8}, {4, 4}, {8, 2}};

	// check -
	for (size_t i = 0; i < aspect_ratios.size(); i++)
	{
		vector<int> params = aspect_ratios.at(i);

		// create matrices for comparison
		Matrix a(v1, params.at(0), params.at(1));
		Matrix b(v2, params.at(0), params.at(1));
		Matrix diff(sub_vec, params.at(0), params.at(1));

		// subtract matrices
		Matrix result = a - b;

		// check if diff == result
		CHECK(diff == result);
	}

	// check -=
	for (size_t i = 0; i < aspect_ratios.size(); i++)
	{
		vector<int> params = aspect_ratios.at(i);

		// create matrices for comparison
		Matrix a(v1, params.at(0), params.at(1));
		Matrix b(v2, params.at(0), params.at(1));
		Matrix sum(sub_vec, params.at(0), params.at(1));

		// add using -=
		a -= b;
		CHECK(sum == a);
	}

	// check -- (postfix)
	for (size_t i = 0; i < aspect_ratios.size(); i++)
	{
		vector<int> params = aspect_ratios.at(i);

		// create matrices for comparison
		Matrix a(v1, params.at(0), params.at(1));
		Matrix b(v1_minus1, params.at(0), params.at(1));

		// add using x-- (postfix)
		a--;
		CHECK(b == a);
	}

	// check -- (prefix)
	for (size_t i = 0; i < aspect_ratios.size(); i++)
	{
		vector<int> params = aspect_ratios.at(i);

		// create matrices for comparison
		Matrix a(v1, params.at(0), params.at(1));
		Matrix b(v1_minus1, params.at(0), params.at(1));

		// add using --x (prefix)
		--a;
		CHECK(b == a);
	}
}

TEST_CASE("Matrix multiplication")
{
	// variables
	vector<double> v1 = {1.25, -1.2, 7, 5.3, -14, 3.3, -21.4, 87.5, 0.8, -8.9, -7, -6.4, 1, 29, -19.2, 0.01};
	vector<double> v2 = {3.42, 6.87, -1.9, 8.32, -9, -19, -21.4, 6.9, -0.8, 9.9, -7, -6.4, -1, 10, 38.4, 0.001};

	// expected result vector
	vector<double> product = {3199.6349999999998,
							  -471.459,
							  35.389999999999986,
							  -347.41199000000006};

	// create matrices to test on
	Matrix a(v1, 8, 2);
	Matrix b(v2, 2, 8);
	Matrix result(product, 2, 2);

	// check if result = a * b (might have some problems due to using double)
	CHECK(result == a * b);

	// check *= operator
	a *= b;
	CHECK(result == a);
}