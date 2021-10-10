#prag\
ma GCC optimize ("Ofast", 3)
#prag\
ma G++ optimize ("Ofast", 3)
#prag\
ma GNU optimize ("Ofast", 3)

#include <stdio.h>
#include <vector>

using namespace std;

#define maxn 100101
#define dmax 2000101

#define rint register int
#define swap(x,y) y^=x^=y^=x

struct TreeNode {
	int l, r;
	long long sum, max;
} dat[dmax];

int fa[maxn], id[maxn], son[maxn], dep[maxn], siz[maxn], top[maxn];
int twei[maxn], wei[maxn], id_cnt, root[maxn];

vector <int> e[maxn];

inline const long long& max (const long long& a, const long long& b) {return a>b? a:b;}
inline const long long& min (const long long& a, const long long& b) {return a<b? a:b;}

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

inline void pushup (int rt)
{
	register int lson = rt<<1, rson = rt<<1|1;
	dat[rt].sum = dat[lson].sum + dat[rson].sum;
	dat[rt].max = max (dat[lson].max, dat[rson].max);
}

static void build (int rt, int l, int r)
{
	dat[rt].l = l, dat[rt].r = r;
	if (l == r) {dat[rt].sum = dat[rt].max = wei[l]; return;}
	register int mid = (l + r) >> 1;
	build (rt<<1, l, mid); build (rt<<1|1, mid+1, r);
	update (rt);
}

static long long tree_sum_query (int rt, int l, int r)
{
	if (l <= dat[rt].l && dat[rt].r <= r) return dat[rt].sum;
	pushdown (rt);
	register int mid = (dat[rt].l + dat[rt].r) >> 1;
	register long long ret = 0ll;
	if (l <=mid) ret  = tree_query (rt<<1, l, r);
	if (r > mid) ret += tree_query (rt<<1|1,l,r);
	return ret;
}

static long long tree_max_query (int rt, int l, int r)
{
	if (l <= dat[rt].l && dat[rt].r <= r) return dat[rt].max;
	pushdown (rt);
	register int mid = (dat[rt].l + dat[rt].r) >> 1;
	register long long ret = 0ll;
	if (l <=mid) ret = max (ret, tree_max_query (rt<<1, l, r));
	if (r > mid) ret = max (ret, tree_max_query (rt<<1|1,l,r));
	return ret;
}

inline long long range_sum_query (int rt, int x, int y)
{
	register long long ret = 0;
	while (top[x] != top[y])
	{
		if (dep[top[x]] < dep[top[y]]) swap (x, y);
		ret += (tree_sum_query (root[rt], id[top[x]], id[x]));
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap (x, y);
	return (ret + tree_sum_query (root[rt], id[x], id[y]));
}

inline long long range_max_query (int rt, int x, int y)
{
	register long long ret = 0;
	while (top[x] != top[y])
	{
		if (dep[top[x]] < dep[top[y]]) swap (x, y);
		ret = max (ret, tree_max_query (root[rt], id[top[x]], id[x]));
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap (x, y);
	return max (ret, tree_query (root[rt], id[x], id[y]));
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
