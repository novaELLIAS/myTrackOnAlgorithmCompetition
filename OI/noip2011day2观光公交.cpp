#prag\
ma GCC optimize ("Ofast")

#include "stdio.h"

#define max(a,b) a>b? a:b
#define min(a,b) a<b? a:b

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

int n, m, k, ans, cntt, pos;
int dis[1001], car[1001], cnt[1001], rlt[1001], dp[1001];
int tim[10001], sta[10001], til[10001];

int main ()
{
	scanf ("%d %d %d", &n, &m, &k);
	for (register int i = 1; i < n; i ++) dis[i] = fastread ();
	for (register int i = 1; i <= m; i ++)
	{
		tim[i] = fastread ();
		sta[i] = fastread ();
		til[i] = fastread ();
		rlt[sta[i]] = max (rlt[sta[i]], tim[i]);
		cnt[til[i]] ++;
	}
	
	for (register int i = 2; i <= m; i ++) cnt[i] += cnt[i-1];
	car[1] = rlt[1];
	for (register int i = 2; i <= n; i ++) car[i] = max (car[i-1], rlt[i-1]) + dis[i-1];
	for (register int i = 1; i <= m; i ++) ans += car[til[i]] - rlt[i];
	
	while (k --)
	{
		cntt = 0;
		dp[n] = dp[n-1] = n;
		
		for (register int i = n-2; i >= 1; i --) dp[i] = car[i+1]<=rlt[i+1]? i+1:dp[i+1];
		for (register int i = 1; i < n; i ++)
		{
			if (cnt[dp[i]] - cnt[i] > cntt && dis[i])
			{
				cntt = cnt[dp[i]] - cnt[i];
				pos = i;
			}
		}
		ans -= cntt;
		dis[pos] --;
		
		for (int i = 2; i <= n; i ++) car[i] = max (car[i-1], rlt[i-1]) + dis[i-1];
	}
	
	printf ("%d", ans);
	
	return 0;
}
