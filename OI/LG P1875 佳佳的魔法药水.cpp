#include <stdio.h>

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
inline void fastwrite(int x)
{
	if(x < 0) x = -x, putchar('-');
	if(x > 9) fastwrite(x / 10);
	putchar(x%10 + '0');
}
inline void fastwriteline(int x)
{
	fastwrite(x);
	putchar('\n');
}

#define maxn 1010
#define maxint 0x7fffffff

int n;
int make[maxn][maxn];
int cost[maxn];
int ans[maxn];
bool visit[maxn];

int main(void)
{
	n = fastread();
	for(int i = 1; i <= n; i ++) cost[i] = fastread();
	for(int i = 1; i <= n; i ++) ans[i] = 1;
	int a, b, c;
	while(scanf("%d %d %d", &a, &b, &c) != EOF)
	{
		a++, b++, c++;
		make[a][b] = make[b][a] = c;
	}
	for(int tim = 1; tim <= n-1 ; tim ++)
	{
		int maxx = maxint;
		int pos;
		for(int i = 1; i <= n; i ++)
		{
			if(!visit[i] && cost[i] < maxn)
			{
				pos = i;
				maxx = cost[i];
			}
		}
		visit[pos] = true;
		for(int i = 1; i <= n; i ++)
		{
			if(visit[i] && make[pos][i])
			{
				int cc = make[pos][i];
				if(cost[pos] + cost[i] == cost[cc])
				{
					ans[cc] += ans[pos] * ans[i];
				}
				else if(cost[pos] + cost[i] < cost[cc])
				{
					cost[cc] = cost[pos] + cost[i];
					ans[cc] = ans[pos] * ans[i];
				}
			}
		}
	}
	fastwrite(cost[1]);
	putchar(' ');
	fastwrite(ans[1]);
}
