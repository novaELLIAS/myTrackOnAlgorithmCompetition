#pragma G++ optimize ("Ofast", 3)

#include <cstdio>

using namespace std;

inline char gc()
{
	static char buf[1<<14],*p1=buf,*p2=buf;
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0;register char c = gc();
	while (c < '0' || c > '9') c = gc();
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return x;
}
static void write (register int x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}
inline void writelen (register int x) {write (x), putchar ('\n');}

#define Re register
#define modn 4096
#define maxn 2011

int dp[maxn][maxn];

inline const int& min (const int& a, const int& b) {return a<b? a:b;}

int main ()
{
	freopen ("subway.in","r",stdin); freopen ("subway.out","w",stdout);
	register int n = read (), p = read (); dp[n][0] = 1;
	for (Re int i = n - 1; i ^ (-1); -- i)
	{
		for (Re int j = min (p, n - i); j ^ (-1); -- j)
		{
			dp[i][j] = dp[i][j+1];
			if (j) dp[i][j] = (dp[i][j] + dp[i+1][j-1]) % modn;
		}
	}
	printf ("%d", dp[0][0]);
	return 0;
}
