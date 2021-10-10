#pragma GCC optimize ("Ofast", 3)
#pragma G++ optimize ("Ofast", 3)
#pragma GNU optimize ("Ofast", 3)

#include <stdio.h>
#include <vector>

using namespace std;

#define maxn 100101
#define dmax 400101

#define rint register int
#define swap(x,y) y^=x^=y^=x

struct TreeNode {
	int l, r;
	long long sum, laz;
} dat[dmax];

int fa[maxn], id[maxn], son[maxn], dep[maxn], siz[maxn], top[maxn];
int twei[maxn], wei[maxn], id_cnt;

vector <int> e[maxn];

void dfs1 (int pt)
{
	siz[pt] = 1;
	register int maxx = -1, to;
	for (rint i = e[pt].size() - 1; i >= 0; i --)
	{
		to = e[pt][i];
		if (dep[to]) continue;
		dep[to] = dep[pt] + 1, fa[to] = pt;
		dfs1 (to);
		siz[pt] += siz[to];
		if (siz[to] > maxx) maxx = siz[to], son[pt] = to;
	}
}

inline void dfs2 (int pt, int fr)
{
	id[pt] = ++ id_cnt, wei[id_cnt] = twei[pt], top[pt] = fr;
	if (!son[pt]) return;
	dfs2 (son[pt], fr);
	register int to;
	for (rint i = e[pt].size()-1; i >= 0; i --)
	{
		to = e[pt][i];
		if (to == fa[pt] || to == son[pt]) continue;
		dfs2 (to, to);
	}
}

static void build (int rt, int l, int r)
{
	dat[rt].l = l, dat[rt].r = r;
	if (l == r) {dat[rt].sum = wei[l]; return;}
	register int mid = (l + r) >> 1;
	build (rt<<1, l, mid); build (rt<<1|1, mid+1, r);
	dat[rt].sum = dat[rt<<1].sum + dat[rt<<1|1].sum;
}

inline void pushdown (int rt)
{
	if (!dat[rt].laz || dat[rt].l == dat[rt].r) return;
	register int lson = rt<<1, rson = rt<<1|1;
	dat[lson].laz += dat[rt].laz, dat[rson].laz += dat[rt].laz;
	dat[lson].sum += dat[rt].laz * (dat[lson].r - dat[lson].l + 1);
	dat[rson].sum += dat[rt].laz * (dat[rson].r - dat[rson].l + 1);
	dat[rt].laz = 0;
} 

static void update (int rt, int l, int r, int val)
{
	if (l <= dat[rt].l && dat[rt].r <= r)
	{
		dat[rt].laz += val, dat[rt].sum += (long long)val * (dat[rt].r - dat[rt].l + 1);
		return;
	}
	pushdown (rt);
	register int mid = (dat[rt].l + dat[rt].r) >> 1;
	if (l <=mid) update (rt<<1, l, r, val);
	if (r > mid) update (rt<<1|1,l,r, val);
	dat[rt].sum = dat[rt<<1].sum + dat[rt<<1|1].sum;
}

static long long tree_query (int rt, int l, int r)
{
	if (l <= dat[rt].l && dat[rt].r <= r) return dat[rt].sum;
	pushdown (rt);
	register int mid = (dat[rt].l + dat[rt].r) >> 1;
	register long long ret = 0ll;
	if (l <=mid) ret  = tree_query (rt<<1, l, r);
	if (r > mid) ret += tree_query (rt<<1|1,l,r);
	return ret;
}

inline long long range_query (int x, int y)
{
	register long long ret = 0;
	while (top[x] != top[y])
	{
		if (dep[top[x]] < dep[top[y]]) swap (x, y);
		ret = (ret + tree_query (1, id[top[x]], id[x]));
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap (x, y);
	return (ret + tree_query (1, id[x], id[y]));
}

inline void range_update (int x, int y, int val)
{
	while (top[x] != top[y])
	{
		if (dep[top[x]] < dep[top[y]]) swap (x, y);
		update (1, id[top[x]], id[x], val);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap (x, y);
	update (1, id[x], id[y], val);
}

inline void son_update (int rt, int val) {update (1, id[rt], id[rt] + siz[rt] - 1, val);}

inline void point_update (int rt, int val) {update (1, id[rt], id[rt], val);}

int main ()
{
	register int n, m; scanf ("%d %d", &n, &m);
	for (rint i = 1; i <= n; i ++) scanf ("%d", &twei[i]);
	register int x, y, opt;
	for (rint i = 1; i < n; i ++)
	{
		scanf ("%d %d", &x, &y);
		e[x].push_back(y), e[y].push_back(x);
	}
	dep[1] = 1; dfs1 (1); dfs2 (1,1); build (1, 1, n);
	while (m --)
	{
		scanf ("%d %d", &opt, &x);
		if (opt == 1) scanf ("%d", &y), point_update (x, y);
		else if (opt == 2) scanf ("%d", &y), son_update (x, y);
		else printf ("%I64d\n", range_query (1, x));
	}
	return 0;
}
