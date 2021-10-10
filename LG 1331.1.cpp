#prag\
ma GCC optimize ("Ofast")

#include "stdio.h"

#define modn 10007

int a, b, k, n, m, ans, nico[1001][1001];

inline int poww (int aa, int bb)
{
	int base = aa % modn, ret = 1;
	while (bb)
	{
		if (bb & 1) ret = (ret * base) % modn;
		base = (base * base) % modn;
		bb >>= 1;
	}
	return ret % modn;
}

int main ()
{
	scanf ("%d %d %d %d %d", &a, &b, &k, &n, &m);
	a %= modn;
	b %= modn;
	a = poww (a, n);
	b = poww (b, m);
	for (register int i = 1; i <= k; i ++)
	{
		nico[i][0] = 1;
		nico[i][i] = 1;
	}
	int p = n<m? n:m;
	for (register int i = 2; i <= k; i ++)
	{
		for (register int j = 1; j <= p; j ++)
		{
			nico[i][j] = (nico[i-1][j] + nico[i-1][j-1]) % modn;
		}
	}
	ans = (a * b) % modn;
	ans = (ans * nico[k][p]) % modn;
	
	printf ("%d", ans);
	
	return 0;
}
