#pragma G++ optmize (3)

#include <cstdio>
#include <algorithm>

const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;
inline char gc()
{
    return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0; register char c = gc();
	while ((c < '0' || c > '9')) c = gc();
	//if (c == '-') m = true, c = gc ();
	while (c>='0'&&c<='9') x = (x<<3) + (x<<1) + (c^'0'), c = gc();
	return x;
}

using std::sort;

#define Re register
#define maxn 301
#define sqr(x) ((x)*(x))
typedef long long ll;

signed main ()
{
	register int dat[301]; dat[0] = 0;
	register int n = read ();
	for (Re int i = 1; i <= n; ++ i) dat[i] = read ();
	sort (dat + 1, dat + n + 1);
	register long long ans = 0ll;
	register int l = 1, r = n, las = 0;
	register bool psi = 0;
	while (n --)
	{
		if (psi) ans += sqr(dat[l] - las), las = dat[l ++], psi =0;
		else ans += sqr(dat[r] - las), las = dat[r --], psi = true;
	}
	printf ("%lld", ans);
	return 0;
}
