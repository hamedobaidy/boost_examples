/*
 * ratio_example.cpp
 *
 *  Created on: Jul 10, 2015
 *      Author: hamed
 */

#include <boost/ratio/ratio_io.hpp>
#include <iostream>

int main()
{
    using namespace std;
    using namespace boost;

    cout << "ratio_string<deca, char>::prefix() = "
         <<  ratio_string<deca, char>::prefix() << '\n';
    cout << "ratio_string<deca, char>::symbol() = "
         <<  ratio_string<deca, char>::symbol() << '\n';

    cout << "ratio_string<giga, char>::prefix() = "
         <<  ratio_string<giga, char>::prefix() << '\n';
    cout << "ratio_string<giga, char>::symbol() = "
         <<  ratio_string<giga, char>::symbol() << '\n';

    cout << "ratio_string<ratio<4, 6>, char>::prefix() = "
         <<  ratio_string<ratio<4, 6>, char>::prefix() << '\n';
    cout << "ratio_string<ratio<4, 6>, char>::symbol() = "
         <<  ratio_string<ratio<4, 6>, char>::symbol() << '\n';
}


