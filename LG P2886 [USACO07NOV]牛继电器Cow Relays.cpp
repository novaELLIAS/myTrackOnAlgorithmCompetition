#pragma GCC optimize ("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2", 3)
#pragma G++ optimize ("Ofast", 3)
#pragma GCC optimize ("Ofast", 3)
#pragma G++ target ("avx","sse2")
#pragma GCC target ("avx","sse2")

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define gc() getchar()
#define rint register int
#define maxn 1001
#define maxm 201

inline int read ()
{
    int x = 0;char c = gc();bool m = 0;
    while (!isdigit(c) && c != '-') c = gc();
    if (c == '-') c = gc(), m = 1;
    while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
    if (m) return -x;
    else return x;
}

int n, m, sta, end, cnt;
int sce[maxn];
int mapp[maxm][maxm], anss[maxm][maxm], temp[maxm][maxm];

inline void nico_INPUT ()
{
	n = read (), m = read (), sta = read (), end = read ();
	register int val, u, v;
	while (m --)
	{
		val = read (), u = read (), v = read ();
		if (!sce[u]) sce[u] = ++ cnt;
		if (!sce[v]) sce[v] = ++ cnt;
		mapp[sce[u]][sce[v]] = mapp[sce[v]][sce[u]] = val;
	}
}

inline void nico_INIT ()
{
	memset (mapp, 0x3f3f3f3f, sizeof mapp);
	memset (temp, 0x3f3f3f3f, sizeof temp);
	memset (anss, 0x3f3f3f3f, sizeof anss);
	for (rint i = 1; i <= 200; i ++) anss[i][i] = 0;
}

inline void nico_floyed (int ans[maxm][maxm], int a[maxm][maxm], int b[maxm][maxm])
{
	for (rint k = 1; k <= cnt; k ++)
	{
		for (rint i = 1; i <= cnt; i ++)
		{
			for (rint j = 1; j <= cnt; j ++)
			{
				if (ans[i][j] > a[i][k] + b[k][j]) ans[i][j] = a[i][k] + b[k][j];
			}
		}
	}
}

inline void nico_memcpy (int to[maxm][maxm], int fr[maxm][maxm])
{
	for (rint i = 1; i <= cnt; i ++)
	{
		for (rint j = 1; j <= cnt; j ++) to[i][j] = fr[i][j], fr[i][j] = 0x3f3f3f3f;
	}
}

inline void nico_WORK ()
{
	while (n)
	{
		if (n & 1)
		{
			nico_floyed (temp, anss, mapp);
			nico_memcpy (anss, temp);
		}
		nico_floyed (temp, mapp, mapp);
		nico_memcpy (mapp, temp);
		n >>= 1;
	}
}

int main ()
{
	nico_INIT ();
	nico_INPUT ();
	nico_WORK ();
	printf ("%d", anss[sce[sta]][sce[end]]);
	return 0;
}
