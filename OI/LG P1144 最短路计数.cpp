#pragma G++ optmize (3)

#include <cstdio>

const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;
inline char gc()
{
    return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register long long x = 0; register char c = gc();
	while (c < '0' || c > '9') c = gc();
	while (c>='0'&&c<='9') x = (x<<3) + (x<<1) + (c^'0'), c = gc();
	return x;
}
static void write (long long x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}

#define Re register
#define maxn 1000001
#define maxm 4000001
#define modn 100003

int que[maxm<<5];
int head[maxn], nxt[maxm], too[maxm], ecnt;
int dis[maxn], cnt[maxn];
bool vis[maxn];

signed main ()
{
	register int n = read (), m = read (), fr, to;
	while (m --)
	{
		fr = read (), to = read ();
		nxt[++ ecnt] = head[fr], head[fr] = ecnt, too[ecnt] = to;
		nxt[++ ecnt] = head[to], head[to] = ecnt, too[ecnt] = fr;
	}
	register int hd = 0, tl = 1; que[1] = 1, cnt[1] = 1, vis[1] = true;
	while (hd < tl)
	{
		fr = que[++ hd];
		for (Re int i = head[fr]; i; i = nxt[i])
		{
			to = too[i];
			if (!vis[to]) vis[to] = true, dis[to] = dis[fr] + 1, que[++ tl] = to;
			if (dis[to] == dis[fr] + 1) cnt[to] = (cnt[to] + cnt[fr]) % modn;
		}
	}
	for (Re int i = 1; i <= n; ++ i) write (cnt[i]), putchar ('\n');
	return 0;
}
