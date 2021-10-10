#prag\
ma GCC optimize("Ofast")

#include "stdio.h"

inline int fastread ();
inline void fastwrite (int);
inline void fastwriteline (int);
inline void fastwritespace (int);

#define maxm 101
#define maxn 20002
#define max(a,b) a>b? a:b

int n, m, ans, maxx;
int mapp[maxm][maxn];
int cntm[maxn], dp[maxn];

int main ()
{
	// scanf("%d %d", &m, &n);
	//n ++;
	m = fastread ();
	n = fastread () - 1;
	for (int i = 1; i <= m; i ++)
	{
		for (int j = 1; j <= n; j ++)
		{
			// scanf("%d", &mapp[i][j]);
			mapp[i][j] = fastread ();
		}
	}
	
	for (int i = 1; i <= n; i ++)
	{
		maxx = mapp[1][i];
		for (int j = 2; j <= m; j ++)
		{
			maxx = max (maxx, mapp[j][i]);
		}
		cntm[i] = maxx;
	}
	
	dp[1] = cntm[1];
	ans = cntm[1];
	for (int i = 2; i <= n; i ++)
	{
		if (dp[i-1] > 0) dp[i] = cntm[i] + dp[i-1];
		else dp[i] = cntm[i];
		ans = max (ans, dp[i]);
	}
	
	fastwrite (ans);
	
	return 0;
}

inline int fastread ()
{
	int sign = 1, n = 0;
	char c = getchar();
	while(c < '0' || c > '9')
	{
		if(c == '-') sign = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9')
	{
		n = n*10 + c-'0';
		c = getchar();
	}
	return sign*n;
}
inline void fastwrite (int x)
{
	if(x < 0) x = -x, putchar('-');
	if(x > 9) fastwrite(x / 10);
	putchar(x%10 + '0');
}
inline void fastwritespace (int x)
{
	fastwrite(x);
	putchar(' ');
}
inline void fastwriteline (int x)
{
	fastwrite(x);
	putchar('\n');
}
