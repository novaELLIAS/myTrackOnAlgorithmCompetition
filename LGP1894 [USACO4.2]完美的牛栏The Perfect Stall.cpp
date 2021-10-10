#include <stdio.h>
#include <string.h>

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

#define maxn 210

int n, m, ans;
bool data[maxn][maxn];
bool visit[maxn];
int stall[maxn];

bool hungry(int x)
{
	for(int i = 1; i <= m; i ++)
	{
		if(visit[i] == false && data[x][i])
		{
			visit[i] = true;
			if(stall[i] == 0 || hungry(stall[i]))
			{
				stall[i] = x;
				return true;
			}
		}
	}
	return false;
}
int main(void)
{
	n = fastread();
	m = fastread();
	for(int i = 1; i <= n; i ++)
	{
		int tos = fastread();
		while(tos --)
		{
			int tempp = fastread();
			data[i][tempp] = true;
		}
	}
	for(int i = 1; i <=n ; i++)
	{
		memset(visit, false, sizeof visit);
		if(hungry(i)) ans++;
	}
	printf("%d", ans);
}
