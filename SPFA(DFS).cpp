#pragma G++ optimize (3)

#include <cstdio>

const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;
inline char gc()
{
    return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0; register char c = gc(); register bool m = false;
	while ((c < '0' || c > '9') && c ^ '-') c = gc();
	if (c == '-') m = true, c = gc();
	while (c>='0'&&c<='9') x = (x<<3) + (x<<1) + (c^'0'), c = gc();
	return m? -x:x;
}
static void write (int x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}
inline const int& min (const int& a, const int& b) {return a<b? a:b;}

#define Re register
#define maxn 10001
#define maxm 500001

int head[maxn], nxt[maxm], too[maxm], wei[maxm], dis[maxn], ecnt;
bool vis[maxn];

inline void dfs_SPFA (register int x)
{
	vis[x] = true;
	for (Re int i = head[x]; i; i = nxt[i])
		if (dis[too[i]] > dis[x] + wei[i])
			{dis[too[i]] = dis[x] + wei[i];if (!vis[too[i]]) dfs_SPFA (too[i]);}
	vis[x] = false;
}

signed main ()
{
	register int n = read (), m = read (), sta = read ();
	for (Re int i = 1; i <= n; ++ i) dis[i] = 2147483647;
	register int fr, to, va;
	while (m --)
	{
		fr = read (), to = read (), va = read ();
		nxt[++ ecnt] = head[fr], head[fr] = ecnt, too[ecnt] = to, wei[ecnt] = va;
	}
	dis[sta] = 0;
	dfs_SPFA (sta);
	for (Re int i = 1; i <= n; ++ i)
	{
		if (dis[i]<0) dis[i] = -dis[i], putchar ('-');
		write (dis[i]), putchar (' ');
	}
	return 0;
}
