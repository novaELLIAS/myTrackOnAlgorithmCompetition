#include <stdio.h>

#define rint register int
#define ll long long

long long n, k, modn;

inline long long poww (int x)
{
	long long base = 2 % modn, ret = 1ll;
	while (x)
	{
		if (x & 1) ret = (ret * base) % modn;
		base = (base * base) % modn;
		x >>= 1;
	}
	return ret;
}

int main ()
{
	freopen ("rabit.in","r",stdin);
	freopen ("rabit.out","w",stdout);
	
	scanf ("%lld %lld %lld", &n, &k, &modn);
	if (!(k%2)) {printf ("%lld", poww (n + 1)); return 0;}
	register long long kil = 2ll, ans = 2ll;
	while (n --)
	{
		kil = (kil << 1) % k, ans = (ans << 1) % modn;
		if (kil == 1)
		{
			ans = (ans - 1 + modn) % modn;
			printf ("%lld", (ans * poww (n)) % modn);
			return 0;
		}
	}
	printf ("%lld", ans);
	return 0;
}
