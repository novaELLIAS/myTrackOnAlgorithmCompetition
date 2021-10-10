#pragma G++ optimize ("Ofast", 3)

#include <cstdio>
#include <cstring>

using namespace std;

const int ELAS = 1<<14;
static char buf[ELAS], *p1 = buf, *p2 = buf;
inline char gc()
{
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0; register char c = gc();
	while (c < '0' || c > '9') c = gc();
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return x;
}

inline const int& max (const int& a, const int& b) {return a>b? a:b;}
inline const int& min (const int& a, const int& b) {return a<b? a:b;}

#define Re register
#define maxn 101
#define stat 100010

int dp[maxn][200110], c[maxn], a[maxn];

int main ()
{
	freopen ("salad.in", "r", stdin);
	freopen ("salad.out","w",stdout);
	
	memset (dp, -1, sizeof dp); dp[0][stat] = 0;
	register int n = read (), k = read ();
	for (Re int i = 1; i <= n; ++ i) a[i] = read ();
	for (Re int i = 1; i <= n; ++ i) c[i] = a[i] - k * read ();
	
	for (Re int i = 1; i <= n; ++ i)
	{
		for (Re int j = 0; j <= 200109; ++ j)
		{
			if (dp[i-1][j] ^ (-1)) dp[i][j] = dp[i-1][j];
			if (dp[i-1][j-c[i]] ^ (-1)) dp[i][j] = max (dp[i][j], dp[i-1][j-c[i]] + a[i]);
		}
	}
	
	printf ("%d", (!dp[n][stat])? -1:dp[n][stat]);
	
	return 0;
}
