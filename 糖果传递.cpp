#prag\
ma G++ optimize ("Ofast", 3)
#prag\
ma GCC optimize ("Ofast", 3)
#prag\
ma GCC target ("sse3","sse2","sse")
#prag\
ma GCC target ("avx","sse4","sse4.1","sse4.2","ssse3")
#prag\
ma GCC target ("f16c")
#prag\
ma G++ target ("sse3","sse2","sse")
#prag\
ma G++ target ("avx","sse4","sse4.1","sse4.2","ssse3")
#prag\
ma G++ target ("f16c")

#include <cstdio>
#include <cctype>
#include <cmath>
#include <algorithm>

#define rint register int
#define maxn 1000001
#define ll long long

using namespace std;

const int str = 1 << 20;
char buf[str], *s, *tt;

inline char gc() { return s==tt&&((tt=(s=buf)+fread(buf,1,str,stdin))==s)?EOF:(*s++);}

inline ll read ()
{
	ll x = 0; char c = gc();
	while (!isdigit(c)) c = gc();
	while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
	return x;
}

ll n, a[maxn], ave, sum[maxn], ans, t;

int main ()
{
	n = read ();
	for (rint i = 1; i <= n; i ++) a[i] = read (), ave += a[i];
	ave /= n;
	for (rint i = 1; i <= n; i ++) a[i] -= ave - a[i-1];
	t = (n+1)>>1; nth_element(a+1, a+t, a+n+1);
	for (rint i = 1; i <= n; i ++) ans += abs (a[i] - a[t]);
	printf ("%I64d", ans);
	return 0;
}

