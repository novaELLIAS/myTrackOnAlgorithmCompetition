#pragma GCC optmize ("Ofast", 3)

#include <cstdio>
#include <queue>

using std::queue;

#define Re register
#define maxn 10001
#define maxm 500001

const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;
inline char gc()
{
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0; register char c = gc(); register bool m = 0;
	while ((c < '0' || c > '9') && (c ^ '-')) c = gc();
	if (c == '-') c = gc(), m = true;
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return m? -x:x;
}
static void write (int x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}
static void writelen (int x) {if(x<0)x=-x,putchar('-'); write (x); putchar ('\n');}
static void writespa (int x) {if(x<0)x=-x,putchar('-'); write (x); putchar (' ');}

bool vis[maxn];
int dis[maxn];
const long long inf = 2147483647ll;

int head[maxn], nxt[maxm], too[maxm], wei[maxm], ecnt;

queue <int> que;

signed main ()
{
	register int n=read(), m=read(), s=read();
	register int fr, to, va, i; que.push (s);
	for (i=1; i<=n; ++i) dis[i]=inf; dis[s]=0;
	while (m --)
	{
		fr=read(), to=read(), va=read();
		nxt[++ ecnt]=head[fr], head[fr]=ecnt, too[ecnt]=to, wei[ecnt]=va;
	}
	while (!que.empty())
	{
		fr=que.front(), que.pop(), vis[fr]=false;
		for (i=head[fr]; i; i=nxt[i])
		{
			to=too[i], va=wei[i];
			if (dis[fr] + va < dis[to])
			{
				dis[to]=dis[fr]+va;
				if (!vis[to]) vis[to]=true, que.push(to);
			}
		}
	}
	for (i=1; i<=n; ++i) writespa (dis[i]);
	return 0;
}
