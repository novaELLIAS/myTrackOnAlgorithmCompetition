#pragma GCC optimzie ("Ofast")

#include "stdio.h"
#define ll long long

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

ll x, y, temp;

inline void exgcd (ll a, ll b)
{
	if (!b)
	{
		x = 1;
		y = 0;
		return;
	}
	exgcd (b, a % b);
	temp = x;
	x = y;
	y = temp - a / b * y;
}

int main ()
{
	
	ll a = fastread ();
	ll b = fastread ();
	
	exgcd (a, b);
	
	printf ("%I64d", (x + b) % b);
	
	return 0;
}
