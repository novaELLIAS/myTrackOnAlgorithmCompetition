#pragma G++ optimize (3)
#pragma GCC optimize ("Ofast", 3)

#include <cstdio>

#define Re register
typedef long long ll;

static ll gcd (ll a, ll b) {return b? gcd(b,a%b):a;}

signed main ()
{
	register ll n; scanf ("%lld", &n);
	register long long p = 0, q = 1, g;
	for (Re int i = 1; i <= n; ++ i)
	{
		p = p * i + q * n, q *= i;
		p /= (g = gcd(p, q)), q /= g;
	}
	
	if (q == 1ll) printf ("%lld", p);
	else {
		Re ll ret = p/q, c = q, rcnt = 0, ccnt = 0, r = ret;
		while (r) r /= 10, ++ rcnt;
		while (c) c /= 10, ++ ccnt;
		for (Re int i = 1; i <= rcnt; ++ i) putchar (' ');
		printf ("%lld\n%lld", p-q*ret, ret);
		while (ccnt --) putchar ('-'); putchar ('\n');
		while (rcnt --) putchar (' ');
		printf ("%lld", q);
	}
    
    return 0;
}
