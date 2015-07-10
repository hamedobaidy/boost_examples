/*
 * legengrem10f.cpp
 *
 *  Created on: Jul 10, 2015
 *      Author: hamed
 */

#include <iostream>

#include <vector>

#include <boost/math/special_functions/legendre.hpp>

using namespace std;
using namespace boost::math;

int main() {
	double x = 0.5;  // Abscissa value
	int m = 10;      // order
	vector<double> v;
	v.push_back(legendre_p(m, m, x));
	v.push_back(legendre_p(1 + m, m, x));
	for(unsigned l = 1; l < 10; ++l)
	   v.push_back(legendre_next(l + 10, m, x, v[l], v[l-1]));
	// Double check values:
	for(unsigned l = 1; l < 10; ++l)
	   assert(v[l] == legendre_p(10 + l, m, x));

	for(int i = 0; i < v.size(); i++) {
		cout << v.at(i) << endl;
	}
}

