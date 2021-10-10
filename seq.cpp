#pragma G++ optimize ("Ofast", 3)

#include <cstdio>

typedef long long ll;
#define Re register
#define rint register int
const ll modn = 1e18;

long long qmul (long long a,long long b)
{
	long long ret = 0ll;
	while (b)
	{
		if (b & 1) ret += a;
		a = (a + a) % modn;
		a %= modn;
		ret %= modn;
		b >>= 1;
	}
	return ret;
}

struct node {
	unsigned long long a[4][4];
} nico, one, zero, ans;

inline node xxx (node aa, node bb)
{
	node ret = zero;
	for (rint i = 0; i <= 3; i ++)
	{
		for (rint j = 0; j <= 3; j ++)
		{
			for (rint k = 0; k <= 3; k ++)
			{
				ret.a[i][j] += qmul(aa.a[i][k] , bb.a[k][j]), ret.a[i][j] %= modn;
			}
		}
	}
	return ret;
}

inline void poww (node k, ll t)
{
	ans = nico;
	while (t)
	{
		if (t&1) ans = xxx (ans, k);
		t >>= 1, k = xxx (k, k);
	}
}

int main ()
{
	freopen ("seq.in", "r", stdin);
	freopen ("seq.out","w",stdout);
	
	register long long a0, a1, a2, b, c, d, e, n;
	scanf ("%I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d", &a0, &a1, &a2, &b, &c, &d, &e, &n);
	
	if (!n) return printf ("%I64d", a0), 0;
	else if (n == 1) return printf ("%I64d", a1), 0;
	else if (n == 2) return printf ("%I64d", a2), 0;
	
	one.a[0][0] = one.a[1][1] = one.a[2][2] = one.a[3][3] = 1ll;
	/*
	one.a = {
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1}
	};
	*/
	nico.a[0][0] = b, nico.a[0][1] = c, nico.a[0][2] = d, nico.a[0][3] = 1ll;
	nico.a[1][0] = nico.a[2][1] = nico.a[3][3] = 1ll;
	
	/*
	nico.a = {
		{b, c, d, 1},
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 0, 1}
	};
	*/
	
	poww (nico, (n-3)*1ll);
	
	//printf ("%I64d", ans.a[0][0]*a2+ans.a[0][1]*a1+ans.a[0][2]*a0+ans.a[0][3]*e);
	
	register ll res = ((qmul(ans.a[0][0],a2)+qmul(ans.a[0][1],a1))%modn+qmul(ans.a[0][2],a0)+qmul(ans.a[0][3],e))%modn;
	register ll out = res;
	register ll cnt = 0;
	while (res) res/=10, ++ cnt;
	cnt = 18 - cnt;
	while (cnt --) putchar ('0');
	printf ("%I64d", out);
	
	fclose (stdin), fclose (stdout);
	return 0;
}
