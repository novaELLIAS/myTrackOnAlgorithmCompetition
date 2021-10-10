#pragma GCC optimize ("Ofast")

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <algorithm>

using namespace std;

#define maxn 51
#define maxe 1260
#define rint register int
#define gc() getchar ()

inline int read ()
{
    int x = 0; char c = gc(); bool m = 0;
    while (!isdigit(c) && c != '-') c = gc();
    if (c == '-') c = gc(), m = 1;
    while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
    if (m) return -x;
    else return x;
}

struct node {
	int u, v, w;
} e[maxe];

struct point {
	int x, y;
} pt[maxn];
int n, fa[maxn], cnt, val, cntt, x, y;

inline bool cmp (node aa, node bb) {return aa.w < bb.w;}
inline int minn (int aa, int bb) {return aa<bb? aa:bb;}
inline int find (int x)
{
	while (x != fa[x]) x = fa[x] = fa[fa[x]];
	return x;
}

int main ()
{
	n = read ();
	for (rint i = 1; i <= n; i ++) fa[i] = i, pt[i].x = read (), pt[i].y = read ();
	for (rint i = 1; i < n; i ++)
	{
		for (rint j = i+1; j <= n; j ++)
		{
			e[++ cnt].u = i, e[cnt].v = j, val = abs (pt[i].y - pt[j].y) + abs (pt[i].x - pt[j].x);
			if (val&1) e[cnt].w = (val>>1) + 1;
			else e[cnt].w = val >> 1;
		}
	}
	
	sort (e+1, e+cnt+1, cmp);
	
	register int i = 1;
	for (; i <= cnt; i ++)
	{
		x = find (e[i].u), y = find (e[i].v);
		if (x == y) continue;
		fa[x] = y;
		cntt ++;
		if (cntt == n - 1) break;
	}
	
	printf ("%d", e[i].w);
	
	return 0;
}
