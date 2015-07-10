/*
 * legendre10f.cpp
 *
 *  Created on: Jul 10, 2015
 *      Author: hamed
 */
#include <vector>
#include <iostream>

#include <boost/math/special_functions/legendre.hpp>

using namespace std;

int main() {
	double x = 0.5;  // Abscissa value
	vector<double> v;
	v.push_back(boost::math::legendre_p(0, x));
	v.push_back(boost::math::legendre_p(1, x));
	for (unsigned l = 1; l < 10; ++l)
		v.push_back(boost::math::legendre_next(l, x, v[l], v[l - 1]));
	// Double check values:
	for (unsigned l = 1; l < 10; ++l)
		assert(v[l] == boost::math::legendre_p(l, x));

	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i) << endl;
	}

	return 0;
}
