#pragma G++ optimize ("Ofast", 3)
#pragma GCC optimize ("Ofast", 3)
#pragma GCC target ("sse3","sse2","sse")
#pragma GCC target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target ("f16c")
#pragma G++ target ("sse3","sse2","sse")
#pragma G++ target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma G++ target ("f16c")

#include <cstdio>
#include <cctype>

#define gc() getchar ()

inline long long read ()
{
	register long long x = 0;register char c = gc();
	while (!isdigit(c)) c = gc();
	while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
	return x;
}

#define rint register int
#define maxn 200001
#define dmax 800001

struct TreeNode {
	int l, r, len;
	int sum, add;
} dat[dmax];

static void build (int rt, int l, int r)
{
	dat[rt].l = l, dat[rt].r = r, dat[rt].len = l - r + 1;
	if (l == r) {dat[rt].sum = read (); return;}
	register int mid = (l + r) >> 1;
	build (rt<<1, l, mid), build (rt<<1|1, mid+1, r);
	dat[rt].sum = dat[rt<<1].sum + dat[rt<<1|1].sum;
}

inline void pushdown (int rt)
{
	if (dat[rt].l == dat[rt].r || !dat[rt].add) return;
	register int ls = rt << 1, rs = rt << 1 | 1;
	dat[ls].sum += dat[rt].add * dat[ls].len;
	dat[rs].sum += dat[rt].add * dat[rs].len;
	dat[ls].add += dat[rt].add, dat[rs].add += dat[rt].add;
	dat[rt].add = 0;
	dat[rt].sum = dat[ls].sum + dat[rs].sum;
}

static int query (int rt, int l, int r)
{
	if (l <= dat[rt].l && dat[rt].r <= r) return dat[rt].sum;
	register int mid = (dat[rt].l + dat[rt].r) >> 1;
	return (l<=mid? query(rt<<1,l,r):0) + (r>mid? query(rt<<1|1,l,r):0);
}

static void change (int rt, int l, int r, int val)
{
	if (l <= dat[rt].l && dat[rt].r <= r)
	{
		dat[rt].add += val, dat[rt].sum += val * dat[rt].len;
		return;
	}
	pushdown (rt);
	register int mid = (dat[rt].l + dat[rt].r) >> 1;
	if (l <=mid) change (rt<<1, l, r, val);
	if (r > mid) change (rt<<1|1,l,r, val);
	dat[rt].sum = dat[rt<<1].sum + dat[rt<<1|1].sum;
}

int main ()
{
	freopen ("nico.in","r",stdin);
	freopen ("ellias.out","w",stdout);
	
	register int n = read(), m = read(), x, y, v;
	register char c[11];
	build (1, 1, n);
	while (m --)
	{
		scanf ("%s", c); x = read (), y = read ();
		if (c[0] == 'Q') printf ("%d\n", query (1, x, y));
		else change (1, x, y, read());
	}
	return 0;
}
