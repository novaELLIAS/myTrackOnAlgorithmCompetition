#include <stdio.h>

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

#define maxn 110
#define maxm 10010

int n, m;
int data[maxn];
int dp[maxm];

int main(void)
{
	n = fastread();
	m = fastread();
	for(int i = 1; i <= n; i ++) data[i] = fastread();
	dp[0] = 1;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = m; j >= data[i]; j --)
		{
			dp[j] += dp[j-data[i]];
		}
	}
	fastwrite(dp[m]);
}
