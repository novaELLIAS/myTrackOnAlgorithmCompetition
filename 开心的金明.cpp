#include "stdio.h"

#define max(x,y) x>y? x:y
#define min(x,y) x<y? x:y

inline int fastread()
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

#define maxv 30010
#define maxm 26

struct node {
	int val, imp, wei;
}data[maxm];
int v, m;
int dp[maxv];

int main(void)
{
	v = fastread();
	m = fastread();
	for(int i = 1; i <= m; i ++)
	{
		data[i].val = fastread();
		data[i].imp = fastread();
		data[i].wei = data[i].val * data[i].imp;
	}
	for(int i = 1; i <= m; i ++)
	{
		for(int j = v; j >= data[i].val; j--)
		{
			if(dp[j] < dp[j-data[i].val] + data[i].wei)
			{
				dp[j] = dp[j-data[i].val] + data[i].wei;
			}
		}
	}
	printf("%d", dp[v]);
}
