//============================================================================
// Name        : boost_gmp_float_test.cpp
// Author      : Hamed Mohammadi
// Version     :
// Copyright   : Your copyright notice
// Description : Boost C++ libraries - GMP multiprecision example
//============================================================================

#include <iostream>
#include <boost/multiprecision/gmp.hpp>
#include <boost/math/special_functions/gamma.hpp>

using namespace boost::multiprecision;

int main() {
	// Operations at variable precision and limited standard library support:
	mpf_float a = 2;
	mpf_float::default_precision(100);
	std::cout << mpf_float::default_precision() << std::endl;
	std::cout << std::setprecision(mpf_float::default_precision()) << sqrt(a) << std::endl; // print root-2

	// Operations at fixed precision and full standard library support:
	mpf_float_100 b = 2;
	std::cout << std::numeric_limits<mpf_float_100>::digits << std::endl;
	// We can use any C++ std lib function:
	std::cout << log(b) << std::endl; // print log(2)
	// We can also use any function from Boost.Math:
	std::cout << boost::math::tgamma(b) << std::endl;
	// These even work when the argument is an expression template:
	std::cout << boost::math::tgamma(b * b) << std::endl;

	// Access the underlying representation:
	mpf_t f;
	mpf_init(f);
	mpf_set(f, a.backend().data());
	return 0;
}
