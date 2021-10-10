#include "stdio.h"

#define rint register int
#define ll long long

inline int read ()
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

inline void fastwrite (int x)
{
	if(x < 0) x = -x, putchar('-');
	if(x > 9) fastwrite(x / 10);
	putchar(x%10 + '0');
}

int n, m, k, tk, tn, tp;
int a[201][201];
char c[201][201];
int starty[201][201];
int startn[201][201];
int beginy[201][201];
int beginn[201][201];

int main ()
{
	
	freopen ("game.in", "r", stdin);
	freopen ("game.out", "w", stdout);
	
	n = read ();
	m = read ();
	k = read ();
	for (rint i = 1; i <= n; i ++)
	{
		for (rint j = 1; j <= m; j ++)
		{
			a[i][j] = read ();
			scanf ("%c", &c[i][j]);
		}
	}

	for (rint i = 1; i <= m; i ++)
	{
		tn = n;
		while (tn && c[tn][i] == 'Y')
		{
			starty[i][0] += a[tn][i];
			tn --;
		}
		for (rint j = 1; j <= n && tn; j ++)
		{
			startn[i][j] = starty[i][j-1] + a[tn][i];
			starty[i][j] = startn[i][j];
			tn --;
			while (tn && c[tn][i] == 'Y')
			{
				starty[i][j] += a[tn][i];
				tn --;
			}
		}
	}

	for (rint i = 1; i <= m; i ++)
	{
		for (rint j = 0; j <= k; j ++)
		{
			for (rint t = 0; t <= j; t ++)
			{
				tp = beginy[i-1][j-t] + starty[i][t];
				beginy[i][j] = beginy[i][j]<tp? tp:beginy[i][j];
				if (t != j)
				{
					tp = beginn[i-1][j-t] + starty[i][t];
					beginn[i][j] = tp>beginn[i][j]? tp:beginn[i][j];
				}
				if (t)
				{
					tp = beginy[i-1][j-t] + startn[i][t];
					beginn[i][j] = tp>beginn[i][j]? tp:beginn[i][j];
				}
			}
		}
	}

	fastwrite (beginn[m][k]);

	return 0;
}
