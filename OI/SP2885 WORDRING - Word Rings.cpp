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
    register int x = 0; register char c = gc();
    while ((c < '0' || c > '9')) c = gc();
    while (c>='0'&&c<='9') x = (x<<3) + (x<<1) + (c^'0'), c = gc();
    return x;
}

#define Re register
#define maxn 110001
#define maxx 800
#define eps 1e-4

int head[maxx], nxt[maxn], too[maxn], wei[maxn], ecnt;
int hash[maxx], hhsh;
double dis[maxx];
bool vis[maxx];

inline int calc (Re char c1, Re char c2) {
	return ((c1 - 'a') * 26 + c2 - 'a' + 1);
}
inline void addedge (Re int fr, Re int to, Re int va) {
	nxt[++ ecnt] = head[fr], head[fr] = ecnt, wei[ecnt] = va, too[ecnt] = to;
}

static bool spfa_dfs (Re int fr, Re double mid)
{
	vis[fr] = true;
	register int to;
	for (Re int i = head[fr]; i; i = nxt[i])
	{
		to = too[i];
		if (dis[fr] + wei[i] - mid > dis[to])
		{
			dis[to] = dis[fr] + wei[i] - mid;
			if (vis[to] || spfa_dfs(to, mid))
				{vis[fr] = false; return true;}
		}
	}
	vis[fr] = false; return false;
}

inline bool judge (register double mid)
{
	memset (dis, 0, sizeof dis);
	for (Re int i = 1; i <= hhsh; ++ i)
		if (spfa_dfs (i, mid)) return true;
	return false;
}

signed main ()
{
	freopen ("nico.in","r",stdin);
	register int len, n, fr, to;
	register double l, r, mid;
	register char c, s[1011];
	while (true)
	{
		n = read (); if (!n) return 0;
		memset (head, 0, sizeof head);
		memset (hash, 0, sizeof hash);
		ecnt = hhsh = 0;
		while (n --)
		{
			c = gc(), len = 0;
			while (c == '\n' || c == '\r') c = gc ();
			while ((c != '\n') && (c != '\r')) s[++ len] = c, c = gc();
			fr = calc(s[1], s[2]), to = calc(s[len-1], s[len]);
			if (!hash[fr]) hash[fr] = ++ hhsh;
			if (!hash[to]) hash[to] = ++ hhsh;
			addedge (hash[fr], hash[to], len);
		}
		l = 0.0, r = 1000.0;
		while (r - l >= eps)
		{
			mid = (l + r) / 2;
			if (judge(mid)) l = mid;
			else r = mid;
		}
		if (l == 0) puts ("No solution.");
		else printf ("%.2lf\n", l);
	}
	return 0;
}
