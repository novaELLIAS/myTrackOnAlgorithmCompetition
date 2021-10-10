#pragma G++ optimize ("Ofast", 3)

#include <cstdio>

static char buf[1<<14],*p1=buf,*p2=buf;
inline char gc()
{
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
}
inline long long read ()
{
	register long long x = 0; register char c = gc();
	while (c < '0' || c > '9') c = gc();
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return x;
}

typedef long long ll;
#define Re register

long long n;

inline long long qmul (Re long long a, Re long long b)
{
	Re long long ret = 0ll;
	while (b)
	{
		if (b & 1) ret += a;
		a = (a + a) % n;
		a %= n;
		ret %= n;
		b >>= 1;
	}
	return ret;
}

inline long long qpow (Re ll k, Re ll t)
{
	register ll ret = 1ll;
	while (t)
	{
		if (t&1) ret = qmul (ret, k);
		t >>= 1, k = qmul (k, k);
	}
	return ret;
}

int main ()
{
	freopen ("lsz.in", "r", stdin);
	freopen ("lsz.out","w",stdout);
	
	n = read ();
	printf ("%I64d", qpow (2, n-1ll) + 1);
	
	fclose (stdin), fclose (stdout);
	return 0;
}
