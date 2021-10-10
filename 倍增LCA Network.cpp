#prag\
ma G++ optimize ("Ofast", 3)
#pra\
gma GNU optimize ("Ofast", 3)
#prag\
ma GCC optimize ("Ofast", 3)

#include <stdio.h>
#include <vector>

using namespace std;

#define rint register int
#define maxn 200011
#define swap(x,y) y^=x^=y^=x

long long ans;
int deep[maxn], lca[maxn][21], cnt[maxn], m, ft[maxn], nt[maxn], u[maxn];
vector <int> e[maxn];

static void nico_dfs (int x, int fa)
{
	deep[x] = deep[fa] + 1;
	lca[x][0] = fa;
	for (rint i = 1; (1 << i) <= deep[x]; i ++)
	{
		lca[x][i] = lca[lca[x][i-1]][i-1];
	}
	for (rint i = ft[x]; i; i = nt[i])
	{
		if (u[i]==fa) continue;
		nico_dfs (u[i], x);
	}
}

inline int get_lca (int a, int b)
{
	register int i, j;
	if (deep[a] < deep[b]) swap (a, b);
	for (i = 0; (1 << i) <= deep[a]; i ++); i --;
	for (j = i; j >= 0; j --)
	{
		if (deep[a] >= deep[b] + (1 << j)) a = lca[a][j];
	}
	if (a == b) return a;
	for (j = i; j >= 0; j --)
	{
		if (lca[a][j] && lca[a][j] != lca[b][j])
		{
			a = lca[a][j], b = lca[b][j];
		}
	}
	return lca[a][0];
}

static void get_ans (int x, int fa)
{
	for (rint i = ft[x]; i; i = nt[i])
	{
		if (u[i] == fa) continue;
		get_ans (u[i], x);
		cnt[x] += cnt[u[i]];
		if (!cnt[u[i]]) ans += m;
		else if (cnt[u[i]] == 1) ans ++;
	}
}

int main ()
{
	register int n;;
	register int x, y, lc, sz = 1;
	scanf ("%d %d", &n, &m);
	for (rint i = 1; i <= n; i ++) ft[i] = 0;
	for (rint i = 1; i < n; i ++)
	{
		scanf ("%d %d", &x, &y);
		u[sz] = y;
		nt[sz] = ft[x];
		ft[x] = sz++;
		u[sz] = x;
		nt[sz] = ft[y];
		ft[y] = sz++;
	}
	
	nico_dfs (1, 0);
	
	for (rint i = 1; i <= m; i ++)
	{
		scanf ("%d %d", &x, &y);
		lc = get_lca (x, y);
		if (lc == x || lc == y) cnt[lc] --, cnt[x^y^lc] ++;
		else cnt[x] ++, cnt[y] ++, cnt[lc] -= 2;
	}
	
	get_ans (1, 0);
	
	printf ("%lld\n", ans);
	return 0;
}
