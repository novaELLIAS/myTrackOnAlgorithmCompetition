#include <stdio.h>
#include <string.h>

#define max(a,b) a>b? a:b
#define min(a,b) a<b? a:b
#define maxn 110

int n, m, ans = 2333333;
int a, b, c;
int mapp[maxn][maxn];
int dis[maxn][maxn];

int main()
{
	scanf("%d %d", &n, &m);
	memset(mapp, 127/3, sizeof(mapp));
	memset(dis, 127/3, sizeof(dis));
	for (int i = 1; i <= n; i ++)
	{
		mapp[i][i] = 0;
	}
	for (int i = 1; i <= m; i ++)
	{
		scanf("%d %d %d", &a, &b, &c);
		mapp[a][b] = mapp[b][a] = c;
		dis[b][a] = dis[a][b] = c;
	}
	for (int k = 1; k <= n; k ++)
	{
		for (int i = 1; i <= k-1; i ++)
		{
			for (int j = i+1; j < k; j ++)
			{
				ans = min(ans, dis[i][j] + mapp[j][k] + mapp[k][i]);
			}
		}
		for (int i = 1; i <= n; i ++)
		{
			for (int j = 1; j <= n; j ++)
			{
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	if (ans == 2333333) puts("no");
	else printf("%d", ans);
	return 0;
}
