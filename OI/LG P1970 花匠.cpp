#pragma GCC optimize ("Ofast")

#include "stdio.h"
#define max(a,b) (a)>(b)? (a):(b)

int ans = 1, n, last, in;
short flag;

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

int main ()
{
	n = fastread ();
	if (n == 1) {putchar ('1'); return 0;}
	last = fastread ();
	
	for (register int i = 2; i <= n; i ++)
	{
		in = fastread ();
		if (in != last)
		{
			if (flag != 1 && in > last)
			{
				ans ++;
				flag = 1;
			} else {
				if (flag != 2 && in < last)
				{
					ans ++;
					flag = 2;
				}
			}
			last = in;
		}
	}
	
	printf ("%d", ans);
	
	return 0;
}
