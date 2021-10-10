#prag\
ma GCC optimize("Ofast")

#include "stdio.h"

#define maxn 10001
#define maxd 20001
#define min(a,b) a<b? a:b
#define ll long long

inline ll fastread ();
inline void fastwrite (ll);
inline void fastwriteline (ll);
inline void fastwritespace (ll);

ll n, ans = 1e16;
ll l, cnt, sumd;
ll z[maxd], d[maxd];

int main ()
{
	n = fastread ();
	for (ll i = 1; i <= n; i ++)
	{
		z[i] = fastread ();
		z[i+n] = z[i];
		d[i] = fastread ();
		d[i+n] = d[i];
		sumd += d[i];
	}
	
	for (ll i = 1; i <= n; i ++)
	{
		l = d[i], cnt = 0;
		for (ll j = i+1; j <= i+n-1; j ++)
		{
			if (l <= sumd-l)
			{
				cnt += l*z[j];
				l += d[j];
			} else {
				cnt += (sumd-l)*z[j];
				l += d[j];
			}
		}
		ans = min (ans, cnt);
	}
	
	fastwrite (ans);
	
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
