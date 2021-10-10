#pragma GCC optimize ("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2", 3)
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx","sse2")

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

class fastio {
	private:
		inline char gc() {
			static char buf[1<<14],*p1=buf,*p2=buf;
			return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
		}
	public:
		inline void getuint (int &to) {
			int x = 0;
			char c = gc();
			while (!isdigit(c)) c = gc();
			while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
			to = x;
		}
		inline void getudou (double &to) {
			double x=0;
			char ch = gc ();
			while (!isdigit(ch)) ch = gc ();
			while (isdigit(ch)) x = x * 10 + (ch-48), ch = gc ();
			if (ch == '.') {
				double s = 0.1;
				ch = gc ();
				while (isdigit(ch)) x = x + (ch-48)*s,s/=10,ch = gc ();
			}
			to = x;
		}
} io;

class niconi {
#define maxn 1000
#define eps 1e-10
#define rint register int
	private:
		int n, k;
		double a[maxn], b[maxn], t[maxn], sum;
		inline bool check (double x) {
			for (rint i = 0; i < n; i ++) t[i] = a[i] - (x*b[i]);
			sort (t, t+n);
			sum = 0.0;
			for (rint i = k; i < n; i ++) sum += t[i];
			if (sum > 0) return true;
			else return false;
		}
#undef maxn
	public:
		inline void work () {
			io.getuint(n), io.getuint(k);
			if ((!n) && (!k)) exit (0);
			for (rint i = 0; i < n; i ++) io.getudou(a[i]);
			for (rint i = 0; i < n; i ++) io.getudou(b[i]);
			double l = 0.0, r = 1.0, mid;
			while (r > l + eps) {
				mid = (l + r) / 2;
				if (check(mid)) l = mid;
				else r = mid;
			}
			printf ("%.0lf\n", l*100);
		}
#undef rint
#undef maxn
#undef eps
} kiana;

int main () {
	while (true) kiana.work ();
	return 0;
}
