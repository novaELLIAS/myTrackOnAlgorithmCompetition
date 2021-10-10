#include <cstdio>

using namespace std;

/****************************************************/
inline char gc()
{
	static char buf[1<<14],*p1=buf,*p2=buf;
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0; register char c = gc();
	while (c < '0' || c > '9') c = gc();
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c - '0'), c = gc();
	return x;
}
/****************************************************/

#define Re register
#define maxn 20001 

/****************************************************/
struct edge {
	int nex, to, wei;
} e[maxn << 1];
int head[maxn], ecnt;
/****************************************************/

int dp[maxn][3], ans, modn;

inline int mmod (register int x) {return (x % 3 + 3) % 3;}

static int gcd (register int a, register int b) {return b? gcd (b, a%b):a;}

inline void nico_dfs (register int x, register int fa)
{
	register int to, va, j; dp[x][0] = 1;
	for (Re int i = head[x]; i; i = e[i].nex)
	{
		to = e[i].to, va = e[i].wei;
		if (to ^ fa)
		{
			nico_dfs (to, x);
			for (j = 0; j ^ 3; j ++) ans += dp[to][j] * dp[x][(3 - (j + va) % 3) % 3];
			for (j = 0; j ^ 3; j ++) dp[x][(j + va) % 3] += dp[to][j];
		}
	}
}

int main ()
{
	register int n = read(), u, v, va;
	for (Re int i = 1; i ^ n; i ++)
	{
		u = read (), v = read (), va = read ();
		e[++ ecnt].to = v, e[ecnt].wei = va, e[ecnt].nex = head[u], head[u] = ecnt;
		e[++ ecnt].to = u, e[ecnt].wei = va, e[ecnt].nex = head[v], head[v] = ecnt;
	}
	nico_dfs (1, 0);
	ans <<= 1;ans += n; register int div = gcd (ans, n * n);
	printf ("%d/%d", ans / div, n * n / div);
	
	return 0;
} 
