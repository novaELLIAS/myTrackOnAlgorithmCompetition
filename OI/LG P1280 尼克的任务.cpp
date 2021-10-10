#pragma GCC optimize ("Ofast")

#include <stdio.h>
#include <ctype.h>
#include <algorithm>

using namespace std;

#define rint register int
#define maxn 10002

inline int read ()
{
	int x = 0; char c = getchar(); bool m = 0;
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') c = getchar(), m = 1;
	while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = getchar();
	if (m) return -x;
	else return x;
}

struct node {
	int sta, las;
} a[maxn];
int n, k, dp[maxn], pos = 1, to[maxn];

inline bool cmp (node aa, node bb) {return aa.sta > bb.sta;}

inline int maxx (int aa, int bb) {return aa>bb? aa:bb;}

int main ()
{
	n = read (), k = read ();
	for (rint i = 1; i <= k; i ++) a[i].sta = read (), a[i].las = read (), to[a[i].sta] ++;
	sort (a+1, a+k+1, cmp);
	for (rint i = n; i; i --)
	{
		if (!to[i]) dp[i] = dp[i+1] + 1;
		else {
			for (rint j = 1; j <= to[i]; j ++)
			{
				dp[i] = maxx (dp[i], dp[i + a[pos].las]);
				pos ++;
			}
		}
	}
	printf ("%d", dp[1]);
	return 0;
}
