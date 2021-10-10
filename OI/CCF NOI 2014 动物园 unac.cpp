#prag\
ma GCC optimize("Ofast")

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define modn 1000000007
#define maxn 1000002
#define ll unsigned long long

inline int fastread ();
inline void fastwrite (ll);

int n, len, pt, next[maxn];
unsigned long long ans = 1ull;
char in[maxn];

int main ()
{
	n = fastread ();
	
	while (n --)
	{
		scanf ("%s", in);
		len = strlen (in);
		memset (next, 0, sizeof next);
		pt = 0;
		ans = 1ull;
		
		for (int i = 1; i < len; i ++)
		{
			while (pt && in[i] != in[pt]) pt = next[pt];
			next[i+1] = in[i]==in[pt]? ++pt:0;
		}
		
		pt = 0;
		for (int i = 1; i < len; i ++)
		{
			while (pt && in[i] != in[pt]) pt = next[pt];
			while ((pt<<1) > (i|1)) pt = next[pt];
			pt = pt|1;
			ans *= next[pt]|1;
			ans %= modn;
		}
		
		printf ("%lld", ans);
	}
}

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
inline void fastwrite (ll x)
{
	if(x < 0) x = -x, putchar('-');
	if(x > 9) fastwrite(x / 10);
	putchar(x%10 + '0');
}
