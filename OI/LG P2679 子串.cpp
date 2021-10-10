#pragma GCC optimize ("Ofast")

#include "stdio.h"

#define rint register int
#define modn 1000000007
#define maxn 1001
#define maxm 201

inline int read () {
	int x = 0; char c = getchar(); bool m = 0;
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') c = getchar(), m = 1;
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x;
	else return x;
}

int n, m, k;
int dp[2][maxn][maxm][2];
char a[maxn], b[maxm];

int main ()
{
	n = read (), m = read (), k = read ();
	for (rint i = 1; i <= n; i ++) a[i] = getchar (); getchar ();
	for (rint i = 1; i <= m; i ++) b[i] = getchar (); getchar ();
	
	dp[0][0][0][0] = dp[1][0][0][0] = 1;
	for (rint i = 1; i <= n; i ++)
	{
		for (rint j = 1; j <= m; j ++)
		{
			for (rint w = 1; w <= k; w ++)
			{
				
			}
		}
	}
}
