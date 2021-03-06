//============================================================================
// Name        : boost_circle_area.cpp
// Author      : Hamed Mohammadi
// Version     :
// Copyright   : Your copyright notice
// Description : Boost C++ libraries - circle area example
//============================================================================

#include <iostream>
#include <iomanip>
#include <boost/math/constants/constants.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

using namespace boost::multiprecision;

template<typename T>
inline T area_of_a_circle(T r) {
	using boost::math::constants::pi;
	return pi<T>() * r * r;
}

int main(int, char**) {
	const float r_f(float(123) / 100);
	const float a_f = area_of_a_circle(r_f);

	const double r_d(double(123) / 100);
	const double a_d = area_of_a_circle(r_d);

	const cpp_dec_float_50 r_mp(cpp_dec_float_50(123) / 100);
	const cpp_dec_float_50 a_mp = area_of_a_circle(r_mp);

	// 4.75292
	std::cout << std::setprecision(std::numeric_limits<float>::digits10) << a_f
			<< std::endl;

	// 4.752915525616
	std::cout << std::setprecision(std::numeric_limits<double>::digits10) << a_d
			<< std::endl;

	// 4.7529155256159981904701331745635599135018975843146
	std::cout
			<< std::setprecision(
					std::numeric_limits<cpp_dec_float_50>::digits10) << a_mp
			<< std::endl;

	return 0;
}
