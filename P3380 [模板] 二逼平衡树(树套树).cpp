#pragma GCC optimize ("Ofast")

#include "stdio.h"
#include "iostream"

using namespace std;

#define maxn 5000005
#define rint register int
#define lc (o<<1)
#define mid ((l+r)>>1)
#define rc (o<<1|1)

inline int read()
{
	int x=0,t=1;
	char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')t=-1,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return x*t;
}

const int INF = 2147483647;
int n, m, root, tot, ans, maxx;
int a[maxn], data[maxn], size[maxn], ch[maxn][2], fa[maxn], rt[maxn], cnt[maxn];

inline void push_up (int u)
{
	size[u] = (ch[u][0]? size[ch[u][0]]:0) + (ch[u][1]? size[ch[u][1]]:0) + cnt[u];
}

inline void rotate (int x)
{
	int y = fa[x], z = fa[y];
	bool f = ch[y][1] == x;
	ch[y][f] = ch[x][f^1];
	if (ch[x][f^1]) fa[ch[x][f^1]] = y;
	fa[x] = z;
	if (z) ch[z][ch[z][1] == y] = x;
	fa[y] = x;
	ch[x][f^1] = y;
	push_up(y);
	push_up(x);
}

inline void splay(int pos, int x, int to)
{
	int y, z;
	while (fa[x] != to)
	{
		y = fa[x], z = fa[y];
		if (z != to) rotate ((ch[z][0] == y) == (ch[y][0] == x) ? y : x);
		rotate (x);
	}
	if (!to) rt[pos] = x;
}

inline void splay_insert (int pos, int val)
{
	register int prt = rt[pos], last = 0;
	if (!prt)
	{
		rt[pos] = prt = ++ tot;
		data[prt] = val;
		size[prt] = cnt[prt] = 1;
		fa[prt] = ch[prt][0] = ch[prt][1] = 0;
		return;
	}
	while (true)
	{
		if (data[prt] == val)
		{
			cnt [prt] ++;
			push_up (last);
			break;
		}
		last = prt;
		prt = ch[prt][val > data[prt]];
		if (!prt)
		{
			prt = ++ tot;
			data[prt] = val;
			size[prt] = cnt[prt] = 1;
			ch[last][val > data[last]] = prt;
			fa[prt] = last;
			ch[prt][0] = ch[prt][1] = 0;
			push_up (last);
			break;
		}
	}
	splay (pos, prt, 0);
}

inline int splay_find (int pos, int val)
{
	register int x = rt[pos];
	while (x)
	{
		if (data[x] == val)
		{
			splay (pos, x, 0);
			return x;
		}
		x = ch[x][val > data[x]];
	}
}

inline int splay_rank (int pos, int val)
{
	register int prt = rt[pos], ret = 0;
	while (prt)
	{
		if (data[prt] == val) return ret + ((ch[prt][0])? size[ch[prt][0]]:0);
		if (data[prt] < val)
		{
			ret += ((ch[prt][0])? size[ch[prt][0]]:0) + cnt[prt];
			prt = ch[prt][1];
		}
		else prt = ch[prt][0];
	}
	return ret;
}

inline void splay_clear(int x)
{
	fa[x] = ch[x][0] = ch[x][1] = size[x] = cnt[x] = data[x] = 0;
}

inline int splay_pre (int i)
{
	int x = ch[rt[i]][0];
	while (ch[x][1]) x = ch[x][1];
	return x;
}
inline int splay_suc (int i)
{
	int x = ch[rt[i]][1];
	while (ch[x][0]) x = ch[x][0];
	return x;
}

inline void splay_delete(int i, int key)
{
	int x = splay_find (i, key);
	if (cnt[x] > 1)
	{
		cnt[x] --;
		push_up (x);
		return;
	}
	if (!ch[x][0] && !ch[x][1])
	{
		splay_clear(rt[i]);
		rt[i] = 0;
		return;
	}
	if (!ch[x][0])
	{
		int y = ch[x][1];
		rt[i] = y;
		fa[y] = 0;
		return;
	}
	if (!ch[x][1])
	{
		int y = ch[x][0];
		rt[i] = y;
		fa[y] = 0;
		return;
	}
	int p = splay_pre (i);
	int oldrt = rt[i];
	splay (i, p, 0);
	ch[rt[i]][1] = ch[oldrt][1];
	fa[ch[oldrt][1]] = rt[i];
	splay_clear (oldrt);
	push_up (rt[i]);
}

