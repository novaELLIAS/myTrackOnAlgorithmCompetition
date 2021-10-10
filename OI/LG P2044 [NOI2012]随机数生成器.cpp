#pragma GCC optimize ("Ofast")

#include "stdio.h"
#include "string.h"
#define ull long long
//#define rint register int

struct node {
	ull a[2][2];
} init, work;

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

inline node xxx (node aa,node bb)
{
    node ret;
    memset (ret.a, 0ll, sizeof ret.a);
    for (int i = 0; i <= 1; i ++)
    {
        for (int j = 0; j <= 1; j ++)
        {
            for (int k = 0; k <= 1; k ++)
            {
                ret.a[i][j] += mul (aa.a[i][k], bb.a[k][j]);
                ret.a[i][j] %= m;
            }
        }
    }
    return ret;
}

node poww (node aa, ull k)
{
	if (k <= 1) return aa;
	if (!k) return init;
	node aaa = poww (aa, k >> 1);
	aaa = xxx (aaa, aaa);
	if (k & 1) aaa = xxx (aaa, aa);
	return aaa;
}

int main ()
{
	scanf ("%lld %lld %lld %lld %lld %lld", &m, &a, &c, &x, &n, &g);
	node kk; kk.a[0][0] = a, kk.a[0][1] = c, kk.a[1][0] = 0, kk.a[1][1] = 1;
	init.a[1][1] = init.a[0][0] = 1;
	node cc = poww (kk, n);
	printf ("%lld", ((x * cc.a[0][0]) + cc.a[0][1]) % g);
	return 0;
}
