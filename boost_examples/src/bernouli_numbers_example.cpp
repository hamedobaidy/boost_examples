/*
 * bernouli_numbers_example.cpp
 *
 *  Created on: Jul 10, 2015
 *      Author: hamed
 */

#include <iostream>

#include <boost/math/special_functions/bernoulli.hpp>

int main() {
	std::vector<float> bn; // Space for 32-bit `float` precision Bernoulli numbers.

	// Start with Bernoulli number 0.
	// Fill vector with even Bernoulli numbers.
	boost::math::bernoulli_b2n<float>(0, 32, std::back_inserter(bn));

	for (size_t i = 0; i < bn.size(); i++) {
		// Show vector of even Bernoulli numbers, showing all significant decimal digits.
		std::cout << std::setprecision(std::numeric_limits<float>::digits10)
				<< i * 2 << ' ' << bn[i] << std::endl;
	}
}

