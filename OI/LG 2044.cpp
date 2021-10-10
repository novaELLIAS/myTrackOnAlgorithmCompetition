#pragma GCC optimize ("Ofast")

#include "stdio.h"
#include "string.h"

#define ull long long
#define rint register int

struct node {
	ull a[3][3];
} init;

ull m, a, c, x, n, g;

inline ull mul (ull a, ull b)
{ 
    ull ans = 0ll;
    a %= m; b %= m;
    while (b)
    {
        if (b&1) ans = (ans+a) % m;
        a = (a<<1) % m;
        b >>= 1;
    }
    return ans % m;
}

node operator * (node aa, node bb)
{
	node ret;
	memset (ret.a, 0ll, sizeof ret.a);
	ret.a[1][1] = ret.a[2][1] = ret.a[1][2] = ret.a[2][2] = 0;
	for (rint i = 1; i <= 2; i ++)
	{
		for (rint j = 1; j <= 2; j ++)
		{
			for (rint k = 1; k <= 2; k ++)
			{
				ret.a[i][j] += mul (aa.a[i][k], bb.a[k][j]);
				ret.a[i][j] %= m;
			}
		}
	}
	return ret;
}

inline node poww (node aa, ull k)
{
	//puts ("check");
	//printf ("check %d\n", k);
	if (!k) return init;
	node temp = poww (aa, k>>1);
	temp = temp * temp;
	if (k&1) temp = temp * aa;
	return temp;
}

int main ()
{
	scanf ("%I64d %I64d %I64d %I64d %I64d %I64d", &m, &a, &c, &x, &n, &g);
	node kk; kk.a[1][1] = a; kk.a[1][2] = c; kk.a[2][1] = 0; kk.a[2][2] = 1;
	init.a[1][1] = init.a[2][2] = 1;
	node cc = poww (kk, n);
	/*
	for (rint i = 1; i <= 2; i ++)
	{
		for (rint j = 1; j <= 2; j ++)
		{
			printf ("%d ", cc.a[i][j]);
		}
		puts ("");
	}
	*/
	node tle; tle.a[1][1] = x, tle.a[2][1] = 1; tle.a[2][2] = tle.a[1][2] = 0;
	cc = cc * tle;
	/*
	for (rint i = 1; i <= 2; i ++)
	{
		for (rint j = 1; j <= 2; j ++)
		{
			printf ("%d ", cc.a[i][j]);
		}
		puts ("");
	}
	*/
	printf ("%I64d", cc.a[1][1] % g);
	return 0;
}
