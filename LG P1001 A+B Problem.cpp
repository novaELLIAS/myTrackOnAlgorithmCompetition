#pragma G++ optimize (3)

#include <iostream>
#include <future>

signed int main()
{
	std::ios::sync_with_stdio(false);
	register int a, b;
	register auto c = [&] {std::cin >> a >> b; return a+b;};
	std::future <int> d = std::async (c);
	std::cout << d.get ();
}
