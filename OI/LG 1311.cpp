#prag\
ma GCC optimize ("Ofast")

#include "stdio.h"

#define max(a,b) a>b? a:b
#define min(a,b) a<b? a:b

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

int n, k, p, ans;
int clor, pris, now;
int last[200001], cnt[200001], sum[200001];

int main ()
{
	// freopen ("testtable.in", "r", stdin);
	scanf ("%d %d %d", &n, &k, &p);
	
	for (register int i = 1; i <= n; i ++)
	{
		clor = fastread ();
		pris = fastread ();
		if (pris <= p) now = i;
		if (now >= last[clor]) sum[clor] = cnt[clor];
		last[clor] = i;
		ans += sum[clor];
		cnt[clor] ++;
	}
	
	printf ("%d", ans);
	
	return 0;
}
