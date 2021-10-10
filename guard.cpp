#pragma G++ optimize (3)

#include <cstdio>
#include <algorithm>

const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;
inline char gc()
{
    return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0; register char c = gc(); register bool m = false;
	while ((c < '0' || c > '9') && (c ^ '-')) c = gc();
	if (c == '-') m = true, c = gc ();
	while (c>='0'&&c<='9') x = (x<<3) + (x<<1) + (c^'0'), c = gc();
	return m? -x:x;
}
inline double getdou ()
{
	register double x=0; register char c = gc ();
	while (c < '0' || c > '9') c = gc();
	while (c>='0'&&c<='9') x = x * 10 + (c^'0'), c = gc();
	if (c == '.')
	{
		register double s = 0.1, c = gc ();
		while (c>='0'&&c<='9') x = x + (c-'0')*s, s/=10, c = gc ();
	}
	return x;
}

inline const int& min (const int& a, const int& b){return a<b? a:b;}

#define Re register

struct node {
	int opt;
	double dat;
} dat[201];

inline bool cmp (node a, node b) {return a.opt > b.opt;}
double dp[201][201][201];

signed main ()
{
	freopen ("guard.in", "r", stdin);
	freopen ("guard.out","w",stdout);
	register int n = read (), l = read (), k = read (), tmp;
	for (Re int i = 1; i <= n; ++ i) dat[i].dat = getdou()/100;
	for (Re int i = 1; i <= n; ++ i) dat[i].opt = read ();
	std::sort (dat + 1, dat + n + 1, cmp);
	dp[0][0][min(n, k)] = 1.0;
	for (Re int i = 1; i <= n; ++ i)
	{
		for (Re int j = 0; j <= i; ++ j)
		{
			for (Re int K = 0; K <= n; ++ K)
			{
				dp[i][j][K] += dp[i-1][j][K] * (1 - dat[i].dat);
				if ((tmp = min (K + dat[i].opt, n)) < 0) continue;
				dp[i][j+1][tmp] += dp[i-1][j][K] * dat[i].dat;
			}
		}
	}
	register double ans = 0.0;
	for (Re int i = l; i <= n; ++ i)
		for (Re int j = 0; j <= n; ++ j)
			ans += dp[n][i][j];
	printf ("%.6lf", ans);
	fclose (stdin), fclose (stdout);
	return 0;
}
