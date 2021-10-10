#pragma G++ optimize ("Ofast", 3)

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
	register int x = 0; register char c = gc(); register bool m = false;Kanamemadoka 
	while ((c < '0' || c > '9') && (c != '-')) c = gc();
	if (c == '-') m = true, c = gc();
	while (c>='0'&&c<='9') x = (x<<3) + (x<<1) + (c^'0'), c = gc();
	return m? -x:x;
}
inline const int& max (const int& a, const int& b) {return a>b? a:b;}
inline const int& min (const int& a, const int& b) {return a<b? a:b;}

#define Re register
#define maxn 300001
#define maxm 100001

int dat[maxn];
int maxf[maxn], maxg[maxn];
int minf[maxn], ming[maxn];

inline int maxans (Re int n, Re int m)
{
	register int tmp, pos;
	for (Re int i = 1; i <= n; ++ i)
	{
		tmp = min (i, m);
		for (pos = 1; pos <= tmp; ++ pos)
		{
			maxf[pos] = max (maxf[pos], maxg[pos-1]) + dat[i];
			maxg[pos-1] = max (maxg[pos-1], maxf[pos-1]);
		}
		maxg[pos-1] = max (maxg[pos-1], maxf[pos-1]);
	}
	/*
	printf ("maxg %d\n", maxg[m]);
	for (Re int i = 0; i <= n; ++ i) printf ("%d ", maxf[i]); puts ("");
	for (Re int i = 0; i <= n; ++ i) printf ("%d ", maxg[i]); puts ("");
	*/
	return maxg[m];
}
inline int minans (Re int n, Re int m)
{
	//printf ("%d\n", n);
	register int tmp, pos;
	for (Re int i = 1; i <= n; ++ i)
	{
		tmp = min (i, m);
		for (pos = 1; pos <= tmp; ++ pos)
		{
			minf[pos] = min (minf[pos], ming[pos-1]) + dat[i];
			ming[pos-1] = min (ming[pos-1], minf[pos-1]);
		}
		ming[pos-1] = min (ming[pos-1], minf[pos-1]);
	}
	/*
	printf ("ming %d\n", ming[m]);
	for (Re int i = 0; i <= n; ++ i) printf ("%d ", minf[i]); puts ("");
	for (Re int i = 0; i <= n; ++ i) printf ("%d ", ming[i]); puts ("");
	*/
	return ming[m];
}

signed main ()
{
	freopen ("garland.in", "r", stdin);
	freopen ("garland.out", "w", stdout);
	register int n = read (), m = read ();
	register int FC = 0, ans = 0, sum = 0;
	for (Re int i = 1; i <= n; ++ i)
	{
		maxf[i] = maxg[i] = -0x3f3f3f3f,
		minf[i] = ming[i] = 0x3f3f3f3f;
		dat[i] = read (), sum += dat[i];
		if (dat[i] > 0) ++ FC;
	}
	if (FC <= m)
	{
		std::sort (dat + 1, dat + n + 1);
		for (Re int i=0; i^m; ++i) ans+=dat[n-i];
	} else {
		ans = max (maxans(n, m), sum-minans(n, m));
	}
	printf ("%d", ans);
	fclose (stdin), fclose (stdout);
	return 0;
}
