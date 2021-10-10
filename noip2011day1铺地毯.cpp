#prag\
ma GCC optimize ("Ofast")

#include "stdio.h"

int x, y;
int n, mapp[10001][4];

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
	scanf ("%d", &n);
	for (register int i = 1; i <= n; i ++)
	{
		for (register int j = 0; j < 4; j ++)
		{
			mapp[i][j] = fastread ();
		}
		mapp[i][2] += mapp[i][0];
		mapp[i][3] += mapp[i][1];
	}
	
	scanf ("%d %d", &x, &y);
	
	for (register int i = n; i >= 1; i --)
	{
		if (x >= mapp[i][0] && x <= mapp[i][2] && y >= mapp[i][1] && y <= mapp[i][3])
		{
			printf ("%d", i);
			return 0;
		}
	}
	
	puts ("-1");
	
	return 0;
}
