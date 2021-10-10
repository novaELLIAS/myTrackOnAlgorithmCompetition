#pragma G++ optimize (3)

#include <cstdio>
#include <cstring>

const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;
inline char gc()
{
    return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
    register int x = 0; register char c = gc(); register bool m = false;
    while ((c < '0' || c > '9') && (c ^ '-')) c = gc();
    if (c == '-') m = true, c = gc();
    while (c>='0'&&c<='9') x = (x<<3) + (x<<1) + (c^'0'), c = gc();
    return m? -x:x;
}
inline double getdou ()
{
	register double x=0;register char ch = gc ();register bool m = 0;
	while ((ch < '0' || ch > '9') && ch != '-') ch = gc ();
	if (ch == '-') ch = gc(), m = 1;
	while ('0' <= ch && ch <= '9') x = x*10 + (ch^48), ch = gc ();
	if (ch == '.')
	{
		register double s = 0.1; ch = gc ();
		while ('0' <= ch && ch <= '9') x = x + (ch^48)*s, s/=10, ch = gc ();
	}
	return m? -x:x;
}

#define Re register
#define maxn 3001
#define maxm 20001
#define eps 1e-10

int head[maxn], nxt[maxm], too[maxm], ecnt;
double wei[maxm], dis[maxn];
int n;
bool vis[maxn];

static bool SPFA (register int x, Re double mid)
{
	vis[x] = true;
	register int to; register double va;
	for (Re int i = head[x]; i; i = nxt[i])
	{
		to = too[i], va = wei[i];
		if (dis[to] > dis[x] + va - mid)
		{
			dis[to] = dis[x] + va - mid;
			if (vis[to] || SPFA (to, mid))
				{vis[x] = false; return true;}
		}
	}
	vis[x] = false; return false;
}

inline bool check (register double mid)
{
	memset (dis, 0.0, sizeof dis);
	for (Re int i = 1; i <= n; ++ i)
		if (SPFA (i, mid)) return true;
	return false;
}

int main ()
{
	n = read (); register int m = read ();
	register int fr, to; register double va;
	while (m --)
	{
		fr = read (), to = read (), va = getdou ();
		nxt[++ ecnt] = head[fr], head[fr] = ecnt,\
		too[ecnt] = to, wei[ecnt] = va;
	}
	register double l = -1e6, r = 1e6, mid;
	while (r - l > 1e-10)
	{
		mid = (l + r) / 2;
		//printf ("%.12lf\n", mid);
		if (check (mid)) r = mid;
		else l = mid;
	}
	printf ("%.8lf", l);
}
