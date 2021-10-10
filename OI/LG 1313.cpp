#prag\
ma GCC optimize ("Ofast")

#include "stdio.h"

#define modn 10007

int a, b, k, n, m, ans = 1, val[1000001];

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
inline void nekocala (int s, int v)
{
	int xx = s;
	for (register int i = 2; i*i <= xx; i ++)
	{
		if (s % i == 0)
		{
			s /= i;
			val[i] += v;
			while (s % i == 0)
			{
				val[i] += v;
				s /= i;
			}
		}
	}
	if (s > 1) val[s] += v;
}
int main ()
{
	scanf ("%d %d %d %d %d", &a, &b, &k, &n, &m);
	a %= modn;
	b %= modn;
	
	for (register int i = k; i >= k-n+1; i --) nekocala (i, 1);
	for (register int i = 1; i <= n; i ++) nekocala (i, -1);
	for (register int i = 2; i <= k; i ++)
	{
		if (val[i] > 0) ans = (ans * poww (i, val[i])) % modn;
	}
	ans = ((ans % modn) * ((poww (a, n) * poww(b, m)) % modn));
	
	printf ("%d", ans);
	
	return 0;
}
