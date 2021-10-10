#pragma GCC optimize ("Ofast")

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <vector>

using namespace std;

inline int read () {
	int x = 0; char c = getchar(); bool m = 0;
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') c = getchar(), m = 1;
	while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = getchar();
	if (m) return -x;
	else return x;
}

#define rint register int
#define maxn 300001

struct node1 {
	int sum, ans;
}vis[maxn];

int n, m, u, v, w;
int sta[maxn], end[maxn];
pair <int, int> fa[maxn];
vector <pair <int, int> > e[maxn];
vector <int> floor[maxn];

inline void build_tree (int pre, int p, int deep,int val)
{
	fa[p] = make_pair (pre, val);
	floor[deep].push_back (p);
	for (rint i = e[p].size () - 1; i >= 0; i --)
	{
		if (e[p][i].first != pre) build_tree (p, e[p][i].first, deep+1, e[p][i].second);
	}
}

inline void solve1 ()
{
	if (sta[1] == end[1])
	{
		printf ("0");
		exit (0);
	}
	bool fla = true;
	int ans = 0, sum = 0, summ = 0;
	build_tree (0, 1, 0, 0);
	for (rint i = sta[1]; i; i = fa[i].first)
	{
		if (i == end[1])
		{
			fla = false;
			break;
		}
		vis[i].sum = sum;
		vis[i].ans = ans;
		sum += fa[i].second;
		ans = max (ans, fa[i].second);
	}
	int ans1 =  0;
	if (fla)
	{
		for (rint i = end[1]; i; i = fa[i].first)
		{
			if (vis[i].sum)
			{
				summ += vis[i].sum;
				ans1 = max (vis[i].ans, ans1);
				printf ("%d", summ - ans1);
				exit (0);
			}
			ans1 = max (ans1, fa[i].second);
			summ += fa[i].second;
		}
	}
	printf ("%d", sum + summ - max (ans, ans1));
	exit (0);
}

inline void solve ()
{
	if (m == 1) solve1 ();
	else printf ("FA Q");
}

int main ()
{
	freopen ("transport.in","r",stdin);
	freopen ("transport.out","w",stdout);
	
	n = read (), m = read ();
	for (rint i = 1; i < n; i ++)
	{
		u = read (), v = read (), w = read ();
		e[u].push_back (make_pair (v, w)), e[v].push_back (make_pair (u, w));
	}
	for (rint i = 1; i <= m; i ++) sta[i] = read (), end[i] = read ();
	
	solve ();
	
	return 0;
}
