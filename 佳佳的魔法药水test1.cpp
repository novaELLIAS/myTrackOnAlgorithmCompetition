#include <stdio.h>

#define maxm 1001

int cost[maxm], ans[maxm];
int make[maxm][maxm];
bool visit[maxm];
int n, pos;

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &cost[i]);
        ans[i]=1;
    }
    int a, b, c; 
    while(scanf("%d%d%d", &a, &b, &c) != EOF)
    {
        make[a+1][b+1] = make[b+1][a+1] = c+1;
    }
    for(int ti = 1; ti < n; ti++)
    {
        int maxn = 0x7fffffff;
        for(int i = 1; i <= n; i ++)
        {
            if(!visit[i] && cost[i]<maxn)
            {
                pos = i;
                maxn = cost[i];
            }
        }
        visit[pos] = 1;
        for(int i = 1; i <= n; i ++)
        if(visit[i] && make[pos][i])
        {
        	if(visit[i])
        	{
        		if(cost[pos]+cost[i] <= cost[make[pos][i]])
        		{
                	if(cost[pos]+cost[i] == cost[make[pos][i]])
                	{
                    	ans[make[pos][i]] += ans[pos]*ans[i];
                    } else {
                    	ans[make[pos][i]] = ans[pos]*ans[i];
                    	cost[make[pos][i]] = cost[pos]+cost[i];
                	}
            	}
			}
			else {
				if(cost[pos]+cost[i] <= cost[make[pos][i]])
        		{
                	if(cost[pos]+cost[i] == cost[make[pos][i]])
                	{
                    	ans[make[pos][i]] += ans[i];
                    } else {
                    	ans[make[pos][i]] = ans[pos]*ans[i];
                    	cost[make[pos][i]] = cost[pos]+cost[i];
                	}
            	}
			}
        }
    }
    printf("%d %d", cost[1], ans[1]);
    return 0;
}
