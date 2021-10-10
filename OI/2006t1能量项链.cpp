#include <stdio.h>

#define maxn 202
#define ll long long
#define max(a,b) a>b? a:b

inline int fastread();
inline void fastwrite(int);
inline void fastwriteline(int);

int n, ans = -1;
int data[maxn];
int dp[maxn][maxn];

int main()
{
	n = fastread();
	for (int i = 1; i <= n; i ++)
	{
		data[i] = fastread();
		data[i+n] = data[i];
	}
	for (int r = 2; r < 2*n; r ++)
	{
		for (int l = r-1; r-l<n && l>=1; l --)
		{
			for (int k = l; k < r; k ++)
			{
				dp[l][r] = max(dp[l][r], dp[l][k] + dp[k+1][r] + data[l]*data[k+1]*data[r+1]);
				ans = max(ans, dp[l][r]);
			}
		}
	}
	fastwrite(ans);
	return 0;
}

inline int fastread()
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
inline void fastwrite(int x)
{
	if(x < 0) x = -x, putchar('-');
	if(x > 9) fastwrite(x / 10);
	putchar(x%10 + '0');
}
inline void fastwriteline(int x)
{
	fastwrite(x);
	putchar('\n');
}
