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
	register long long x = 0; register char c = gc();
	while (c < '0' || c > '9') c = gc();
	while (c>='0'&&c<='9') x = (x<<3) + (x<<1) + (c^'0'), c = gc();
	return x;
}
static void write (long long x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}

inline const int& max (const int& a, const int& b) {return a>b? a:b;}

#define Re register
#define maxn 100001
#define dmax 400001

struct node {
	int l, r;
	int dat;
	int lmax, rmaxn, mmax;
};

static void build (Re int rt, Re int l, Re int r)
{
	dat[rt].l = l, dat[rt].r = r;
	if (l == r) {dat[rt]}
}

signed main ()
{
	
}
