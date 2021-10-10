#include <stdio.h>

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

#define maxt 1001
#define maxm 101

int t, m;
int dp[maxt], val[maxm], tim[maxm];

int main(void)
{
	t = fastread();
	m = fastread();
	for(int i = 1; i <= m; i ++)
	{
		tim[i] = fastread();
		val[i] = fastread();
	}
	for(int i = 1; i <= m; i ++)
	{
		for(int j = t; j >= tim[i]; j --)
		{
			if(dp[j] < dp[j-tim[i]] + val[i]){
				dp[j] = dp[j-tim[i]] + val[i];
			}
		}
	}
	printf("%d", dp[t]);
}
