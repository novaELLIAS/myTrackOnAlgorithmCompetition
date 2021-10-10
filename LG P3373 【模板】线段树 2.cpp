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

inline long long mul_mod (register long long a,register long long b,register long long mo) {
	register long long ret;
	__asm__ __volatile__ ("\tmull %%ebx\n\tdivl %%ecx\n" : "=d"(ret):"a"(a),"b"(b),"c"(mo));
	return ret;
}

#define Re register
#define maxn 100001
#define dmax 400001
typedef long long ll;
#define swap(x,y) ((x)^=(y)^=(x)^=(y))
#define mod(x) (((x)%modn+modn)%modn)
long long modn;

struct SMT {
	int l, r;
	long long sum, add, mul;
} tr[dmax];

inline void update (Re int rt) {
	tr[rt].sum = tr[rt<<1].sum + tr[rt<<1|1].sum;
}

static void build (Re int rt, Re int l, Re int r)
{
	tr[rt] = {l, r, 0ll, 0ll, 1ll};
	if (l == r) {tr[rt].sum = read()%modn; return;}
	register int mid = (l + r) >> 1;
	build (rt<<1, l, mid), build (rt<<1|1, mid+1, r);
	update (rt);
}

inline void pushdown (Re int rt)
{
	if (rt > 200000 || (!tr[rt].add && tr[rt].mul == 1ll)) return;
	register int ls = rt << 1, rs = rt << 1 | 1;
	tr[ls].mul = mul_mod (tr[ls].mul, tr[rt].mul, modn);
	tr[rs].mul = mul_mod (tr[rs].mul, tr[rt].mul, modn);
	tr[ls].add = mod (mul_mod (tr[ls].add , tr[rt].mul, modn) + tr[rt].add);
	tr[rs].add = mod (mul_mod (tr[rs].add, tr[rt].mul, modn) + tr[rt].add);
	tr[ls].sum = mod (mul_mod (tr[ls].sum, tr[rt].mul, modn) + mul_mod (tr[rt].add, (tr[ls].r - tr[ls].l + 1), modn));
	tr[rs].sum = mod (mul_mod (tr[rs].sum, tr[rt].mul, modn) + mul_mod (tr[rt].add, (tr[rs].r - tr[rs].l + 1), modn));
	tr[rt].add = 0ll, tr[rt].mul = 1ll;
}

// opt==1: mul opt==2: add
static void modify (Re int rt, Re int l, Re int r, Re ll val, Re int opt)
{
	register int L = tr[rt].l, R = tr[rt].r;
	if (l <= L && R <= r) {
		if (opt == 2) {
			tr[rt].add = mod (tr[rt].add + val),\
			tr[rt].sum = mod (tr[rt].sum + mul_mod (val, (R - L + 1), modn));
			return;
		} else {
			tr[rt].mul = mul_mod (tr[rt].mul, val, modn),\
			tr[rt].sum = mul_mod (tr[rt].sum, val, modn),\
			tr[rt].add = mul_mod (tr[rt].add, val, modn);
			return;
		}
	} pushdown (rt); register int mid = (L + R) >> 1;
	if (l <= mid) modify (rt<<1, l, r, val, opt);
	if (r  > mid) modify (rt<<1|1,l,r, val, opt);
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
	return ret % modn;
}

signed main ()
{
	register int n=read(), m=read(); modn=read();
	register int opt, x, y;
	register long long z;
	build (1, 1, n);
	while (m --)
	{
		opt=read(), x=read(), y=read();
		if (x > y) swap (x, y);
		if (opt == 3) writelen (query (1,x,y));
		else z=read()%modn,modify(1,x,y,z,opt);
	}
	return 0;
}
