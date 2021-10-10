#prag\
ma GCC optimize ("Ofast")

#include "stdio.h"
#include "string.h"

#define max(a,b) a>b? a:b

inline void fastwrite (int x)
{
	if(x < 0) x = -x, putchar('-');
	if(x > 9) fastwrite(x / 10);
	putchar(x%10 + '0');
}
inline void add (int *aa, int *bb)
{
	int len = 0, x = 0;
	while (len < aa[0] || len < bb[0])
	{
		aa[++ len] = aa[len] + bb[len] + x;
		x = aa[len] / 10;
		aa[len] %= 10;
	}
	if (x > 0) aa[++ len] = x;
	aa[0] = len;
}

int k, w, kk, ww, maxy, miny, a[201][201];
int ans[201];

int main ()
{
	scanf ("%d %d", &k, &w);

	kk = w % k;
	ww = w / k;
	for (register int i = 1; i <= kk; i ++) maxy += 1 << (i-1);
	miny = (1<<k) - 1;

	for (register int i = 1; i < miny; i ++)
	{
		a[i][1] = i;
		a[i][0] = 1;
		add (ans, a[i]);
	}
	for (register int i = 1; i <= ww; i ++)
	{
		for (register int j = 1; j <= miny-i+1; j ++)
		{
			add (a[j], a[j-1]);
			add (ans, a[j]);
		}
	}
	for (register int j = 1; j <= miny - ww; j ++) add (a[j], a[j-1]);
	for (register int j = miny - ww; j >= max (miny - ww - maxy + 1, 1); j --) add (ans, a[j]);
	
	for (register int i = ans[0]; i >= 1; i --) fastwrite (ans[i]);

	return 0;
}
