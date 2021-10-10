#include "stdio.h"

#define maxr 2147483647
#define maxn 1000010
#define maxl 1000000
#define ll long long

inline ll fastread();
inline void fastwrite(ll);
inline void fastwriteline(ll);
inline ll max(ll, ll);

ll l, r, ans;
bool nico[maxn], nico_s[maxn];

int main()
{
	
	l = fastread();
	r = fastread();
	
	//scanf("%lld%lld", &l, &r);
	int delta = r - l;
	for (ll i = 0; i*i <= r; i ++) nico_s[i] = true;
	for (ll i = 0; i <= delta; i ++) nico[i] = true;
	for (int i = 2; i*i <= r; i ++)
	{
		if (nico_s[i])
		{
			for (int j = 2*i;(ll) j*j <= r; j += i) nico_s[j] = false;
			for (ll j = max(2LL, (l+i-1)/i) * i; j <= r; j +=i) nico[j-l] = false;
		}
	}
	for (int i = 0; i <= delta; i ++)
	{
		if (nico[i]) ans ++;
	}
	//printf("%lld", ans);
	fastwrite(ans);
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
inline void fastwriteline(ll x)
{
	fastwrite(x);
	putchar('\n');
}
inline ll max (ll x, ll y)
{
	return x>y? x:y;
}
