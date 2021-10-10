#pragma GCC optimize ("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2", 3)
#pragma G++ optimize ("Ofast", 3)
#pragma GCC optimize ("Ofast", 3)
#pragma GCC target ("sse3","sse2","sse")
#pragma GCC target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target ("f16c")
#pragma G++ target ("sse3","sse2","sse")
#pragma G++ target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma G++ target ("f16c")

#include <stdio.h>
#include <ctype.h>

#define maxn 100001
#define dmax 400001
#define ll long long 
#define rint register int
#define gc() getchar ()

inline int read () {
	int x = 0;char c = gc();bool m = 0;
	while (!isdigit(c) && c != '-') c = gc();
	if (c == '-') c = gc(), m = 1;
	while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
	if (m) return -x;
	else return x;
}

int n, dat[maxn];
double ans;

int main ()
{
	n = read();
	for (rint i = 1; i <= n; i ++)
	{
		dat[i] = read();
		ans += (double) (i * (n-i) * (n-i+1)) / (2*n*(n+1));
	}
	for (rint i = 1; i <= n; i ++) {
		for (rint j = i+1; j <= n; j ++) {
			if (dat[i] > dat[j]) ans += (double) ((j-1)*j + (n-i)*(n-i+1) - (j-i-1)*(j-i))/(n*(n+1));
		}
	}
	printf ("%.12lf", ans);
	return 0;
}
