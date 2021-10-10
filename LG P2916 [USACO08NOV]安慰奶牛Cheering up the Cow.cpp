#pragma G++ optimize (3)

#include <cstdio>
#include <algorithm>

#define Re register
#define maxn 10001
#define maxe 100001

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
inline const int& min (const int& a, const int& b) {return a<b? a:b;}

struct node {
	int fr, to, val;
} e[maxe];

inline bool cmp (node a, node b) {return a.val < b.val;}

int fa[maxn], dat[maxn];

inline int find (register int x)
{
	while (x ^ fa[x]) x = fa[x] = fa[fa[x]];
	return x;
}

signed main ()
{
	register int n = read (), m = read ();
	register int fr, to, va, sta = 0x3f3f3f3f;
	for (Re int i = 1; i <= n; ++ i)
		dat[i] = read (), sta = min (sta, dat[i]), fa[i] = i;
	for (Re int i = 1; i <= m; ++ i)
	{
		fr = read (), to = read (), va = read ();
		e[i] = (node) {fr, to, (va<<1) + dat[fr] + dat[to]};
	}
	std::sort (e + 1, e + m + 1, cmp);
	register int cnt = 1, ans = 0;
	for (Re int i = 1; cnt ^ n; ++ i)
	{
		fr = find (e[i].fr), to = find (e[i].to);
		if (fr ^ to) fa[fr] = to, ++ cnt, ans += e[i].val;
	}
	printf ("%d", ans + sta);
	return 0;
}
