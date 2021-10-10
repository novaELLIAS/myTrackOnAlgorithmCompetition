
#include <cstdio>
#include <string.h>
const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;	
inline char gc()
{
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0; register char c = gc(); register bool m = 0;
	while (c < '0'|| c > '9') {if (c == '-') m = true; c = gc();}
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return m? -x:x;
}
inline const int& min (const int& a, const int& b) {return a<b? a:b;}
inline const int& max (const int& a, const int& b) {return a>b? a:b;}
#define Re register
#define maxn 100001
#define maxm 200001
#define maxk 300001
const int inf = -0x3f3f3f3f;
struct edge {
	int to, nex;
} e[maxm<<3];
int h[maxm], ecnt;
int degr[maxm], weit[maxm];
int que[10000001];
int dp[maxm][55];
int main ()
{
	register int n=read(),m=read(),k=read(),disa=read()-1,disb=read()-1,csta=read(),cstb=read();
	if (disa > disb) disb ^= disa ^= disb ^= disa;
	register int fr, to, va, head=0, tail=0;
	memset (dp, -0x3f3f3f3f, sizeof dp);
	for (Re int i = 0; i ^ n; ++ i) fr=read(), weit[fr] += read();
	for (Re int i = 0; i ^ k; ++ i)
	{
		fr=read(), to=read(), ++ degr[to];
		e[++ ecnt].to = to, e[ecnt].nex = h[fr], h[fr] = ecnt;
	}
	for (Re int i = 2; i <= m; ++ i) if (!degr[i]) que[++ tail] = i;
	while (head < tail)
	{
		fr = que[++ head];
		for (Re int i = h[fr]; i; i = e[i].nex)
		{
			to = e[i].to, -- degr[to];
			if (!degr[to] && (to != 1)) que[++ tail] = to;
		}
	}
	que[++ tail] = 1, dp[1][0] = weit[1];
	
	while (head < tail)
	{
		fr = que[++ head];
		
		for (Re int i = h[fr]; i; i = e[i].nex)
		{
			to = e[i].to, -- degr[to];
			if (!degr[to] && (to != 1)) que[++ tail] = to;
		}
		
		for (Re int i = h[fr]; i; i = e[i].nex)
		{
			to = e[i].to;
			if (dp[fr][0] ^ inf)
			{
				if (disa) dp[to][disa] = max (dp[to][disa], dp[fr][0] - csta);
				else dp[to][0] = max (dp[to][0], dp[fr][0] - csta + weit[to]);
				if (disb) dp[to][disb] = max (dp[to][disb], dp[fr][0] - cstb);
				else dp[to][0] = max (dp[to][0], dp[fr][0] - cstb + weit[to]);
			}
			
			if (dp[fr][1] ^ inf)
			{
				dp[to][0] = max (dp[to][0], dp[fr][1] + weit[to]);
				for (Re int j = disb; j; -- j)
				{
					if (dp[fr][j+1] ^ inf) dp[to][j] = max (dp[to][j], dp[fr][j+1]);
				}
			}
		}
	}
	register int ans = inf;
	for (Re int i = 1; i <= m; ++ i) ans = max (ans, dp[i][0]);
	printf ("%d", ans);
	return 0;
}
