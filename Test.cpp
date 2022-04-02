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

	// add to the vector
	for (size_t i = 0; i < size; ++i)
	{
		result[i] = v1.at(i) + v2.at(i);
	}

	return result;
}

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

TEST_CASE("Good input")
{
	// variables
	vector<double> v1 = {1.25, -1.2, 7, 5.3, -14, 3.3, -21.4, 87.5, 0.8, -8.9, -7, -6.4, 1, 29, -19.2, 0.01};
	vector<double> v2 = {3.42, 6.87, -1.9, 8.32, -9, -19, -21.4, 6.9, -0.8, 9.9, -7, -6.4, -1, 10, 38.4, 0.001};

	// calculate the sum of v1 and v2
	vector<double> sum_vec = v1 + v2;

	// sum of vector
	double sum = 0;
	for (vector<double>::iterator it = sum_vec.begin(); it != sum_vec.end(); ++it)
	{
		sum += *it;
	}

	// list of aspect ratios
	vector<vector<int>> aspect_ratios = {{2, 8}, {4, 4}, {8, 2}};

	// add matrices
	for (size_t i = 0; i < aspect_ratios.size(); i++)
	{
		vector<int> params = aspect_ratios.at(i);

		// create new matrices
		Matrix a(v1, params.at(0), params.at(1));
		Matrix b(v2, params.at(0), params.at(1));
		Matrix sum(sum_vec, params.at(0), params.at(1));

		// add matrices
		Matrix result = a + b;

		// check if sum == result
		CHECK(sum == result);
	}
}
