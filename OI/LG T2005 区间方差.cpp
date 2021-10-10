#pragma G++ optimize (3)
#pragma GCC optimize ("Ofast", 3)

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

#define Re register
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-(x)))
#define maxn 100001
#define dmax 400001
typedef long long ll;
const long long modn = 1e9+7;

inline long long qpow (Re ll a, Re ll t)
{
	register long long base = a % modn, ret = 1ll;
	while (t)
	{
		if (t&1) ret = ret * base % modn;
		base = base * base % modn, t >>= 1;
	}
	return ret % modn;
}

struct SMT {
	int l, r;
	long long sum, dsm;
} dat[dmax];

static void build (Re int rt, Re int l, Re int r)
{
	dat[rt].l = l, dat[rt].r = r;
	if (l == r) {
		dat[rt].sum = read () % modn, dat[rt].dsm = sqr(dat[rt].sum)%modn;return;
	} register int mid = (l + r) >> 1;
	build(rt<<1, l, mid); build (rt<<1|1,mid+1,r);
	dat[rt].sum = (dat[rt<<1].sum+dat[rt<<1|1].sum)%modn;
	dat[rt].dsm = (dat[rt<<1].dsm+dat[rt<<1|1].dsm)%modn;
}

inline SMT add (Re SMT a, Re SMT b)
{
	register SMT ret;
	ret.sum = (a.sum + b.sum) % modn;
	ret.dsm = (a.dsm + b.dsm) % modn;
	return ret;
}

static void modify (Re int rt, Re int pt, Re ll val)
{
	register int l = dat[rt].l, r = dat[rt].r;
	if (l == r && r == pt) {
		dat[rt].sum = val, dat[rt].dsm = sqr(val)%modn;
		return;
	} register int mid = (l + r) >> 1;
	if (pt <= mid) modify (rt<<1, pt, val);
	else modify (rt<<1|1, pt, val);
	dat[rt].sum = (dat[rt<<1].sum+dat[rt<<1|1].sum)%modn;
	dat[rt].dsm = (dat[rt<<1].dsm+dat[rt<<1|1].dsm)%modn;
}

struct SMT query (Re int rt, Re int l, Re int r)
{
	register int L = dat[rt].l, R = dat[rt].r;
	if (l <= L && R <= r) return dat[rt];
	register int mid = (L + R) >> 1;
	register SMT ret = {0, 0, 0ll, 0ll};
	if (l <= mid) ret = query (rt<<1, l, r);
	if (r >  mid) ret = add(ret, query (rt<<1|1,l,r));
	return ret;
}

signed main ()
{
	register int n = read (), m = read (), opt;
	register SMT pi;
	register long long a, b, ans, inv;
	
	build (1, 1, n);
	
	while (m --)
	{
		opt = read (), a = read (), b = read ();
		if (opt == 1) modify (1, a, b%modn);
		else {
			pi = query(1, a, b);
			inv = qpow (b-a+1, modn-2);
			ans = (pi.dsm + modn - (sqr(pi.sum)%modn*inv)%modn)%modn*inv%modn;
			printf ("%lld\n", ans);
		}
	}
	
	return 0;
}
