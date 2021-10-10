#prag\
ma GCC optimize ("Ofast")

#include "stdio.h"
#include "string.h"

#define maxn 41
#define max(a,b) a>b? a:b
#define min(a,b) a<b? a:b

inline int fastread ();
inline void fastwrite (int);
inline void fastwritespace (int);

inline void dfs (int, int);
inline int dp (int, int);

int n, k, ansmax;
int dpw[100001], ans[maxn], tem[maxn];

int main ()
{
	n = fastread ();
	k = fastread ();
	
	dfs (1, 0);
	
	for (int i = 1; i <= k; i ++) fastwritespace (ans[i]);
	putchar ('\n');
	// printf ("MAX=");
	fastwrite (ansmax);
	
	return 0;
}


inline int dp (int tick, int maxx)
{
	memset (dpw, 127, sizeof dpw);
	dpw[0] = 0;
	
	for (int i = 1; i <= tick; i ++)
	{
		for (int j = tem[i]; j <= tem[i]*n; j ++)
		{
			dpw[j] = min (dpw[j], dpw[j-tem[i]] + 1);
		}
	}
	
	for (int i = 1; i <= tem[tick]*n; i ++)
	{
		if (dpw[i] > n) return i-1;
	}
	return tem[tick]*n;
}

inline void dfs (int tick, int maxx)
{
	if (tick > k)
	{
		if (ansmax < maxx)
		{
			ansmax = maxx;
			for (int i = 1; i <= k; i ++) ans[i] = tem[i];
			return;
		}
	} else {
		for (int i = tem[tick-1]+1; i <= maxx+1; i ++)
		{
			tem[tick] = i;
			dfs (tick+1, dp (tick, maxx));
		}
	}
}

inline int fastread ()
{
	int sign = 1, n = 0;
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
inline void fastwrite (int x)
{
	if(x < 0) x = -x, putchar('-');
	if(x > 9) fastwrite(x / 10);
	putchar(x%10 + '0');
}
inline void fastwritespace (int x)
{
	fastwrite(x);
	putchar(' ');
}
