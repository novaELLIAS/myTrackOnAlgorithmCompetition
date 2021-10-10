#pragma GCC optimize ("Ofast", 3)

#include <iostream>
#include <iomanip>

using namespace std;

signed main ()
{
	register long double n=114.514;
	std::cout << "F" << setprecision (2) << n;
	return 0;
}
