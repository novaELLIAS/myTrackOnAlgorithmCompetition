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

#define Re register
bool dp[51][1001];

signed main ()
{
	register int n = read (), bgl = read (), mxl = read ();
	register int dat[51]; dp[0][bgl] = true;
	for (Re int i = 1; i <= n; ++ i) dat[i] = read ();
	for (Re int i = 1; i <= n; ++ i)
		for (Re int j = mxl; j >= 0; -- j)
		{
			if (j - dat[i] >= 0)   dp[i][j] |= dp[i-1][j-dat[i]];
			if (j + dat[i] <= mxl) dp[i][j] |= dp[i-1][j+dat[i]];
		}
	for (Re int i = mxl; i; -- i) if (dp[n][i]) return printf ("%d", i), 0;
	puts ("-1"); return 0;
}