inline int splay_getpre(int i, int v)
{
	int x = rt[i];
	while (x)
	{
		if (data[x] < v)
		{
			if (ans < data[x]) ans = data[x];
			x = ch[x][1];
		}
		else x = ch[x][0];
	}
	return ans;
}

inline int splay_getsuc(int i, int v)
{
	int x = rt[i];
	while (x)
	{
		if (data[x] > v)
		{
			if (ans > data[x]) ans = data[x];
			x = ch[x][0];
		}
		else x = ch[x][1];
	}
	return ans;
}

inline void tree_insert (int o, int l, int r, int x, int w)
{
	splay_insert (o, w);
	if (l == r) return;
	if (x <= mid) tree_insert (lc, l, mid, x, w);
	else tree_insert (rc, mid+1, r, x, w);
}

inline void tree_rank (int o, int l, int r, int x, int y, int v)
{
	if (l == x && r == y)
	{
		ans += splay_rank(o, v);
		return;
	}
	if (y <= mid) tree_rank(lc, l, mid, x, y, v);
	else if (x > mid) tree_rank(rc, mid+1, r, x, y, v);
	else tree_rank(lc, l, mid, x, mid, v), tree_rank(rc, mid+1, r, mid+1, y, v);
}

inline void tree_change(int o, int l, int r, int x, int v)
{
	splay_delete(o, a[x]);
	splay_insert(o, v);
	if (l == r)
	{
		a[x] = v;
		return;
	}
	if (x <= mid) tree_change (lc, l, mid, x, v);
	else tree_change(rc, mid+1, r, x, v);
}

inline void tree_pre(int o, int l, int r, int x, int y, int v)
{
	if (l == x && r == y)
	{
		ans = max (ans, splay_getpre(o, v));
		return;
	}
	if (y <= mid) tree_pre(lc, l, mid, x, y, v);
	else if (x > mid) tree_pre(rc, mid+1, r, x, y, v);
	else tree_pre(lc, l, mid, x, mid, v), tree_pre(rc, mid+1, r, mid+1, y, v);
}

inline void tree_suc (int o, int l, int r, int x, int y, int v)
{
	if (l == x && r == y)
	{
		ans = min(ans, splay_getsuc(o, v));
		return;
	}
	if (y <= mid) tree_suc (lc, l, mid, x, y, v);
	else if (x > mid) tree_suc (rc, mid+1, r, x, y, v);
	else tree_suc (lc, l, mid, x, mid, v), tree_suc (rc, mid+1, r, mid+1, y, v);
}

inline int get_Kth (int x, int y, int k)
{
	int ll = 0, rr = maxx+1, midd;
	while (ll < rr)
	{
		midd = (ll + rr) >> 1;
		ans = 0;
		tree_rank (1, 1, n, x, y, midd);
		if (ans < k) ll = midd+1;
		else rr = midd;
	}
	return ll-1;
}

int main ()
{
	n = read (), m = read ();
	for (rint i = 1; i <= n; i ++)
	{
		a[i] = read ();
		tree_insert (1, 1, n, i, a[i]);
		maxx = max (maxx, a[i]);
	}
	
	int opt, x, y, z;
	while (m --)
	{
		opt = read (), x = read (), y = read ();
		if (opt == 1) z = read (), ans = 0, tree_rank (1, 1, n, x, y, z), printf ("%d\n", ans+1);
		else if (opt == 2) z = read (), printf ("%d\n", get_Kth(x, y, z));
		else if (opt == 3) tree_change (1, 1, n, x, y);
		else if (opt == 4) z = read (), ans = -INF, tree_pre(1, 1, n, x, y, z), printf ("%d\n", ans);
		else if (opt == 5) z = read (), ans = INF, tree_suc(1, 1, n, x, y, z), printf ("%d\n", ans);
	}
	
	return 0;
}
