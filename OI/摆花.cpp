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

#define maxm 110
#define modn 1000007
int n, m;
int dp[maxm][maxm], data[maxm];

int main()
{
	n = fastread();
	m = fastread();
	for(int i = 1; i <= n; i++) data[i] = fastread();
	for(int i = 0; i <= m; i++) dp[i][0] = 1;
	for(int i = 1; i <= n; i++) // varis of form  
	{
		for(int j = 1 /*0*/; j <= m ; j ++) // number of num 
		{
			for(int k = max(0, j-data[i]); k <= j; k++)
			{
				dp[i][j] += dp[i-1][k] % modn;
				dp[i][j] %= modn;
			}
		}
	}
	printf("%d", dp[n][m]);
}
