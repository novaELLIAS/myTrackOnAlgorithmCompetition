#pragma GCC optimize ("Ofast")

#include "stdio.h"
#include "iostream"
/*
#define max(a,b) (a>b? a:b)
#define min(a,b) (a<b? a:b)
*/
using namespace std;

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

int n, m, k, ans, pos, maxx, cnt;
int dis[1001], last[1001], down[1001], arrive[1001], dp[1001];
int tim[10001], sta[10001], til[10001];

int main ()
{
    scanf ("%d %d %d", &n, &m, &k);
    for (register int i = 2; i <= n; i ++) dis[i] = fastread ();
    for (register int i = 1; i <= m; i ++)
    {
        tim[i] = fastread ();
        sta[i] = fastread ();
        til[i] = fastread ();
        last[sta[i]] = max (last[sta[i]], tim[i]);
        down[til[i]] ++;
    }
    for (register int i = 2; i <= n; i ++) arrive[i] = max (arrive[i-1], last[i-1]) + dis[i];
	for (register int i = 1; i <= m; i ++) ans += arrive[til[i]] - tim[i];
    while (k)
    {
        for (register int i = n; i >= 2; i --)
        {
            if (!dis[i]) dp[i] = 0;
            else  {
                if (last[i] < arrive[i]) dp[i] = dp[i+1] + down[i];
                else dp[i] = down[i];
            }
        }
        
        pos = maxx = 0;
        
        for (register int i = 1; i <= n; i ++)
        {
            if (dp[i] > maxx)
            {
                maxx = dp[i];
                pos = i;
            }
        }
        if (!pos) break;
        cnt = dis[pos];
        for (register int i = pos+1; i <= n; i ++)
    	{
    		cnt = min (cnt, arrive[i] - last[i]);
		}
        cnt = min (k, cnt);
        cnt = min (cnt, dis[pos]);
        k -= cnt;
        ans -= cnt * dp[pos];
        // dis[pos] -= cnt;
        
        for (register int i = pos+1; i <= n; i ++) arrive[i] -= cnt; /*arrive[i] = max (arrive[i-1], last[i-1]) + dis[i];*/
    }
    
    // for (register int i = 1; i <= m; i ++) ans += arrive[til[i]] - tim[i];
    
    printf ("%d", ans);
    
    return 0;
}
