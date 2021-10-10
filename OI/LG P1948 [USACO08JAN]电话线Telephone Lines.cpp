#pragma G++ optimize (3)
#pragma GCC optimize ("Ofast", 3)

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
	register int x = 0; register char c = gc(); register bool m = 0;
	while (c!='-'&&(c<'0'||c>'9') && c != '-') c = gc();
	if (c == '-') c = gc(), m = 1;
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return m? -x:x;
}

static void write (int x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}

inline const int& max (const int& a, const int& b) {return a>b? a:b;}

#define Re register
#define maxn 1001
#define maxp 20001

int head[maxn], nex[maxp], to[maxp], wei[maxp], ecnt;
int dis[maxn], que[10000001];
bool vis[maxn];

inline bool check (register int lim, register int k, register int n)
{
	memset (dis, 0x3f3f3f3f, sizeof dis);
	memset (vis, 0, sizeof vis);
    register int fr, am, va;
    register int frot = 0, tail = 1;
    vis[1] = true, dis[1] = 0, que[tail] = 1;
	while (frot < tail)
	{
		fr = que[++ frot];
		for (Re int i = head[fr]; i; i = nex[i])
		{
			va = dis[fr] + (wei[i] > lim);
			if (va < dis[to[i]])
			{
				dis[to[i]] = va;
				if (!vis[to[i]]) que[++ tail] = to[i], vis[to[i]] = true;
			}
		}
		vis[fr] = false;
	}
	return dis[n] <= k;
}

int main ()
{
	register int n = read (), p = read (), k = read ();
	register int x, y, w, l = 0, r = -1, mid, ans = -1;
	while (p --)
	{
		x = read (), y = read (), w = read (), r = max (r, w);
		nex[++ ecnt] = head[y], head[y] = ecnt, to[ecnt] = x, wei[ecnt] = w;
		nex[++ ecnt] = head[x], head[x] = ecnt, to[ecnt] = y, wei[ecnt] = w;
	}
	while (l <= r)
	{
		mid = (l + r) >> 1;
		if (check (mid, k, n)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	printf ("%d", ans);
	return 0;
}
