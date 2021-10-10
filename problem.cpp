#pragma GCC optimize ("Ofast") 

#include "stdio.h"
#include "ctype.h"

#define rint register int
#define maxn 2001

inline int read ()
{
	int x = 0; char c = getchar(); bool m = 0;
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') c = getchar(), m = 1;
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x;
	else return x;
}

int k, n, m;
int reltable[maxn][maxn], sumtable[maxn][maxn];

inline void nico_build (const int modn)
{
	reltable[1][1] = 1;
	for (rint i = 0; i <= 2000; i ++) reltable[i][0] = 1;
	for (rint i = 2; i <= 2000; i ++)
	{
		for (rint j = 1; j <= i; j ++) reltable[i][j] = (reltable[i-1][j] + reltable[i-1][j-1]) % modn;
	}
	for (rint i = 2; i <= 2000; i ++)
	{
		for (rint j = 1; j <= i; j ++)
		{
			sumtable[i][j] = sumtable[i-1][j] + sumtable[i][j-1] - sumtable[i-1][j-1];
			if (!reltable[i][j]) sumtable[i][j] ++;
		}
		sumtable[i][i+1] = sumtable[i][i];
	}
}

int main ()
{
	freopen ("problem.in","r",stdin);
	freopen ("problem.out","w",stdout);
	
	int _ = read ();
	k = read ();
	nico_build (k);
	/*
	for (rint i = 1; i <= 10; i ++)
	{
		for (rint j = 1; j <= i; j ++)
		{
			printf ("%d ", reltable[i][j]);
		}
		putchar ('\n');
	}
	*/
	while (_ --)
	{
		n = read (), m = read ();
		if (m > n) m = n;
		printf ("%d\n", sumtable[n][m]);
	}
	
	return 0;
}
