//============================================================================
// Name        : first_boost.cpp
// Author      : Hamed Mohammadi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<boost/version.hpp>
#include <iostream>

using namespace std;

int main() {
	cout << "My first boost program with version:" <<BOOST_LIB_VERSION<< endl;
	return 0;
}
