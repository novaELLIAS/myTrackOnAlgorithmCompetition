#pragma GCC optimize ("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2", 3)
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx","sse2")

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

#define rint register int
#define xxxx 131
#define maxl 201
#define maxn 30001
#define ll long long
#define ull unsigned long long

int n, cnt, len;
string opt, s;
ull now, a[maxn];

inline void hash () {
	now = 1ll, len = s.size ();
	for (rint j = 0; j < len; j ++) now = now * xxxx + (ull) s[j];
}



int main () {
	ios::sync_with_stdio (false);
	cin >> n;
	while (n --) {
		cin >> opt;
		gets (s);
		hash (s);
		if (opt[1] == 'a') a[++ cnt] = now;
		else find (hash);
	}

	return 0;
}
