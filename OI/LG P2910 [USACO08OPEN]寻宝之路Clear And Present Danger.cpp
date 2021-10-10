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
inline const int& min (const int& a, const int& b) {return a<b? a:b;}

#define Re register
#define maxm 10001
#define maxn 101

signed main ()
{
	register int a[maxm], p[maxn][maxn];
	register int n = read (), m = read (), ans = 0;
	for (Re int i = 1; i <= m; ++ i) a[i] = read ();
	for (Re int i = 1; i <= n; ++ i)
		for (Re int j = 1; j <= n; ++ j)
			p[i][j] = read ();
	for (Re int k = 1; k <= n; ++ k)
		for (Re int i = 1; i <= n; ++ i)
			for (Re int j = 1; j <= n; ++ j)
				p[i][j] = min (p[i][j], p[i][k] + p[k][j]);
	for (Re int i = 1; i ^ m; ++ i) ans += p[a[i]][a[i+1]];
	printf ("%d", ans); return 0;
}
