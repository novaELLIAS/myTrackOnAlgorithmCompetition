#pragma GCC optimize ("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2", 3)
#pragma G++ optimize ("Ofast", 3)
#pragma GCC optimize ("Ofast", 3)
#pragma G++ target ("avx","sse2")
#pragma GCC target ("avx","sse2")

#include <stdio.h>
#include <ctype.h>

#define gc() getchar()
#define rint register int
#define maxn 51

inline int read () {
    int x = 0;char c = gc();bool m = 0;
    while (!isdigit(c) && c != '-') c = gc();
    if (c == '-') c = gc(), m = 1;
    while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
    if (m) return -x;
    else return x;
}

int n, m, x, y, w;
int mapp[maxn][maxn], dp[maxn][maxn][maxn][maxn];

inline int maxx (int a, int b) {return a>b? a:b;}

int main ()
{
	n = read (), m = read ();
	for (rint i = 1; i <= n; i ++)
	{
		for (rint j = 1; j <= m; j ++) mapp[i][j] = read ();
	}
	
	for (rint i = 1; i <= n; i ++)
		for (rint j = 1; j <= m; j ++)
			for (rint p = 1; p <= n; p ++)
				for (rint q = 1; q <= m; q ++)
				{
					dp[i][j][p][q] = maxx( maxx (dp[i-1][j][p-1][q], dp[i-1][j][p][q-1]), maxx (dp[i][j-1][p-1][q], dp[i][j-1][p][q-1])) + mapp[i][j] + mapp[p][q];
					if (i == p && j == q) dp[i][j][p][q] -= mapp[i][j];
				}
	
	printf ("%d", dp[n][m][n][m]);
	return 0;
}
