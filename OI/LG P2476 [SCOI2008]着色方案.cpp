#pragma G++ optimize (3)

#include <cstdio>

#define Re register
#define maxn 6
#define maxc 16
#define modn 1000000007ll

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

int dp[maxc][maxc][maxc][maxc][maxc][maxn], cnt[maxn];

static long long nico_dfs (Re int a, Re int b, Re int c, Re int d, Re int e, Re int las)
{
	if (dp[a][b][c][d][e][las]) return dp[a][b][c][d][e][las];
	register long long ret = 0;
	if (a) ret = (ret + (a - (las == 2)) * nico_dfs (a - 1, b, c, d, e, 1)) % modn;
	if (b) ret = (ret + (b - (las == 3)) * nico_dfs (a + 1, b - 1, c, d, e, 2)) % modn;
	if (c) ret = (ret + (c - (las == 4)) * nico_dfs (a, b + 1, c - 1, d, e, 3)) % modn;
	if (d) ret = (ret + (d - (las == 5)) * nico_dfs (a, b, c + 1, d - 1, e, 4)) % modn;
	if (e) ret = (ret + e * nico_dfs (a, b, c, d + 1, e - 1, 5)) % modn;
	return dp[a][b][c][d][e][las] = ret;
}

signed main ()
{
	register int n = read ();
	while (n --) ++ cnt[read ()];
	dp[0][0][0][0][0][0] = dp[0][0][0][0][0][1] = dp[0][0][0][0][0][2] = dp[0][0][0][0][0][3] = dp[0][0][0][0][0][4] = dp[0][0][0][0][0][5] = 1;
	printf ("%I64d", nico_dfs (cnt[1], cnt[2], cnt[3], cnt[4], cnt[5], 0));
	return 0;
}
