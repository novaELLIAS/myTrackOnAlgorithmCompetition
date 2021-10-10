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
inline const int& min (const int& a, const int& b) {return a<b? a:b;}
inline const int& max (const int& a, const int& b) {return a>b? a:b;}

#define Re register
#define maxn 1001

int dat[maxn], dp[maxn][maxn][2];

signed main ()
{
	register int t = read (), w = read (), ans = 0;
	register int pss, psi, top;
	for (Re int i = 1; i <= t; ++ i) dat[i] = read ();
	if (dat[1] == 1) dp[1][0][0] = 1;
	else dp[1][0][1] = 1;
	for (Re int i = 2; i <= t; ++ i)
	{
		pss = dat[i]==1? 1:0, psi = !pss, top = min (i, w);
		for (Re int j = 0; j <= top; ++ j)
		{
			dp[i][j][psi] = max (dp[i-1][j][psi] + 1, dp[i-1][j-1][pss] + 1);
			dp[i][j][pss] = max (dp[i-1][j][pss], dp[i-1][j-1][psi]);
			ans = max (ans, max (dp[i][j][1], dp[i][j][0]));
		}
	}
	printf ("%d", ans);
	return 0;
}
