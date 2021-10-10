#prag\
ma GCC optimize ("Ofast")

#include <bits/stdc++.h>
#define mond 10007

using namespace std;

int a[1001][1001];

int main ()
{
	a %= modn;
	b %= modn;
	freopen ("testtable000.out", "w", stdout);
	for (int i = 1; i <= 1000 ; i ++)
	{
		a[i][1] = 1;
		for (int j = 2; j <= i; j ++)
		{
			a[i][j] = (a[i-1][j-1] + a[i-1][j]) % mond;
		}
	}
	for (int i = 1; i <= 1000; i ++)
	{
		putchar ('{');
		for (int j = 1; j < 1000; j ++)
		{
			printf ("%d ,", a[i][j]);
		}
		printf ("%d", a[i][1000]);
		putchar ('}');
		putchar (',');
		putchar ('\n');
	}
}
