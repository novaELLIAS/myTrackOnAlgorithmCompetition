#pragma GCC optimize ("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2", 3)
#pragma G++ optimize ("Ofast", 3)
#pragma GCC optimize ("Ofast", 3)
#pragma GCC target ("sse3","sse2","sse")
#pragma GCC target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target ("f16c")

#include <stdio.h>
#include <ctype.h>
#include <algorithm>

using namespace std;

class fastio {
//#define gc() getchar ()
	private:
		inline char gc() {
			static char buf[1<<14],*p1=buf,*p2=buf;
			return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
		}
	public:
		inline void read (int &to) {
			register int x = 0;
			register char c = gc();
			while (!isdigit(c)) c = gc();
			while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
			to = x;
		}
} io;

#define maxn 21
#define rint register int

struct node {
	int to, va;
} grap[maxn][maxn];

int mapp[maxn][maxn];
int n, ans = 0x3f3f3f3f, minlexp = 0x3f3f3f3f, minbexp = 0x3f3f3f3f;
bool vis[maxn];
int bakh[maxn];

inline bool cmp (node aa, node bb) {
	return aa.va < bb.va;
}

inline int minn (int aa, int bb) {
	return aa<bb? aa:bb;
}

inline void nico_dfs (int x, int ste, int sum) {
	register int to, va;
	if (ste == n) {
		ans = minn (ans, sum + bakh[x]);
		return;
	}
	if (sum >= ans) return;
	if ((n - ste)* minlexp + sum + minbexp >= ans) return;
	for (rint i = 2; i <= n; i ++) {
		to = grap[x][i].to, va = sum + grap[x][i].va;
		if (!vis[grap[x][i].to]) {
			if ((n - ste-1) * minlexp + va + minbexp >= ans) return;
			vis[grap[x][i].to] = true;
			nico_dfs (grap[x][i].to, ste + 1, va);
			vis[grap[x][i].to] = false;
		}
	}
}

int main () {
	//freopen ("salesman.in","r",stdin);
	//freopen ("salesman.out", "w", stdout);
	io.read(n);
	register int w;
	for (rint i = 1; i <= n; i ++) {
		for (rint j = 1; j <= n; j ++) {
			io.read(w);
			if (i != j) minlexp = minn (minlexp, w);
			mapp[i][j] = w, grap[i][j].to = j, grap[i][j].va = w;
		}
		bakh[i] = mapp[i][1];
		if (i != 1) minbexp = minn (minbexp, bakh[i]);
		sort (grap[i]+1, grap[i]+n+1, cmp);
	}
	bakh[1] = -0x3f3f3f3f;
	vis[1] = true;
	nico_dfs (1, 1, 0);
	printf ("%d\n", ans);
	return 0;
}
