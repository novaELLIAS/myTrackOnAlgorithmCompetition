#pragma GCC optimize (2)
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
#pragma GCC optimize ("-freorder-blocks")
#pragma GCC optimize ("-fschedule-insns")
#pragma GCC optimize ("inline-functions")
#pragma GCC optimize ("-ftree-tail-merge")
#pragma GCC optimize ("-fschedule-insns2")
#pragma GCC optimize ("-fstrict-aliasing")
#pragma GCC optimize ("-falign-functions")
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
#pragma GCC optimize ("inline-functions-called-once")
#pragma GCC optimize ("-fdelete-null-pointer-checks")
#pragma GCC optimize ("Ofast", 3)
#pragma GCC target ("sse3","sse2","sse")
#pragma GCC target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target ("f16c")

#include <cstdio>

const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;
inline char gc()
{
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline long long read ()
{
	register long long x = 0; register char c = gc(); register bool m = false;
	while ((c < '0' || c > '9') && (c ^ '-')) c = gc();
	if (c == '-') m = true, c = gc ();
	while (c>='0'&&c<='9') x = (x<<3) + (x<<1) + (c^'0'), c = gc();
	return m? -x:x;
}
static void write (long long x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}
static void writelen (long long x) {if(x<0)x=-x,putchar('-'); write (x); putchar ('\n');}

#define Re register
#define maxn 100001
#define dmax 400001
typedef long long ll;
#define swap(x,y) ((x)^=(y)^=(x)^=(y))

struct SMT {
	int l, r;
	long long sum, tag;
} tr[dmax];

inline void update (Re int rt) {
	tr[rt].sum = tr[rt<<1].sum + tr[rt<<1|1].sum;
}

static void build (Re int rt, Re int l, Re int r)
{
	tr[rt].l = l, tr[rt].r = r;
	if (l == r) {tr[rt].sum = read(); return;}
	register int mid = (l + r) >> 1;
	build (rt<<1, l, mid), build (rt<<1|1, mid+1, r);
	update (rt);
}

inline void pushdown (Re int rt)
{
	if (rt > 200000 || !tr[rt].tag) return;
	register int ls = rt<<1, rs = rt<<1|1;
	tr[ls].tag += tr[rt].tag, tr[rs].tag += tr[rt].tag;
	tr[ls].sum += tr[rt].tag * (tr[ls].r - tr[ls].l + 1),
	tr[rs].sum += tr[rt].tag * (tr[rs].r - tr[rs].l + 1);
	tr[rt].tag = 0;
}

static void modify (Re int rt, Re int l, Re int r, Re ll val)
{
	register int L = tr[rt].l, R = tr[rt].r;
	if (l <= L && R <= r) {
		tr[rt].sum += val * (R - L + 1), tr[rt].tag += val;
		return;
	} register int mid = (L + R) >> 1; pushdown (rt);
	if (l <= mid) modify (rt<<1, l, r, val);
	if (r  > mid) modify (rt<<1|1,l,r, val);
	update (rt);
}

static long long query (Re int rt, Re int l, Re int r)
{
	register int L = tr[rt].l, R = tr[rt].r;
	if (l <= L && R <= r) return tr[rt].sum;
	pushdown (rt); register int mid = (L+R)>>1;
	register long long ret = 0;
	if (l <= mid) ret  = query (rt<<1, l, r);
	if (r  > mid) ret += query (rt<<1|1,l,r);
	return ret;
}

signed main ()
{
	register int n=read(), m=read();
	register int opt, x, y;
	register long long z;
	build (1, 1, n);
	while (m --)
	{
		opt=read(), x=read(), y=read();
		if (x > y) swap (x, y);
		if (opt == 2) writelen (query (1, x, y));
		else z = read (), modify (1, x, y, z);
	}
	return 0;
}
