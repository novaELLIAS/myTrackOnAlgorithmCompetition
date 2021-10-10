#pragma GCC optimize ("Ofast")

#include <stdio.h>
#include <ctype.h>
#include <algorithm>

using namespace std;

#define rint register int
#define maxn 5001
#define maxm 200001

inline int read ()
{
	int x = 0; char c = getchar(); bool m = 0;
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') c = getchar(), m = 1;
	while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = getchar();
	if (m) return -x;
	else return x;
}

struct node {
	int u, v, w;
} e[maxm];

int n, m, x, y, val, ans, cnt, fa[maxn];

inline int find (int x)
{
	while (x != fa[x]) x = fa[x] = fa[fa[x]];
	return x;
}

inline bool cmp (node aa, node bb) {return aa.w < bb.w;}

inline void solve ()
{
	for (rint i = 1; i <= m; i ++)
	{
		x = find (e[i].u), y = find (e[i].v);
		if (x == y) continue;
		ans += e[i].w;
		cnt ++;
		fa[x] = y;
		if (cnt == n - 1) break;
	}
}

int main ()
{
	n = read (), m = read ();
	for (rint i = 1; i <= m; i ++) e[i].u = read (), e[i].v = read (), e[i].w = read ();
	for (rint i = 1; i <= n; i ++) fa[i] = i;
	sort (e+1, e+m+1, cmp);
	solve ();
	printf ("%d", ans);
	return 0;
}
