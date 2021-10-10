#pragma GCC optimize ("Ofast", 3)

#include <cstdio>
#include <iostream>

inline void func (int n) {
	if (~n) throw "NMSL";
	std::cout<<n<<std::endl;
}

signed main () {
	register int n = 0;
	try {
		func(0);
	} catch (const char* s) {
		std::cout<<s<<std::endl;
	} return 0;
}
