#pragma GCC optimize ("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2", 3)
#pragma G++ optimize ("Ofast", 3)
#pragma GCC optimize ("Ofast", 3)
#pragma G++ target ("avx","sse2")
#pragma GCC target ("avx","sse2")

#include <stdio.h>
#include <ctype.h>
#define rint register int

class fastio {
//#define gc() getchar ()
	private:
		inline char gc() {
			static char buf[1<<14],*p1=buf,*p2=buf;
			return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
		}
	public:
		inline void read (int &to) {
			int x = 0;
			char c = gc();
			while (!isdigit(c)) c = gc();
			while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
			to = x;
		}
} io;

inline int maxx (int aa, int bb) {
	return aa>bb? aa:bb;
}

int n, r, x, y, w, ans = -1, to;
int dp[5001][5001];

int main () {
	io.read(n), io.read(r);
	for (rint i = 1; i <= n; i ++) {
		io.read(x), io.read(y), io.read(w);
		dp[x+1][y+1] = w;
	}
	for (rint i = 1; i <= 5000; i ++) {
		for (rint j = 1; j <= 5000; j ++) {
			dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
		}
	}
	to = 5000-r;
	for (rint i = 0; i <= to; i ++) {
		for (rint j = 0; j <= to; j ++)
		{
			ans = maxx (ans, dp[i+r][j+r] - dp[i+r][j] - dp[i][j+r] + dp[i][j]);
		}
	}
	printf ("%d", ans);
	return 0;
}
