#pragma G++ optimize ("Ofast", 3)

#include <cstdio>
#include <string.h>

static char buf[1<<14],*p1=buf,*p2=buf;
inline char gc()
{
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0; register char c = gc();
	while (c < '0' || c > '9') c = gc();
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return x;
}
inline const int& minint (const int& a, const int& b) {return a<b? a:b;}
inline const double& mindou (const double& a, const double& b) {return a<b? a:b;}

#define Re register
#define maxz 51
#define maxn 51
#define maxm 301

struct edge {
	int to, val, nex;
} e[maxm];
int head[maxn], ecnt;
int deg[maxn], sum, dp[maxn][21][16001];
int que[6001];

int main ()
{
	freopen ("library.in", "r", stdin);
	freopen ("library.out","w",stdout);
	
	register int n = read (), m = read (), x, y, w;
	memset (dp, 127, sizeof dp); dp[1][0][0] = 0;
	while (m --)
	{
		x = read (), y = read (), w = read (), sum += w;
		++ deg[y], e[++ ecnt].to = y, e[ecnt].val = w, e[ecnt].nex = head[x], head[x] = ecnt;
	}
	
	register int hd = 1, tl = 0;
	for (Re int i = 1; i <= n; ++ i) if (!deg[i]) que[++ tl] = i;
	while (hd <= tl)
	{
		y = que[hd ++];
		for (Re int j = 1; j <= 20; ++ j)
		{
			for (Re int k = 0; k <= sum; ++ k)
			{
				{
					for (Re int i = head[y]; i; i = e[i].nex)
					{
						x = e[i].to, w = e[i].val;
						if (k + w <= sum) dp[x][j][k+w] = minint (dp[x][j][k+w], dp[y][j-1][k] + w*w);
					}
				}
			}
		}
		for (Re int i = head[y]; i; i = e[i].nex) if (!(-- deg[e[i].to])) que[++ tl] = e[i].to;
	}
	
	register double ans = 1000000000.0;
	for (Re int i = 1; i <= 20; ++ i)
	{
		for (Re int j = 0; j <= sum; ++ j)
		{
			ans = mindou (ans, (1.0*dp[n][i][j]/i) - ((1.0*j*j)/(1.0*i*i)));
		}
	}
	
    printf("%.4lf", ans);
    
    fclose (stdin), fclose (stdout);
    
	return 0;
}
