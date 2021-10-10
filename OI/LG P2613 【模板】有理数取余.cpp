#pragma GCC optimize (3)

#include <cstdio>

#define Re register
#define modn 19260817ll

const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;
inline char gc()
{
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline long long read ()
{
	register long long x = 0; register char c = gc(); register bool m = false;
	while ((c < '0' || c > '9') && (c ^ '-')) c = gc();
	if (c == '-') m = true, c = gc ();
	while (c>='0'&&c<='9') x = (((x<<3) + (x<<1)) % modn + (c^'0')) % modn, c = gc();
	return m? -x:x;
}

inline long long qpow (Re long long a, Re long long b)
{
	register long long base = a, ret = 1ll;
	while (b)
	{
		if (b&1) (ret *= base) %= modn;
		(base *= base) %= modn, b >>= 1;
	}
	return ret % modn;
}

signed main ()
{
	register long long a = read (), b = read ();
	if (!b) return printf ("Angry!"), 0;
	else printf ("%lld", a * qpow(b, modn - 2) % modn);
	return 0;
}
