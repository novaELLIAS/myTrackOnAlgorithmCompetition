#pragma G++ optimize ("Ofast", 3)

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
#define maxn 50001

/****************************************************/
struct edge {
	int nex, to, wei;
} e[maxn << 1];
int head[maxn], EdgeCnt;
inline void add_edge (Re int u, Re int v, Re int w)
{
	e[++ EdgeCnt].to = v;
	e[EdgeCnt].wei = w;
	e[EdgeCnt].nex = head[u];
	head[u] = EdgeCnt;
}
/****************************************************/

int dp[maxn][101], ans, modn;

inline int mmod (register int x) {return (x % modn + modn) % modn;}

inline void nico_dfs (int x, int fa)
{
	register int to, va; dp[x][0] = 1;
	for (Re int i = head[x]; i; i = e[i].nex)
	{
		to = e[i].to, va = e[i].wei;
		nico_dfs (to, x);
		for (Re int j = 0; j < modn; j ++) ans += (dp[to][j] * dp[x][mmod(-j-va)]) << 1;
		for (Re int j = 0; j < modn; j ++) dp[x][(j + va) % modn] += dp[to][j];
	}
}

int main ()
{
	freopen ("pair.in","r",stdin);
	freopen ("pair.out","w",stdout);
	
	register int n = read(), u, fa, va; modn = read ();
	for (Re int i = 2; i <= n; i ++) fa = read (), va = read (), add_edge (fa, i, va);
	
	nico_dfs (1, 0);
	
	printf ("%d", ans + n);
	
	return 0;
}
