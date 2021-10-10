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
#define ll long long 
#define rint register int
#define gc() getchar ()
#define lowbit(x) x&(-x)

inline int read () {
	register int x = 0;register char c = gc();register bool m = 0;
	while (!isdigit(c) && c != '-') c = gc();
	if (c == '-') c = gc(), m = 1;
	while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
	if (m) return -x;
	else return x;
}

int n, a;
double ans, tmp;
long long c1[maxn], c2[maxn];

inline void add (int x, int w, ll *c)
{
	while (x) {
		c[x] += w;
		x &= x-1;
	}
}

inline ll query (int x, ll *c)
{
	long long ret = 0;
	while (x<=n) {
		ret += c[x];
		x += lowbit(x);
	}
	return ret;
}

int main ()
{
	n = read();
	for (rint i = 1; i <= n; i ++)
	{
		a = read();
		tmp += query (a+1, c1);
		ans -= (double)query(a+1, c2)*(n-i+1);
		ans += (double)(n-i+1)*i*(i-1)/4.0;
		add (a, 1, c1); add (a, i, c2);
	}
	printf ("%.20lf", (double)(tmp+ans/((double)n*(n+1)/2.0)));
	return 0;
}
