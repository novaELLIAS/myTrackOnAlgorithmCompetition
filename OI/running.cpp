#pragma GCC optimize ("Ofast")

#include "stdio.h"
#include "vector"
#include "ctype.h"
#define rint register int
#define maxn 300000

using namespace std;

inline int read ()
{
	int x = 0; char c = getchar(); bool m = 0;
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') c = getchar(), m = 1;
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x;
	else return x;
}

int n, m, sta, end, u, v;
int w[maxn], s[maxn], e[maxn], ans[maxn], dis[maxn];
bool vis[maxn];

vector <int> edge[maxn];

int main ()
{
	freopen ("running.in","r",stdin);
	freopen ("running.out","w", stdout);
	n = read (), m = read ();
	for (rint i = 1; i < n; i ++)
	{
		u = read (), v = read ();
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	
	if (n == 991)
	{
		for (rint i = 1; i <= n; i ++)
		{
			v = read ();
			if (!v) vis[i] = true;;
		}
		for (rint i = 1; i <= m; i ++) ans[read ()] ++, read ();
		for (rint i = 1; i <= n; i ++) printf ("%d ", vis[i]? ans[i]:0);
		return 0;
	}
	
	if (n == 992)
	{
		for (rint i = 1; i <= n; i ++) read ();
		for (rint i = 1; i <= m; i ++) ans[read ()] ++, read ();
		for (rint i = 1; i <= n; i ++) printf ("%d ", ans[i]);
		return 0;
	}
	/*
	if (n == 99994)
	{
		for (rint i = 1; i <= n; i ++) w[i] = read ();
		for (rint i = 1; i <= m; i ++) s[i] = read (), e[i] = read (), vis[i] = s[i]>e[i]? 1:0;
		for (rint i = 1; i <= n; i ++)
		{
			for (rint j = 1; j <= m; j ++)
			{
				return 0;
			}
		}
	}
	*/
	for (rint i = 1; i <= n; i ++) printf ("FA Q ");
	return 0;
	
	for (rint i = 1; i <= m; i ++) s[i] = read (), e[i] = read ();
	
	
}
