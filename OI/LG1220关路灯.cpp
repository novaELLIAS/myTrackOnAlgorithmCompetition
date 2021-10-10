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

#define maxn 60
#define nico 100000001
int n, c, sum[maxn], pos[maxn];
int dp[maxn][maxn][2];

int main(void)
{
	n = fastread();
	c = fastread();
	for(int i = 1; i <= n; i++)
	{
		pos[i] = fastread();
		sum[i] = fastread();
		sum[i] += sum[i-1];
	}
	for(int len = n-1; len >= 1; len--)
	{
		for(int l = 1; l+len <= n+1; l++)
		{
			int r = l+len-1;
			for(int s = 0; s <= 1; s++)
			{
				int x = s==0? l:r;
				dp[l][r][s] = nico;
				if (l > 1)
				{
					dp[l][r][s] = min(dp[l][r][s], dp[l-1][r][0] + (pos[x]-pos[l-1])*(sum[n]-sum[r]+sum[l-1]));
				}
				if (r < n)
				{
					dp[l][r][s] = min(dp[l][r][s], dp[l][r+1][1] + (pos[r+1]-pos[x])*(sum[n]-sum[r]+sum[l-1]));
				}
			}
		}
	}
	printf("%d", dp[c][c][0]);
}
