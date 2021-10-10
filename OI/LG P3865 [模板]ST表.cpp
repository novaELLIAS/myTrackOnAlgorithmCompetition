#include <stdio.h>
#include <ctype.h>
#include <math.h>

inline char gc()
{
	static char buf[1<<14],*p1=buf,*p2=buf;
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
}

inline int read ()
{
	register int x = 0;register char c = gc();
	while (!isdigit(c)) c = gc();
	while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
	return x;
}

inline const int& max (const int&a, const int&b) {return a>b? a:b;}

#define rint register int

int dat[100001][21];

inline int query (int l, int r)
{
	register int t = log2 (r - l + 1);
	return max (dat[l][t], dat[r-(1<<t)+1][t]);
}

int main ()
{
	register int n = read(), m = read(), top = ceil(log2(n)), tmp;
	for (rint i = 1; i <= n; i ++) dat[i][0] = read ();
	for (rint j = 1; j <= top; j ++)
	{
		tmp = n + 1 - (1 << j);
		for (rint i = 1; i <= tmp; i ++)
		{
			dat[i][j] = max (dat[i][j-1], dat[i+(1<<(j-1))][j-1]);
		}
	}
	register int l, r;
	while (m --)
	{
		l = read (), r = read ();
		printf ("%d\n", query (l, r));
	}
}
