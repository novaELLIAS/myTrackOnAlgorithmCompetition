#prag\
ma CGG optimize ("Ofast")

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

int ans, n, k, p, pris[200002], colr[200002], minn;

int main ()
{
	freopen ("testtable.in", "r", stdin);
	scanf ("%d %d %d", &n, &k, &p);
	
	for (register int i = 1; i <= n; i ++)
	{
		colr[i] = fastread ();
		pris[i] = fastread ();
	}
	
	for (register int i = 1; i < n; i ++)
	{
		minn = pris[i];
		for (register int j = i+1; j <= n; j ++)
		{
			minn = min (minn, pris[j]);
			if (minn > p) continue;
			if (colr[j] != colr[i]) continue;
			ans ++;
		}
	}
	
	printf ("%d", ans);
	
	return 0;
}
