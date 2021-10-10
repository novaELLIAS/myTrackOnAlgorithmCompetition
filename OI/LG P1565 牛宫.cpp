#prag\
ma GCC optimize("Ofast")

#include "stdio.h"

inline long long fastread ();
inline void fastwrite (long long);
inline void fastwriteline (long long);
inline void fastwritespace (long long);

#define max(a, b) a>b? a:b
#define ll long long
#define maxn 201
#define inff 23333333

ll n, m, ans, area, len;
ll data[maxn][maxn];
ll dp[maxn], rs[maxn];

inline ll findn (ll x)
{
	ll l = 1, r = len, ret = -1, mid;
	while (l <= r)
	{
		mid = (l+r) >> 1;
		if (dp[mid] < x)
		{
			r = mid - 1;
			ret = mid;
		} else l = mid + 1;
	}
	return ret;
}
int main ()
{
	n = fastread ();
	m = fastread ();
	ll in;
	for (ll i = 1; i <= n; i ++)
	{
		for (ll j = 1; j <= m; j ++)
		{
			in = fastread ();
			data[i][j] = data[i][j-1] + in;
		}
	}
	
	for (ll i = 1; i <= m; i ++)
	{
		for (ll j = 1; j <= m; j ++)
		{
			area = len = 0;
			dp[0] = inff;
			
			for (ll k = 1; k <= n; k ++)
			{
				area += data[k][j] - data[k][i-1];
				if (area > 0) ans = max (ans, k * (j-i+1));
				else {
					ll poss = findn (area);
					if (poss != -1) ans = max (ans, (j-i+1)*(k-rs[poss]));
				}
				if (dp[len] > area)
				{
					dp[++ len] = area;
					rs[len] = k;
				}
			}
			
			len = area = 0;
		}
	}
	
	printf("%lld", ans);
	
	return 0;
}

inline ll fastread ()
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
inline void fastwrite (ll x)
{
	if(x < 0) x = -x, putchar('-');
	if(x > 9) fastwrite(x / 10);
	putchar(x%10 + '0');
}
inline void fastwritespace (ll x)
{
	fastwrite(x);
	putchar(' ');
}
inline void fastwriteline (ll x)
{
	fastwrite(x);
	putchar('\n');
}
