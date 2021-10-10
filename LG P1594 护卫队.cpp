#include <stdio.h>

inline long long fastread();
inline void fastwrite(int);
inline void fastwriteline(int);

#define maxn 1010
#define min(x,y) x<y? x:y
#define ll long long

int n;
ll towei, tolong;
ll w[maxn], v[maxn], sum[maxn];
ll minv[maxn][maxn];
double dp[maxn];

int main()
{
	scanf("%lld %lld", &towei, &tolong);
	n = fastread();
	for (int i = 1; i <= n; i ++)
	{
		w[i] = fastread();
		v[i] = fastread();
		minv[i][i] = v[i];
		sum[i] = sum[i-1] + w[i];
	}
	for (int i = 1; i < n; i ++)
	{
		for (int j = i+1; j <= n; j ++)
		{
			minv[i][j] = min(v[j], minv[i][j-1]);
		}
	}
	for (int i = 1; i <= n; i ++)
	{
		dp[i] = (double) tolong/v[i] + dp[i-1];
		for (int j = i-1; j >= 1; j --)
		{
			if (sum[i] - sum[j-1] <= towei)
			{
				dp[i] = min(dp[i], dp[j-1] + (double) tolong/minv[j][i]);
			}
			else break;
		}
	}
	printf("%.1lf", dp[n] * 60);
	return 0;
}

inline ll fastread()
{
	ll sign = 1, n = 0;
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
