#pragma G++ optimize ("Ofast", 3)

#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

#define maxn 60
#define maxp 3610
#define Re register

inline char gc()
{
	static char buf[1<<14],*p1=buf,*p2=buf;
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0;register char c = gc();
	while (c < '0' || c > '9') c = gc();
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return x;
}

/****************************************************/
struct edge {
	int nex, to;
} e[maxp << 2];
int head[maxp << 1], ecnt;
inline void addedge (int u, int v)
{
	e[++ ecnt].to = v, e[ecnt].nex = head[u], head[u] = ecnt;
	e[++ ecnt].to = u, e[ecnt].nex = head[v], head[v] = ecnt;
}
/****************************************************/

const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {1, 0, -1, 0};

int n, p, hp, sta = 0, end;
int dam[maxp], dat[maxn][maxn];
bool vis[maxp], bfsvis[maxn][maxn];

static void nico_bfs (int x, int y, int typ)
{
	if (dat[x][y] ^ typ)
	{
		if (!vis[dat[x][y]])
		{
			vis[dat[x][y]] = true;
			addedge (typ, dat[x][y]);
		}
		return;
	}
	bfsvis[x][y] = true;
	register int xx, yy;
	for (Re int i = 0; i ^ 4; i ++)
	{
		xx = x + dx[i], yy = y + dy[i];
		if (xx && yy && xx <= n && yy <= n)
		{
			if (!bfsvis[xx][yy]) nico_bfs (xx, yy, typ);
		}
	}
}

/****************************************************/
struct node {
	int val, name;
	bool operator < (const node &x) const {return val > x.val;}
};
priority_queue <node> nico;
int dis[maxp];

inline void dijkstra ()
{
	memset (dis, 0x3f3f3f3f, sizeof dis);
	register int fro, to, va;
	nico.push((node) {0, sta}); dis[sta] = 0;
	while (!nico.empty())
	{
		fro = nico.top().name, nico.pop();
		if (vis[fro]) continue;
		vis[fro] = true;
		for (Re int i = head[fro]; i != (-1); i = e[i].nex)
		{
			to = e[i].to, va = dam[to];
			if (!vis[to] && dis[fro] + va < dis[to])
			{
				dis[to] = dis[fro] + va;
				nico.push((node) {dis[to], to}); 
			}
		}
	}
}
/****************************************************/

int main ()
{
	freopen ("eldrethalas.in","r",stdin);
	freopen ("eldrethalas.out","w",stdout);
	/****************************************************/
	memset (head, -1, sizeof head);
	n = read (), p = read (), hp = read (), end = p + 1;
	for (Re int i = 1; i <= p; ++ i) dam[i] = read ();
	for (Re int i = 1; i <= n; ++ i) for (Re int j = 1; j <= n; ++ j) dat[i][j] = read ();
	/****************************************************/
	for (Re int i = 1; i <= n; ++ i) if (!vis[dat[1][i]]) vis[dat[1][i]] = true, addedge(sta, dat[1][i]);
	memset (vis, 0, sizeof vis);
	
	for (Re int i = 1; i <= n; ++ i) if (!vis[dat[n][i]]) vis[dat[n][i]] = true, addedge(end, dat[n][i]);
	memset (vis, 0, sizeof vis);
	
	for (Re int i = 1; i <= n; ++ i)
	{
		for (Re int j = 1; j <= n; ++ j)
		{
			if (!bfsvis[i][j])
			{
				nico_bfs (i, j, dat[i][j]);
				memset (vis, 0, sizeof vis);
			}
		}
	}
	/****************************************************/
	dijkstra ();
	/****************************************************/
	if (dis[end] >= hp) puts ("NO");
	else printf ("%d", hp - dis[end]);
	/****************************************************/
	return 0;
}
