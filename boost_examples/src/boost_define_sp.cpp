//============================================================================
// Name        : boost_define_sp.cpp
// Author      : Hamed Mohammadi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <boost/math/tools/promotion.hpp>
#include <boost/math/special_functions/gamma.hpp>
#include <boost/math/special_functions/bessel.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

using namespace boost::multiprecision;

template <class Float1, class Float2>
typename boost::math::tools::promote_args<Float1, Float2>::type
   JEL4(Float1 v, Float2 z)
{
   using std::pow;
   return boost::math::tgamma(v + 1) * boost::math::cyl_bessel_j(v, z) / pow(z / 2, v);
}

int main() {
	std::cout << std::scientific << std::setprecision(std::numeric_limits<cpp_dec_float_100>::digits10);
	std::cout << JEL4(cpp_dec_float_100(2) + 0.5, cpp_dec_float_100(0.5)) << std::endl;
	return 0;
}
