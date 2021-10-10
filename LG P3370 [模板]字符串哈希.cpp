#pragma GCC optimize ("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2", 3)
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx","sse2")

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define rint register int
#define xxxx 131
#define maxn 10001
#define ll long long
#define ull unsigned long long

int n, ans;
char s[maxn];
ull a[maxn], len, now;

int main ()
{
	scanf ("%d", &n);
	for (rint i = 1; i <= n; i ++)
	{
		now = 1ll;
		scanf ("%s", s);
		len = strlen (s);
		for (rint j = 0; j < len; j ++) now = now * xxxx + (ull) s[j];
		a[i] = now;
	}
	sort (a+1, a+n+1);
	for (rint i = 2; i <= n; i ++) if (a[i] != a[i-1]) ans ++;
	printf ("%d", ans + 1);
	return 0;
}
