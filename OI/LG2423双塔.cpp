#include <bits/stdc++.h>
using namespace std;

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

#define maxn 110
#define maxtot 2010
int dp[maxn][maxtot], data[maxn];
int n, tot;

int main(void)
{
	n = fastread();
	for(int i = 1; i <= n; i++)
	{
		data[i] = fastread();
		tot += data[i];
	}
	memset(dp, -9001, sizeof(dp));
	dp[0][0] = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = tot; j >= 0; j--)
		{
			// put crystal i to the shorter tower to form delta j 
			dp[i][j] = max(dp[i][j], dp[i-1][j]);
			dp[i][j] = max(dp[i][j], dp[i-1][j+data[i]]);
			// put crystal i to the higher tower to form delta j 
			if(j >= data[i])
			{
				dp[i][j] = max(dp[i][j], dp[i-1][j-data[i]] + data[i]);
			}
			// shorter += higher 
			if(j <= data[i])
			{
				dp[i][j] = max(dp[i][j], dp[i-1][data[i]-j] + j);
			}
		}
	}
	if(dp[n][0] <= 0) puts("Impossible");
	else printf("%d", dp[n][0]);
}
