//============================================================================
// Name        : boost_gmp_int.cpp
// Author      : Hamed Mohammadi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <boost/multiprecision/gmp.hpp>

using namespace boost::multiprecision;

using namespace std;

int main(void) {
	mpz_int v = 1;

	// Do some arithmetic:
	for(unsigned i = 1; i <= 1000; ++i)
	   v *= i;

	std::cout << v << std::endl; // prints 1000!

	// Access the underlying representation:
	mpz_t z;
	mpz_init(z);
	mpz_set(z, v.backend().data());

	return 0;
}
