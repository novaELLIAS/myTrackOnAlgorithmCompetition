#pragma G++ optimize (3)

#include <cstdio>
#include <algorithm>

using std::sort;
using std::__gcd;

const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;
inline char gc()
{
    return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0; register char c = gc(); //register bool m = false;
	while ((c < '0' || c > '9')/* && (c ^ '-')*/) c = gc();
	//if (c == '-') m = true, c = gc ();
	while (c>='0'&&c<='9') x = (x<<3) + (x<<1) + (c^'0'), c = gc();
	return /*m? -x:*/x;
}

inline const int max (const int& a, const int& b) {return a>b? a:b;}
inline const int min (const int& a, const int& b) {return a<b? a:b;}

#define Re register
#define maxn 100001
#define sqr(x) ((x)*(x))

int dat[maxn];
int mov[maxn][2];

bool vis[maxn];
int len[maxn], lcnt;

signed main ()
{
	register int n = read (), k = read ();
	register int now, pos;
	
	register int to = k&1, fr = !to;
	for (Re int i = 1; i <= n; ++ i)
		dat[i] = read (), mov[i][fr] = i;
	
	for (Re int i = 1; i <= n; ++ i)
	{
		if (!vis[i])
		{
			vis[i] = true, pos = i, now = dat[i], len[++ lcnt] = 1;
			while (now ^ pos) vis[now] = true, ++ len[lcnt], now = dat[now];
		}
	}
	
	register int modn = len[1];
	for (Re int i = 2; i <= lcnt; ++ i) modn = modn*len[i]/__gcd(modn, len[i]);
	k %= modn;
	
	if (!k) {for (Re int i = 1; i <= n; ++ i) printf ("%d ", dat[i]); return 0;}
	
	while (k --)
		for (Re int i = 1; i <= n; ++ i)
			fr = k&1, to = !fr, mov[dat[i]][to] = mov[i][fr];
	for (Re int i = 1; i <= n; ++ i) printf ("%d ", mov[i][to]);
	return 0;
}
