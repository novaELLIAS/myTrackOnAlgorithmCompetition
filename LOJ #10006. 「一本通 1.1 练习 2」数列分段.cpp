#pragma GCC optimize ("Ofast")

#include <stdio.h>
#include <ctype.h>
#include <queue>

using namespace std;

#define maxn 2000001
#define rint register int

inline int read ()
{
	int x = 0; char c = getchar(); bool m = 0;
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') c = getchar(), m = 1;
	while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = getchar();
	if (m) return -x;
	else return x;
}

int n, m, sum, x, ans;

int main ()
{
	n = read (), m = read ();
	
	for (rint i = 1; i <= n; i ++)
	{
		x = read ();
		if (sum + x > m) sum = x, ans ++;
		else sum += x;
	}
	
	printf ("%d", ans + 1);
	
	return 0;
}
