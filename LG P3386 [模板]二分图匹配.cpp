#pragma G++ optimize ("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2", on)
#pragma G++ optimize ("Ofast", on)
#pragma GCC optimize ("Ofast", 3)
#pragma G++ target ("avx","sse2", on)
#pragma GCC target ("avx","sse2")

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <vector>

using namespace std;

//#define gc() getchar()
#define rint register int
#define maxn 1001

inline char gc()
{
    static char buf[1<<14],*p1=buf,*p2=buf;
    return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
}

inline int read ()
{
    int x = 0;char c = gc();bool m = 0;
    while (!isdigit(c) && c != '-') c = gc();
    if (c == '-') c = gc(), m = 1;
    while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
    if (m) return -x;
    else return x;
}

int n, m, t, u, v, ans;
vector <int> e[maxn];
bool vis[maxn];
int mat[maxn];

inline bool hungry (int x)
{
	int to;
	for (rint i = e[x].size()-1; i >= 0; i --)
	{
		to = e[x][i];
		if (vis[to]) continue;
		vis[to] = true;
		if (!mat[to] || hungry(mat[to]))
		{
			mat[to] = x;
			return true;
		}
	}
	return false;
}

int main ()
{
	n = read (), m = read (), t = read ();
	while (t --)
	{
		u = read (), v = read ();
		if (v > m) continue;
		e[u].push_back(v);
	}
	for (rint i = 1; i <= n; i ++)
	{
		memset (vis, 0, sizeof vis);
		if (hungry(i)) ans ++;
	}
	printf ("%d", ans);
	return 0;
}
