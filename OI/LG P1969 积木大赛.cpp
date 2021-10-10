#pragma GCC optimize ("Ofast")

#include "stdio.h"

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

int n, in, ans, last;

int main ()
{
	n = fastread ();
	for (register int i = 1; i <= n; i ++)
	{
		in = fastread ();
		if (in > last) ans += (in - last);
		last = in;
	}
	printf ("%d", ans);
	return 0;
}
