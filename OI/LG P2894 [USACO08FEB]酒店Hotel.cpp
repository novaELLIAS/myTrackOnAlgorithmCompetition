#pragma G++ optimize (3)

#include <cstdio>

const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;
inline char gc()
{
    return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
    register int x = 0; register char c = gc();
    while (c < '0' || c > '9') c = gc();
    while (c>='0'&&c<='9') x = (x<<3) + (x<<1) + (c^'0'), c = gc();
    return x;
}
static void write (int x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}
static void writelen (int x) {write (x); putchar ('\n');}
inline const int& max (const int& a, const int& b) {return a>b? a:b;}

#define Re register
#define maxn 50001
#define dmax 200001

struct SMT {
	int l, r, len;
	int lm, rm, mm;
	int tag;
} tr[dmax];

static void build (Re int rt, Re int l, Re int r)
{
	tr[rt].l = l, tr[rt].r = r;
	tr[rt].lm = tr[rt].rm = tr[rt].mm = tr[rt].len = r - l + 1;
	if (l == r) return;
	register int mid = (l + r) >> 1;
	build (rt<<1, l, mid), build (rt<<1|1, mid+1, r);
}

inline void pushdown (register int rt)
{
	if (!tr[rt].tag) return;
	register int ls = rt<<1, rs = rt<<1|1;
	if (tr[rt].tag == 1)
	{
		tr[ls].tag = tr[rs].tag = 1;
		tr[ls].mm = tr[ls].lm = tr[ls].rm = 0;
		tr[rs].mm = tr[rs].lm = tr[rs].rm = 0;
	} else  {
		tr[ls].tag = tr[rs].tag = 2;
		tr[ls].mm = tr[ls].lm = tr[ls].rm = tr[ls].len;
		tr[rs].mm = tr[rs].lm = tr[rs].rm = tr[rs].len;
	}
	tr[rt].tag = 0;
}

inline void pushup (register int rt)
{
	register int ls = rt<<1, rs = rt<<1|1;
	if (tr[ls].mm == tr[ls].len) tr[rt].lm = tr[ls].len + tr[rs].lm;
	else tr[rt].lm = tr[ls].lm;
	if (tr[rs].mm == tr[rs].len) tr[rt].rm = tr[rs].len + tr[ls].rm;
	else tr[rt].rm = tr[rs].rm;
	tr[rt].mm = max (tr[ls].rm + tr[rs].lm, max (tr[ls].mm, tr[rs].mm));
}

static void modify (Re int rt, Re int l, Re int r, Re int tag)
{
	register int L = tr[rt].l, R = tr[rt].r;
	if (l <= L && R <= r)
	{
		if (tag == 1) tr[rt].mm = tr[rt].lm = tr[rt].rm = 0;
		else tr[rt].mm = tr[rt].lm = tr[rt].rm = tr[rt].len;
		tr[rt].tag = tag; return;
	}
	pushdown (rt);
	register int mid = (L + R) >> 1;
	if (l <= mid) modify (rt << 1, l, r, tag);
	if (r >  mid) modify (rt<<1|1, l, r, tag);
	pushup (rt);
}

static int query (Re int rt, Re int x)
{
	pushdown (rt);
	register int l = tr[rt].l, r = tr[rt].r;
	if (l == r) return l;
	register int mid = (l + r) >> 1, ls = rt<<1, rs = rt<<1|1;
	if (tr[ls].mm >= x) return query (ls, x);
	if (tr[ls].rm + tr[rs].lm >= x) return mid - tr[ls].rm + 1;
	return query (rs, x);
}

signed main ()
{
	register int n = read (), _ = read ();
	build (1, 1, n);
	register int x, y, opt;
	while (_ --)
	{
		opt = read ();
		if (opt == 1)
		{
			x = read ();
			if (tr[1].mm < x) putchar ('0'), putchar ('\n');
			else {
				y = query (1, x);
				writelen (y);
				modify (1, y, y + x - 1, 1);
			}
		} else {
			x = read (), y = read ();
			modify (1, x, x + y - 1, 2);
		}
	}
	return 0;
}
