#prag\
ma G++ optmize (3)

#include <cstdio>

#define Re register
#define maxn 1005

int dat[maxn];

signed main ()
{
	register int n, m, c;
	scanf ("%d %d %d", &n, &m, &c);
	register int x, pos, cnt = 0;
	while (m --)
	{
		scanf ("%d", &x);
		if ((x<<1) <= c)
		{
			for (pos = 1; dat[pos] && dat[pos]<=x; ++ pos);
			cnt += dat[pos]? 0:1, dat[pos] = x;
			printf ("%d\n", pos);
		} else {
			for (pos = n; dat[pos] >= x; -- pos);
			cnt += (pos && !dat[pos])? 1:0, dat[pos]=x;
			printf ("%d\n", pos);
		}
		fflush (stdout);
		if (cnt >= n) return 0;
	}
	return 0;
}
