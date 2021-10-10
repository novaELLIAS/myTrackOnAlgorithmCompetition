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

inline char gc() {
	static char buf[1<<14],*p1=buf,*p2=buf;
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
}
inline int read () {
	register int x = 0;
	register char c = gc();
	while (!isdigit(c)) c = gc();
	while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
	return x;
}
inline void write (int x) {
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}

#define rint register int
#define LoveLive long long
#define maxn 100001
#define maxa 1000001

int cnt[maxa], ans[maxa], manx = -1, nam[maxn], n;
bool vis[maxa];

inline int maxx (int aa, int bb) {
	return aa>bb? aa:bb;
}

int main () {
	//freopen ("nico.in","r",stdin);
	//freopen ("nico.out","w",stdout);
	n = read();
	for (rint i = 1; i <= n; i ++) {
		nam[i] = read(), cnt[nam[i]] ++, manx  = maxx (manx, nam[i]);
	}
	if (n <= manx) {
		for (rint i = 1; i <= n; i ++) {
			if (!vis[nam[i]]) {
				for (rint j = nam[i]; j <= manx; j += nam[i]) ans[j] += cnt[nam[i]];
				vis[nam[i]] = true;
			}
		}
	} else {
		for (rint i = 1; i <= n; i ++) {
			if (cnt[i]) {
				for (rint j = i; j <= manx; j += i) ans[j] += cnt[i];
			}
		}
	}
	for (rint i = 1; i <= n; i ++) {
		write (ans[nam[i]] - 1);
		putchar('\n');
	}
	return 0;
}
