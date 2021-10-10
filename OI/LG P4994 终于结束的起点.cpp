#pragma G++ optimize (3)

#include <cstdio>

signed main ()
{
	register int n; scanf ("%d", &n);
	register int cnt = 1, a = 1, b = 1, c = 0;
	while (true)
	{
		if (!a && b == 1) return printf ("%d", cnt), 0;
		c = (a + b) % n, a = b, b = c, ++ cnt;
	}
}
