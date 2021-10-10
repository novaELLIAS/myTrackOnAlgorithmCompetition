#pragma GCC optimzie ("Ofast")

#include "stdio.h"
#include "iostream"

#define rint register int

using namespace std;

inline int read()
{
    int x=0ll,t=1ll;
    char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
    if(ch=='-')t=-1,ch=getchar();
    while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
    return x*t;
}

struct edge {
	int v, w, next;
} e[202];
int head[220];

struct node {
	int l, r;
	int lc, rc;
	bool fa;
} a[101];

bool check [101];
int n, q, tot;
int dp[101][101];

inline void add (int u, int v, int w)
{
	e[++ tot] = (edge) { v, w, head[u] }, head[u] = tot;
}

inline void buildt (int k)
{
	check[k] = true;
	for (rint i = head[k]; i; i = e[i].next)
	{
		if (!check[e[i].v])
		{
			a[k].fa = true;
			if(!a[k].l) a[k].l = e[i].v, a[k].lc = e[i].w;
			else a[k].r = e[i].v, a[k].rc = e[i].w;
			buildt (e[i].v);
		}
	}
}

inline int dfs (int u, int cnt)
{
	if (cnt == 0) return 0;
	if (!a[u].fa) return 0;
	if (dp[u][cnt]) return dp[u][cnt];
	dp[u][cnt] =max (dfs (a[u].l, cnt-1) + a[u].lc, dfs (a[u].r, cnt-1) + a[u].rc);
	for (rint i = 0; i < cnt-1; i ++)
	{
		dp[u][cnt] = max (dp[u][cnt], dfs (a[u].l, i) + a[u].lc + dfs (a[u].r, cnt-2-i) + a[u].rc);
	}
	return dp[u][cnt];
}

int main ()
{
	n = read (), q = read ();
	int u, v, w;
	for (rint i = 1; i < n; i ++)
	{
		u = read (), v = read (), w = read ();
		add (u, v, w); add (v, u, w);
	}
	buildt (1);
	printf ("%d", dfs (1, q));
}
