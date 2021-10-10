#pragma GCC optimize ("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2", 3)
#pragma G++ optimize ("Ofast", 3)
#pragma GCC optimize ("Ofast", 3)
#pragma G++ target ("avx","sse2")
#pragma GCC target ("avx","sse2")

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <vector>

using namespace std;

#define gc() getchar()
#define rint register int
#define maxn 500001

inline int read ()
{
    int x = 0;char c = gc();bool m = 0;
    while (!isdigit(c) && c != '-') c = gc();
    if (c == '-') c = gc(), m = 1;
    while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
    if (m) return -x;
    else return x;
}

int n, m, x, y, z, maxx, t, l1, l2, l3, delta, ans;
int fa[maxn][20], dep[maxn];
vector <int> e[maxn];

inline void nico_dfs (int x)
{
	dep[x] = dep[fa[x][0]] + 1;
	for (rint i = 1; i <= maxx; i ++) fa[x][i] = fa[fa[x][i-1]][i-1];
	for (rint i = e[x].size()-1; i >= 0; i --)
	{
		if (e[x][i] != fa[x][0])
		{
			fa[e[x][i]][0] = x;
			nico_dfs (e[x][i]);
		}
	}
}

inline int nico_lca (int x, int y)
{
	if (dep[y] > dep[x]) t = x, x = y, y = t;
	delta = dep[x] - dep[y];
	for (rint i = maxx; i >= 0; i --) if (delta & (1 << i)) x = fa[x][i];
	if (x == y) return y;
	for (rint i = maxx; i >= 0; i --)
	{
		if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	}
	return fa[x][0];
}

int main ()
{
	n = read (), m = read ();
	maxx = ceil (log2 (n));
	for (rint i = 1; i < n; i ++)
	{
		x = read (), y = read ();
		e[x].push_back (y), e[y].push_back (x);
	}
	nico_dfs (1);
	while (m --)
	{
		x = read (), y = read (), z = read ();
		l1 = nico_lca (x, y);
		l2 = nico_lca (x, z);
		l3 = nico_lca (y, z);
		if (l1 == l2) ans = l3;
		else if (l2 == l3) ans = l1;
		else if (l1 == l3) ans = l2;
		printf ("%d %d\n", ans, dep[x] + dep[y] + dep[z] - dep[l1] - dep[l2] - dep[l3]);
	}
}
