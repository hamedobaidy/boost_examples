/*
 * gcd_lcm_determination.cpp
 *
 *  Created on: Jul 10, 2015
 *      Author: hamed
 */

#include <boost/math/common_factor.hpp>
#include <algorithm>
#include <iterator>
#include <iostream>

int main()
{
   using std::cout;
   using std::endl;

   cout << "The GCD and LCM of 6 and 15 are "
   << boost::math::gcd(6, 15) << " and "
   << boost::math::lcm(6, 15) << ", respectively."
   << endl;

   cout << "The GCD and LCM of 8 and 9 are "
   << boost::math::static_gcd<8, 9>::value
   << " and "
   << boost::math::static_lcm<8, 9>::value
   << ", respectively." << endl;

   int  a[] = { 4, 5, 6 }, b[] = { 7, 8, 9 }, c[3];
   std::transform( a, a + 3, b, c, boost::math::gcd_evaluator<int>() );
   std::copy( c, c + 3, std::ostream_iterator<int>(cout, " ") );
}
