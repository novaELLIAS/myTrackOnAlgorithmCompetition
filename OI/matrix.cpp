#pragma G++ optimize ("Ofast", 3)

#include <cstdio>

using namespace std;

const int ELAS = 1<<14;
static char buf[ELAS], *p1 = buf, *p2 = buf;
inline char gc()
{
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0; register char c = gc(); register bool m = 0;
	while ((c < '0' || c > '9') && c != '-') c = gc();
	if (c == '-') c = gc(), m = 1;
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return m? -x:x;
}
static void write (long long x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}
static void writelen (long long x)
{
	if (x < 0) putchar('-'), x = -x;
	write (x); putchar ('\n');
}

inline const int& max (const int& a, const int& b) {return a>b? a:b;}
inline const int& min (const int& a, const int& b) {return a<b? a:b;}
inline const long long& minl (const long long& a, const long long& b) {return a<b? a:b;}

#define Re register
#define maxn 31
#define maxs 1775
#define sqr(x) ((x)*(x))

int dat[maxn][maxn], dp[maxn][maxn][maxs];

int main ()
{
	freopen ("matrix.in", "r", stdin);
	freopen ("matrix.out","w",stdout);
	
	register int _ = read (), n, m;
	register long long ans, tmp;
	while (_ --)
	{
		n = read (), m = read (), tmp = 1ll * (n + m - 1);
		for (Re int i = 1; i <= n; ++ i)
		{
			for (Re int j = 1; j <= m; ++ j) dat[i][j] = read ();
		}
		
		for (Re int i = 0; i <= n; ++ i)
		{
			for (Re int j = 0; j <= m; ++ j)
			{
				for (Re int k = 0; k <= 1770; ++ k) dp[i][j][k] = 0x3f3f3f3f;
			}
		}
		
		dp[1][1][dat[1][1]] = sqr(dat[1][1]);
		
		for (Re int i = 1; i <= n ; ++ i)
		{
			for (Re int j = 1; j <= m; ++ j)
			{
				if ((i^1)||(j^1))
				{
					for (Re int k = dat[i][j]; k <= 1770; ++ k)
					{
						dp[i][j][k] = min (dp[i-1][j][k-dat[i][j]], dp[i][j-1][k-dat[i][j]]) + sqr(dat[i][j]);
					}
				}
			}
		}
		
		ans = 0x3f3f3f3f;
		for (Re int i = 0; i <= 1770; ++ i) ans = minl (ans, tmp * 1ll * dp[n][m][i] - sqr(i));
		
		writelen (ans);
	}
	return 0;
}
