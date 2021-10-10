#prag\
ma GCC optimize("Ofast")

#include "stdio.h"

inline long fastread ();
inline void fastwrite (long);
inline void fastwriteline (long);
inline void fastwritespace (long);

#define maxn 251
#define min(a,b) a<b? a:b
#define max(a,b) a>b? a:b

int n, r;
long mapp[maxn][maxn];
long tott[maxn][maxn];
long ans;
long maxx, maxy, minx, miny;

inline void init_max (long i, long j)
{
	maxx = min (n, i+r);
	minx = max (1, i-r);
	maxy = min (n, j+r);
	miny = max (1, j-r);
}
int main ()
{
	n = fastread ();
	r = fastread ();
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= n; j ++)
		{
			mapp[i][j] = fastread ();
		}
	}
	
	long k = 0;
	for (int i = 1; i <= n; i ++)
	{
		// printf("2333333\n");
		k = 0;
		for (int j = 1; j <= n; j ++)
		{
			// printf("niconi\n");
			k += mapp[i][j];
			tott[i][j] = tott[i-1][j] + k;
		}
		// printf("nicothesecond\n");
	}
	
	for (long i = 1; i <= n; i ++)
	{
		for (long j = 1; j <= n; j ++)
		{
			init_max (i, j);
			ans = tott[maxx][maxy];
			ans -= tott[minx-1][maxy];
			ans -= tott[maxx][miny-1];
			ans += tott[minx-1][miny-1];
			// printf("%ld ", ans);
			fastwritespace (ans);
		}
		putchar ('\n');
	}
	
	return 0;
}

inline long fastread ()
{
	long sign = 1, n = 0;
	char c = getchar();
	while(c < '0' || c > '9')
	{
		if(c == '-') sign = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9')
	{
		n = n*10 + c-'0';
		c = getchar();
	}
	return sign*n;
}
inline void fastwrite (long x)
{
	if(x < 0) x = -x, putchar('-');
	if(x > 9) fastwrite(x / 10);
	putchar(x%10 + '0');
}
inline void fastwritespace (long x)
{
	fastwrite(x);
	putchar(' ');
}
inline void fastwriteline (long x)
{
	fastwrite(x);
	putchar('\n');
}
