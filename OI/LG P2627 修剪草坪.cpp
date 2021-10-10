#include "stdio.h"

inline long long fastread();
inline void fastwrite(long long);
inline void fastwriteline(long long);
inline void fastwritespace(long long x);

#define ll long long
#define max(a, b) a>b? a:b
#define min(a, b) a<b? a:b
#define maxn 100001
#define maxe 1000000001

int n, k, l, r;
ll sum, data[maxn];
ll dp[maxn], que[maxn];

int main ()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i ++)
	{
		data[i] = fastread();
		sum += data[i];
	}
	
	l = r = 1;
	
	for (int i = 1; i <= n; i ++)
	{
		while (l <= r && i - que[l] > k + 1) l ++;
		dp[i] = data[i] + dp[que[l]];
		while (l <= r && dp[que[r]] >= dp[i]) r --;
		que[++ r] = i;
	}
	for (int i = n - k; i < n; i ++)
	{
		dp[i+1] = min(dp[i+1], dp[i]);
	}
	
	printf("%I64d", sum - dp[n]);
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
inline void fastwrite(ll x)
{
	if(x < 0) x = -x, putchar('-');
	if(x > 9) fastwrite(x / 10);
	putchar(x%10 + '0');
}
inline void fastwritespace(ll x)
{
	fastwrite(x);
	putchar(' ');
}
inline void fastwriteline(ll x)
{
	fastwrite(x);
	putchar('\n');
}
