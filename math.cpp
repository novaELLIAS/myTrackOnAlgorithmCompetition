#include <iostream>
#include <stdio.h>
long long a, b;
int main ()
{
	freopen ("math.in","r",stdin);
	freopen ("math.out","w",stdout); 
	std::cin>>a>>b;
	std::cout<<a*b-a-b;
	return 0;
}
