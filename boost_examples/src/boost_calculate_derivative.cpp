//============================================================================
// Name        : boost_calculate_derivative.cpp
// Author      : Hamed Mohammadi
// Version     :
// Copyright   : Your copyright notice
// Description : Boost C++ libraries - calculate derivatives example
//============================================================================

#include <iostream>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/math/constants/constants.hpp>
#include <boost/math/special_functions/gamma.hpp>

template<typename value_type, typename function_type>
   value_type derivative(const value_type x, const value_type dx, function_type func)
{
   // Compute d/dx[func(*first)] using a three-point
   // central difference rule of O(dx^6).

   const value_type dx1 = dx;
   const value_type dx2 = dx1 * 2;
   const value_type dx3 = dx1 * 3;

   const value_type m1 = (func(x + dx1) - func(x - dx1)) / 2;
   const value_type m2 = (func(x + dx2) - func(x - dx2)) / 4;
   const value_type m3 = (func(x + dx3) - func(x - dx3)) / 6;

   const value_type fifteen_m1 = 15 * m1;
   const value_type six_m2     =  6 * m2;
   const value_type ten_dx1    = 10 * dx1;

   return ((fifteen_m1 - six_m2) + m3) / ten_dx1;
}


int main(int, char**)
{
   using boost::math::constants::pi;
   using boost::multiprecision::cpp_dec_float_50;
   //
   // We'll pass a function pointer for the function object passed to derivative,
   // the typecast is needed to select the correct overload of std::sin:
   //
   const float d_f = derivative(
      pi<float>() / 3,
      0.01F,
      static_cast<float(*)(float)>(std::sin)
   );

   const double d_d = derivative(
      pi<double>() / 3,
      0.001,
      static_cast<double(*)(double)>(std::sin)
      );
   //
   // In the cpp_dec_float_50 case, the sin function is multiply overloaded
   // to handle expression templates etc.  As a result it's hard to take its
   // address without knowing about its implementation details.  We'll use a
   // C++11 lambda expression to capture the call.
   // We also need a typecast on the first argument so we don't accidentally pass
   // an expression template to a template function:
   //
   const cpp_dec_float_50 d_mp = derivative(
      cpp_dec_float_50(pi<cpp_dec_float_50>() / 3),
      cpp_dec_float_50(1.0E-9),
      [](const cpp_dec_float_50& x) -> cpp_dec_float_50
      {
         return sin(x);
      }
      );

   // 5.000029e-001
   std::cout
      << std::setprecision(std::numeric_limits<float>::digits10)
      << d_f
      << std::endl;

   // 4.999999999998876e-001
   std::cout
      << std::setprecision(std::numeric_limits<double>::digits10)
      << d_d
      << std::endl;

   // 4.99999999999999999999999999999999999999999999999999e-01
   std::cout
      << std::setprecision(std::numeric_limits<cpp_dec_float_50>::digits10)
      << d_mp
      << std::endl;

   cpp_dec_float_50 gd = derivative(
      cpp_dec_float_50(2),
      cpp_dec_float_50(1.0E-9),
      [](const cpp_dec_float_50& x) ->cpp_dec_float_50
      {
         return boost::math::gamma_p(2, x);
      }
   );
   // 2.70670566473225383787998989944968806815263091819151e-01
   std::cout
      << std::setprecision(std::numeric_limits<cpp_dec_float_50>::digits10)
      << gd
      << std::endl;
   // 2.70670566473225383787998989944968806815253190143120e-01
   std::cout << boost::math::gamma_p_derivative(cpp_dec_float_50(2), cpp_dec_float_50(2)) << std::endl;

   return 0;
}
