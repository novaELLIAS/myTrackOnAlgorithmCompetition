#include <bits/stdc++.h>
using namespace std;
#define maxn 110

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

int n, ans;
int dp[maxn][maxn], data[maxn];

int main(void)
{
	n = fastread();
	for(int i = 1; i <= n; i++)
	{
	data[i] = fastread();
	dp[i][1] = data[i];
	}
	for(int i = 2; i <= n; i++)
	{
		for(int s = 1; s <= n-i+1; s++)
		{
			dp[s][i] = abs(data[s]-data[s+i-1]) * i;
			for(int k = 1; k <= i; k++)
			{
			dp[s][i] = max(dp[s][i], dp[s][k] + dp[s+k][i-k]);
			}
		}
	}
	for(int i = 1; i <= n; i++) ans = max(ans, dp[i][n]);
	printf("%d", ans);
}
