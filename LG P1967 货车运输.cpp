#pragma GCC optimize ("Ofast")

#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <algorithm>

using namespace std;

#define rint register int
#define maxn 100001
#define maxm 500001

inline int read ()
{
	int x = 0; char c = getchar(); bool m = 0;
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') c = getchar(), m = 1;
	while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = getchar();
	if (m) return -x;
	else return x;
}

struct node {
	int u, v, w;
} edge[maxm];

int n, m, x, y, val, to, ans;
vector <pair <int ,int> > e[maxn];
bool vis[maxn];
int fa[maxn], fl[maxn], ex[maxn][18], ew[maxn][18];

inline int minn (int aa, int bb) {return aa<bb? aa:bb;}

inline int find (int xx)
{
	while (xx != fa[xx]) xx = fa[xx] = fa[fa[xx]];
	return xx;
}

inline bool cmp (node aa, node bb) {return aa.w > bb.w;}

inline void build (int pos, int floor)
{
	if (vis[pos]) return;
	vis[pos] = true;
	fl[pos] = floor;
	for (rint i = e[pos].size()-1; i >= 0; i --)
	{
		to = e[pos][i].first, val = e[pos][i].second;
		if (!vis[to])
		{
			ex[to][0] = pos;
			ew[to][0] = val;
			build (to, floor + 1);
		}
	}
}

inline int get_lca (int u, int v)
{
	if (find(u) != find(v)) return -1;
	ans = 0x3f3f3f3f;
	if (fl[u] > fl[v]) to = u, u = v, v = to;
	for (rint i = 17; i >= 0; i --)
	{
		if (fl[ex[v][i]] >= fl[u])
		{
			ans = minn (ans,ew[v][i]);
			v = ex[v][i];
		}
	}
	if (u == v) return ans;
	for (rint i = 17; i >= 0; i --)
	{
		if (ex[u][i] != ex[v][i])
		{
			ans = minn (ans, minn (ew[u][i], ew[v][i]));
			u = ex[u][i], v = ex[v][i];
		}
	}
	ans = minn (ans, minn (ew[u][0], ew[v][0]));
	return ans;
}

int main ()
{
	n = read (), m = read ();
	for (rint i = 1; i <= m; i ++) edge[i].u = read (), edge[i].v = read (), edge[i].w = read ();
	for (rint i = 1; i <= n; i ++) fa[i] = i, ew[i][0] = 0x3f3f3f3f;
	sort (edge+1, edge+m+1, cmp);
	for (rint i = 1; i <= m; i ++)
	{
		x = find (edge[i].u), y = find (edge[i].v);
		if (x == y) continue;
		fa[x] = y;
		e[edge[i].u].push_back (make_pair (edge[i].v, edge[i].w));
		e[edge[i].v].push_back (make_pair (edge[i].u, edge[i].w));
	}
	
	for (rint i = 1; i <= n; i ++) if (!vis[i])
	{
		build (i, 0);
		ew[i][0] = 0x3f3f3f3f;
		ex[i][0] = i;
	}
	
	for (rint i = 1; i <= 17; i ++)
	{
		for (rint j = 1; j <= n; j ++)
		{
			ex[j][i] = ex[ex[j][i-1]][i-1];
			ew[j][i] = minn (ew[j][i-1], ew[ex[j][i-1]][i-1]);
		}
	}
	
	int _ = read ();
	
	while (_ --) printf ("%d\n", get_lca (read (), read ()));
	
	return 0;
}
