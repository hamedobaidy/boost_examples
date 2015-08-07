//============================================================================
// Name        : boost_mpfr_float_test.cpp
// Author      : Hamed Mohammadi
// Version     :
// Copyright   : Your copyright notice
// Description : Boost C++ libraries - mpfr float example
//============================================================================

#include <iostream>

#include <boost/multiprecision/mpfr.hpp>
#include <boost/math/special_functions/gamma.hpp>

using namespace boost::multiprecision;

int main() {
	// Operations at variable precision and no numeric_limits support:
	mpfr_float a = 2;
	mpfr_float::default_precision(1000);
	std::cout << mpfr_float::default_precision() << std::endl;
	std::cout << std::setprecision(100) << sqrt(a) << std::endl; // print root-2

	// Operations at fixed precision and full numeric_limits support:
	mpfr_float_100 b = 2;
	std::cout << std::numeric_limits<mpfr_float_100>::digits << std::endl;
	// We can use any C++ std lib function:
	std::cout << std::setprecision(100) << log(b) << std::endl; // print log(2)
	// We can also use any function from Boost.Math:
	std::cout << std::setprecision(100) << boost::math::tgamma(b) << std::endl;
	// These even work when the argument is an expression template:
	std::cout << std::setprecision(100) << boost::math::tgamma(b * b) << std::endl;

	// Access the underlying data:
	mpfr_t r;
	mpfr_init(r);
	mpfr_set(r, b.backend().data(), GMP_RNDN);


	return 0;
}
