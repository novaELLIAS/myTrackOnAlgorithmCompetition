#include <cstdio>

using namespace std;

inline char gc()
{
	static char buf[1<<14],*p1=buf,*p2=buf;
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
}
inline long long read ()
{
	register long long x = 0; register char c = gc(); register bool m = true;
	while ((c < '0' || c > '9') && c ^ '-') c = gc();
	if (c == '-') m = false, c = gc ();
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c - '0'), c = gc();
	return m? x:-x;
}
static void write (long long x)
{
	if (x < 0) putchar ('-'), x = -x;
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}

typedef long long ll;
#define Re register
#define maxn 100001
#define dmax 400001

struct TreeNode {
	int l, r;
	long long dat, sum, lmax, rmax, mmax, laz;
} dat[dmax];

inline const long long& max (const long long& a, const long long& b) {return a>b? a:b;}

inline void update (int rt) {
    tr[rt].sum =tr[rt<<1].sum + tr[rt<<1|1].sum;
    tr[rt].lmax= max (tr[rt<<1].lmax, tr[rt<<1].sum + tr[rt<<1|1].lmax);
    tr[rt].rmax= max (tr[rt<<1|1].rmax, tr[rt<<1|1].sum + tr[rt<<1].rmax);
    tr[rt].dat = max (max(tr[rt<<1].dat, tr[rt<<1|1].dat), tr[rt<<1].rmax + tr[rt<<1|1].lmax);
}
inline void update (register int rt)
{
	register lson = rt<<1, rson = rt<<1|1;
	dat[rt].sum = dat[lson].sum + dat[rson].sum;
	dat[rt].lmax = max (dat[lson].lmax)
}

inline void build (Re int rt, Re int l, Re int r)
{
	dat[rt].l = l, dat[rt].r = r;
	if (l == r) {dat[rt].dat = dat[rt].sum = dat[rt].lmax = dat[rt].rmax = dat[rt].mmax = read (); return;}
	register int mid = (l + r) >> 1;
	build (rt<<1, l, mid), build (rt<<1|1, mid + 1, r);
	update (rt);
}

int main ()
{
	
}
