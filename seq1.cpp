#pragma G++ optimize ("Ofast", 3)

#include <cstdio>

typedef long long ll;

const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;
inline char gc()
{
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline ll read ()
{
	register ll x = 0; register char c = gc(); register bool m = false;
	while ((c < '0' || c > '9') && (c ^ '-')) c = gc();
	if (c == '-') m = true, c = gc();
	while (c>='0'&&c<='9') x = (x<<3) + (x<<1) + (c^'0'), c = gc();
	return m? -x:x;
}
static void write (long long x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}
static void writelen (long long x)
{
	if (x < 0) x = -x, putchar ('-');
	write (x); putchar ('\n');
}

#define Re register
#define maxn 500001
#define dmax 2000001

struct SMT {
	int l, r;
	ll add, mul, dat;
} tr[dmax];

static void nico_build (Re int rt, Re int l, Re int r)
{
	tr[rt].l = l, tr[rt].r = r, tr[rt].mul = 1ll;
	if (l == r) {tr[rt].dat = read (); return;}
	register int mid = (l + r) >> 1;
	nico_build (rt << 1,  l,  mid);
	nico_build (rt<<1|1, mid+1, r);
	tr[rt].dat = tr[rt<<1].dat + tr[rt<<1|1].dat;
}

inline void pushdown (register int rt)
{
	if ((rt<<1|1) >= dmax) return;
	if (tr[rt].mul == 1 && !tr[rt].add) return;
	register int ls = rt<<1, rs = rt<<1|1;
	register ll le = tr[ls].r - tr[ls].l + 1;
	register ll re = tr[rs].r - tr[rs].l + 1;
	
	tr[ls].dat = tr[ls].dat * tr[rt].mul + tr[rt].add * le;
	tr[ls].add = tr[ls].add * tr[rt].mul + tr[rt].add;
	tr[ls].mul = tr[ls].mul * tr[rt].mul;
	
	tr[rs].dat = tr[rs].dat * tr[rt].mul + tr[rt].add * re;
	tr[rs].add = tr[rs].add * tr[rt].mul + tr[rt].add;
	tr[rs].mul = tr[rs].mul * tr[rt].mul;
	
	tr[rt].add = 0ll, tr[rt].mul = 1ll;
}

static void modify_add (register int rt, Re int l, Re int r, Re ll val)
{
	register int L = tr[rt].l, R = tr[rt].r;
	if (l <= L && R <= r) {tr[rt].add += val, tr[rt].dat += (R - L + 1) * val; return;}
	pushdown (rt);
	register int mid = (L + R) >> 1;
	if (l <= mid) modify_add (rt << 1, l, r, val);
	if (r >  mid) modify_add (rt<<1|1, l, r, val);
	tr[rt].dat = tr[rt<<1].dat + tr[rt<<1|1].dat;
}

static void modify_mul (register int rt, Re int l, Re int r, Re ll val)
{
	register int L = tr[rt].l, R = tr[rt].r;
	if (l <= L && R <= r) {tr[rt].mul *= val, tr[rt].dat *= val, tr[rt].add *= val; return;}
	pushdown (rt);
	register int mid = (L + R) >> 1;
	if (l <= mid) modify_mul (rt << 1, l, r, val);
	if (r  > mid) modify_mul (rt<<1|1, l, r, val);
	tr[rt].dat = tr[rt<<1].dat + tr[rt<<1|1].dat;
}

static long long query (register int rt, Re int l, Re int r)
{
	register int L = tr[rt].l, R = tr[rt].r;
	register long long ret = 0ll;
	if (l <= L && R <= r) return tr[rt].dat;
	pushdown (rt);
	register int mid = (L + R) >> 1;
	if (l <= mid) ret += query (rt << 1, l, r);
	if (r  > mid) ret += query (rt<<1|1, l, r);
	return ret;
}

int main ()
{
	freopen ("seq.in", "r", stdin);
	freopen ("seq.out","w",stdout);
	
	register int n = read (), m = read ();
	register long long opt, l, r, a, k;
	nico_build (1, 1, n);
	while (m -- )
	{
		opt = read ();
		if (opt == 1) {
			l=read(), r=read(), a=read(), k=read();
			if (a) modify_add (1, l, r, a);
			if (k) for (Re int i = l + 1; i <= r; ++ i)
				modify_add (1, i, r, k);
		} else if (opt == 2) {
			l = read (), r = read ();
			writelen (query (1, l, r));
		} else if (opt == 3)
		{
			l = read (), r = read ();
			modify_mul (1, l, r, -1);
		}
	}
	fclose (stdin), fclose (stdout);
	return 0;
}

/* CNMBFRNMLGB */
