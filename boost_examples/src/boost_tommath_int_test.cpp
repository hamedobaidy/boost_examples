//============================================================================
// Name        : boost_tommath_int_test.cpp
// Author      : Hamed Mohammadi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <boost/multiprecision/tommath.hpp>

using namespace std;

int main() {
	boost::multiprecision::tom_int v = 1;

	// Do some arithmetic:
	for(unsigned i = 1; i <= 1000; ++i)
	   v *= i;

	std::cout << v << std::endl; // prints 1000!
	std::cout << std::hex << v << std::endl; // prints 1000! in hex format

	try{
	   std::cout << std::hex << -v << std::endl; // Ooops! can't print a negative value in hex format!
	}
	catch(const std::runtime_error& e)
	{
	   std::cout << e.what() << std::endl;
	}

	try{
	   // v is not a 2's complement type, bitwise operations are only supported
	   // on positive values:
	   v = -v & 2;
	}
	catch(const std::runtime_error& e)
	{
	   std::cout << e.what() << std::endl;
	}

	return 0;
}
