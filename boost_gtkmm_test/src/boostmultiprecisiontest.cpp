/*
 * boostmultiprecisiontest.cpp
 *
 *  Created on: Jan 17, 2014
 *      Author: hamed
 */

#include "boostmultiprecisiontest.h"

#include <iostream>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <cmath>

using namespace std;
using namespace boost::multiprecision;

boost_multiprecision_test::boost_multiprecision_test() {
	// TODO Auto-generated constructor stub

}

string boost_multiprecision_test::test_precision() {
	stringstream buffer;
	streambuf * old = std::cout.rdbuf(buffer.rdbuf());

	float d_f = 2.0f;
	cout << "Type float, precision = " << numeric_limits<float>::digits10
			<< endl << "sqrt(2.0) = "
			<< setprecision(numeric_limits<float>::digits10) << sqrt(d_f)
			<< "\n3.0/7.0 = " << 3.0f / 7.0f << "\narc cos (-1) = "
			<< acos(-1.0f) << "\n\n";

	double d_d = 2.0;
	cout << "Type double, precision = " << numeric_limits<double>::digits10
			<< endl << "sqrt(2.0) = "
			<< setprecision(std::numeric_limits<double>::digits10) << sqrt(d_d)
			<< "\n3.0/7.0 = " << 3.0 / 7.0 << "\narc cos (-1) = " << acos(-1.0)
			<< "\n\n";

	long double d_ld = 2.0L;
	cout << "Type long double, precision = "
			<< numeric_limits<long double>::digits10 << endl << "sqrt(2.0) = "
			<< setprecision(numeric_limits<long double>::digits10) << sqrt(d_ld)
			<< "\n3.0/7.0 = " << 3.0L / 7.0 << "\narc cos (-1) = "
			<< acos(-1.0L) << "\n\n";

	cpp_dec_float_50 d_cpp_50(2.0);
	cout << "Type cpp_dec_float_50, precision = "
			<< numeric_limits<cpp_dec_float_50>::digits10 << endl
			<< "sqrt(2.0) = "
			<< setprecision(numeric_limits<cpp_dec_float_50>::digits10)
			<< sqrt(d_cpp_50) << "\n3.0/7.0 = " << cpp_dec_float_50(3.0) / 7.0
			<< "\narc cos (-1) = " << acos(cpp_dec_float_50(-1.0)) << "\n\n";

	cpp_dec_float_100 d_cpp_100(2.0);
	cout << "Type cpp_dec_float_100, precision = "
			<< numeric_limits<cpp_dec_float_100>::digits10 << endl
			<< "sqrt(2.0) = "
			<< setprecision(numeric_limits<cpp_dec_float_100>::digits10)
			<< sqrt(d_cpp_100) << "\n3.0/7.0 = " << cpp_dec_float_100(3.0) / 7.0
			<< "\narc cos (-1) = " << acos(cpp_dec_float_100(-1.0)) << "\n\n";

	string text = buffer.str();
	return text;
}

boost_multiprecision_test::~boost_multiprecision_test() {
	// TODO Auto-generated destructor stub
}

