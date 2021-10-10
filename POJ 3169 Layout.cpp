#pragma GCC optimize ("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2", 3)
#pragma G++ optimize ("Ofast", 3)
#pragma GCC optimize ("Ofast", 3)
#pragma G++ target ("avx","sse2")
#pragma GCC target ("avx","sse2")

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

#define gc() getchar()
#define rint register int
#define maxn 1001
#define maxe 10001
#define maxx 1000001

inline int read ()
{
    int x = 0;char c = gc();bool m = 0;
    while (!isdigit(c) && c != '-') c = gc();
    if (c == '-') c = gc(), m = 1;
    while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
    if (m) return -x;
    else return x;
}

int n, ml, md, dis[maxn], deg[maxn];
bool vis[maxn];
vector <pair <int, int> > e[maxn];
queue <int> que;

inline void nico_spfa ()
{
	memset (dis, 0x3f3f3f3f, sizeof dis);
	dis[1] = 0;
	que.push (1);
	int fro, to, val;
	bool flag = false;
	while (!que.empty ())
	{
		fro = que.front(), que.pop ();
		deg[fro] ++;
		if (deg[fro] > n)
		{
			flag = true;
			break;
		}
		vis[fro] = false;
		for (rint i = e[fro].size()-1; i >= 0; i --)
		{
			to = e[fro][i].first, val = e[fro][i].second;
			if (dis[to] > dis[fro] + val)
			{
				dis[to] = dis[fro] + val;
				if (!vis[to])
				{
					vis[to] = true;
					que.push(to);
				}
			}
		}
	}
	if (flag) puts ("-1");
	else if (dis[n] == 0x3f3f3f3f) puts ("-2");
	else printf ("%d", dis[n]);
}

int main ()
{
	n = read (), ml = read (), md = read ();
	register int x, y, z;
	for (rint i = 1; i <= ml; i ++)
	{
		x = read (), y = read (), z = read ();
		e[x].push_back (make_pair (y, z));
	}
	for (rint i = 1; i <= md; i ++)
	{
		y = read (), x = read (), z = read ();
		e[x].push_back (make_pair (y, -z));
	}
	nico_spfa ();
	return 0;
}
