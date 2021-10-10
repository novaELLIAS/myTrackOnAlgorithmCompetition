#include "stdio.h"
#include <stack>

using namespace std;

inline int fastread ();
inline void fastwrite (int);
inline void fastwriteline (int);
inline void fastwritespace (int);

#define maxn 80001

int n, in;
stack <int> nico;
long long ans;

int main ()
{
	n = fastread ();
	for (int i = 1; i <= n; i ++)
	{
		in = fastread ();
		while (!nico.empty() && nico.top() <= in) nico.pop();
		ans += nico.size();
		nico.push(in); 
	}
	printf("%lld", ans);
	return 0;
}

inline int fastread ()
{
	int sign = 1, n = 0;
	char c = getchar();
	while(c < '0' || c > '9')
	{
		if(c == '-') sign = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9')
	{
		n = n*10 + c-'0';
		c = getchar();
	}
	return sign*n;
}
inline void fastwrite (int x)
{
	if(x < 0) x = -x, putchar('-');
	if(x > 9) fastwrite(x / 10);
	putchar(x%10 + '0');
}
inline void fastwritespace (int x)
{
	fastwrite(x);
	putchar(' ');
}
inline void fastwriteline (int x)
{
	fastwrite(x);
	putchar('\n');
}
