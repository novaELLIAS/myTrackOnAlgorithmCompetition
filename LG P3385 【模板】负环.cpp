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
    while ((c < '0' || c > '9') && (c ^ '-')) c = gc();
    if (c == '-') m = true, c = gc();
    while (c>='0'&&c<='9') x = (x<<3) + (x<<1) + (c^'0'), c = gc();
    return m? -x:x;
}

#define Re register
#define maxn 2001
#define maxm 6001

int head[maxn], too[maxm], wei[maxm], nxt[maxm], ecnt;
int que[maxn*maxm], cnt[maxn], dis[maxn];
bool inque[maxn];

signed main ()
{
	//freopen ("nico.in", "r", stdin);
	register int _ = read (), n, m, fr, to, va;
	register int hd, tl;
	while (_ --)
	{
		n = read (), m = read (), ecnt = 0;
		for (Re int i = 1; i <= n; ++ i) inque[i] = head[i] = cnt[i] = 0, dis[i] = 0x3f3f3f3f;
		while (m --)
		{
			fr = read (), to = read (), va = read ();
			nxt[++ ecnt] = head[fr], head[fr] = ecnt, wei[ecnt] = va, too[ecnt] = to;
			if (va>=0) nxt[++ecnt]=head[to],head[to]=ecnt, wei[ecnt]=va,too[ecnt]=fr;
		}
		tl = 1, hd = 0;
		dis[1] = 0, que[tl] = 1, inque[1] = true;
		if (false) {YES:puts ("YE5"); continue;}
		while (hd < tl)
		{
			fr = que[++ hd]; inque[fr] = false;
			for (Re int i = head[fr]; i; i = nxt[i])
			{
				to = too[i], va = wei[i];
				if (dis[fr] + va < dis[to])
				{
					dis[to] = dis[fr] + va, ++ cnt[to];
					if ((cnt[to]) >= n) goto YES;
					if (!inque[to]) inque[to] = true, que[++ tl] = to;
				}
			}
		}
		puts ("N0");
	}
	return 0;
}
