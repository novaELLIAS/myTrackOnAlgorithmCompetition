#pragma GCC optimize ("Ofast", 3)

#include <cstdio>
#include <queue>
#include <cstring>

using std::priority_queue;

#define Re register
#define maxn 100001
#define maxm 200001

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
static void writespa(int x) {if(x<0)x=-x,putchar('-');write(x),putchar(' ');}

struct node {
	int id, val;
	bool operator < (const node a) const {
		return val > a.val;
	}
};

int dis[maxn];
bool vis[maxn];
int head[maxn], nxt[maxm], too[maxm], wei[maxm], ecnt;
priority_queue <node> que;

signed main ()
{
	register int n=read(), m=read(), s=read();
	register int fr, to, va, i;
	memset (dis, 0x3f3f3f3f, sizeof dis);
	dis[s]=0; que.push({s, 0}); 
	while (m --)
	{
		fr=read(), to=read(), va=read();
		nxt[++ ecnt]=head[fr], head[fr]=ecnt, too[ecnt]=to, wei[ecnt]=va;
	} fclose (stdin);
	while (!que.empty())
	{
		fr=que.top().id, que.pop();
		if (!vis[fr])
		{
			vis[fr]=true;
			for (i=head[fr]; i; i=nxt[i])
			{
				to=too[i], va=wei[i];
				if (dis[fr]+va<dis[to])
				{
					dis[to]=dis[fr]+va;
					que.push({to, dis[to]});
				}
			}
		}
		
	}
	for (i=1; i<=n; ++i) writespa (dis[i]);
	fclose (stdout); return 0;
}
