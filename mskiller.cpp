#pragma GCC optimize (2)
#pragma G++ optimize (2)
#pragma GCC optimize (3)
#pragma G++ optimize (3)
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("inline")
#pragma GCC optimize ("-fgcse")
#pragma GCC optimize ("-fgcse-lm")
#pragma GCC optimize ("-fipa-sra")
#pragma GCC optimize ("-ftree-pre")
#pragma GCC optimize ("-ftree-vrp")
#pragma GCC optimize ("-fpeephole2")
#pragma GCC optimize ("-ffast-math")
#pragma GCC optimize ("-fsched-spec")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("-falign-jumps")
#pragma GCC optimize ("-falign-loops")
#pragma GCC optimize ("-falign-labels")
#pragma GCC optimize ("-fdevirtualize")
#pragma GCC optimize ("-fcaller-saves")
#pragma GCC optimize ("-fcrossjumping")
#pragma GCC optimize ("-fthread-jumps")
#pragma GCC optimize ("-funroll-loops")
#pragma GCC optimize ("-fwhole-program")
#pragma GCC optimize ("-freorder-blocks")
#pragma GCC optimize ("-fschedule-insns")
#pragma GCC optimize ("inline-functions")
#pragma GCC optimize ("-ftree-tail-merge")
#pragma GCC optimize ("-fschedule-insns2")
#pragma GCC optimize ("-fstrict-aliasing")
#pragma GCC optimize ("-fstrict-overflow")
#pragma GCC optimize ("-falign-functions")
#pragma GCC optimize ("-fcse-skip-blocks")
#pragma GCC optimize ("-fcse-follow-jumps")
#pragma GCC optimize ("-fsched-interblock")
#pragma GCC optimize ("-fpartial-inlining")
#pragma GCC optimize ("no-stack-protector")
#pragma GCC optimize ("-freorder-functions")
#pragma GCC optimize ("-findirect-inlining")
#pragma GCC optimize ("-fhoist-adjacent-loads")
#pragma GCC optimize ("-frerun-cse-after-loop")
#pragma GCC optimize ("inline-small-functions")
#pragma GCC optimize ("-finline-small-functions")
#pragma GCC optimize ("-ftree-switch-conversion")
#pragma GCC optimize ("-foptimize-sibling-calls")
#pragma GCC optimize ("-fexpensive-optimizations")
#pragma GCC optimize ("-funsafe-loop-optimizations")
#pragma GCC optimize ("inline-functions-called-once")
#pragma GCC optimize ("-fdelete-null-pointer-checks")
#pragma GCC target ("sse3","sse2","sse")
#pragma GCC target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target ("f16c")
#pragma G++ target ("sse3","sse2","sse")
#pragma G++ target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma G++ target ("f16c")

#include <cstdio>

#define gc() getchar()
inline long long read ()
{
	register long long x = 0; register char c = gc(); register bool m = 0;
	while ((c < '0' || c > '9') && c != '-') c = gc();
	if (c == '-') c = gc(), m = 1;
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return m? -x:x;
}
static void write (long long x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}
static void writelen (long long x)
{
	if (x < 0) putchar('-'), x = -x;
	write (x); putchar ('\n');
}

#define Re register
#define maxn 10001
#define dmax 40001

struct node {
	int l, r;
	long long sum, lmax, rmax, dat;
} tr[dmax], null;

inline const long long& max (const long long& x,const long long& y) {return x>y? x:y;}

inline void update (int rt)
{
	register int lson = rt<<1, rson = rt<<1|1;
	tr[rt].sum = tr[lson].sum + tr[rson].sum;
	tr[rt].lmax= max (tr[lson].lmax, tr[lson].sum + tr[rson].lmax);
	tr[rt].rmax= max (tr[rson].rmax, tr[rson].sum + tr[lson].rmax);
	tr[rt].dat = max (max(tr[lson].dat, tr[rson].dat), tr[lson].rmax + tr[rson].lmax);
}

static void build (int rt, int l, int r) {
	tr[rt].l = l, tr[rt].r = r;
	if (l == r) {tr[rt].dat = tr[rt].sum = tr[rt].lmax = tr[rt].rmax = read (); return;}
	register int mid = (l + r) >> 1;
	build (rt<<1, l, mid), build (rt<<1|1, mid + 1, r);
	update (rt);
}

static node query (int rt, int ql, int qr) {
	register int l = tr[rt].l, r = tr[rt].r;
	if (ql > qr) return null;
	if (ql <= l && qr >= r) return tr[rt];
	register int mid = (l + r) >> 1;
	if (ql >  mid) return query (rt<<1|1,ql,qr);
	if (qr <= mid) return query (rt<<1, ql, qr);
	else
	{
		register node ret, a, b;
		a = query (rt<<1, ql, qr), b = query (rt<<1|1, ql, qr);
		ret.sum = a.sum + b.sum;
		ret.dat = max (a.dat, a.rmax + b.lmax), ret.dat = max (ret.dat, b.dat);
		ret.lmax= max (a.lmax, a.sum + b.lmax), ret.rmax= max (b.rmax, b.sum + a.rmax);
		return ret;
	}
}

static void modify (int rt, int to, long long val)
{
	if (tr[rt].l == tr[rt].r) {tr[rt].sum = tr[rt].lmax = tr[rt].rmax = tr[rt].dat = val; return;}
	register int mid = (tr[rt].l + tr[rt].r) >> 1;
	if (to <= mid) modify (rt<<1, to, val);
	else modify (rt<<1|1, to, val);
	update(rt);
}

int main() {
	freopen ("mskiller.in", "r", stdin);
	//freopen ("mskiller.out","w",stdout);
	
	register int x1, y1, x2, y2, n = read (), m = read ();
	register long long tmp;
	register char opt;
	build (1, 1, n);
	while (m --)
	{
		opt = gc();
		if (opt ^ 'C')
		{
			x1 = read (), y1 = read (), x2 = read (), y2 = read ();
			if (y1 < x2) {
				writelen (max(query(1,x1,y1-1).rmax, 0) + query(1,y1,x2).sum + max(query(1,x2+1,y2).lmax, 0));
			} else {
				tmp = query (1,x2,y1).dat;
				tmp = max (tmp, query(1,x2,y1).lmax + query(1,x1,x2-1).rmax);
				tmp = max (tmp, query(1,y1+1,y2).lmax + query(1,x2,y1).rmax);
				tmp = max (tmp, query(1,x2,y1).sum + max(0, query(1,x1,x2-1).rmax) + max(0, query(1, y1 + 1,y2).lmax));
				writelen (tmp);
			}
		} else {x1 = read (), tmp = read (); modify (1, x1, tmp);}
	}
	
	return 0;
}
