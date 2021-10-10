#pragma GCC optimize ("Ofast")

#include "stdio.h"
#include "iostream"

using namespace std;

#define maxn 200001
#define modn 10007
#define ll long long
#define rint register int

inline int read () {
	int sign = 1, n = 0;
	char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') sign = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		n = (n*10) + c-'0';
		c = getchar();
	}
	return sign*n;
}

int n, x, y;
int head[maxn], next[maxn<<1], to[maxn<<1], cnt;
int valu[maxn];
int sumans, maxans;

inline void add (int xx, int yy)
{
	to[++ cnt] = yy;
	next[cnt] = head [xx];
	head [xx] = cnt;
}

inline void nico (int pos)
{
	int aresum = 0, aremax = -1;
	for (rint i = head[pos]; i; i = next[i])
	{
		sumans = (sumans + (aresum * valu[to[i]])) % modn;
		maxans = max (maxans, aremax * valu[to[i]]);
		aresum = (aresum + valu[to[i]]) % modn;
		aremax = max (aremax, valu[to[i]]);
	}
}

int main ()
{
	freopen ("link.in", "r", stdin);
	freopen ("link.out", "w", stdout);
	n = read ();
	for (rint i = 1; i < n; i ++)
	{
		x = read (), y = read ();
		add (x, y), add (y, x);
	}
	for (rint i = 1; i <= n; i ++) valu[i] = read ();
	
	for (rint i = 1; i <= n; i ++) nico (i);
	
	printf ("%d %d", maxans, (sumans * 2) % modn);
	
	return 0;
}
