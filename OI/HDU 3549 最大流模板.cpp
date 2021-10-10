#pragma GCC optimize ("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2", 3)
#pragma G++ optimize ("Ofast", 3)
#pragma GCC optimize ("Ofast", 3)
#pragma G++ target ("avx","sse2")
#pragma GCC target ("avx","sse2")

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

class fastio {
	private:
		inline char gc() {
			static char buf[1<<14],*p1=buf,*p2=buf;
			return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
		}
	public:
		inline void read (int &to) {
			int x = 0;
			char c = gc();
			bool m = 0;
			while (!isdigit(c) && c != '-') c = gc();
			if (c == '-') c = gc(), m = 1;
			while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
			if (m) to = -x;
			else to = x;
		}
} io;

class NetworkFlood {
#define rint register int
#define maxn 16
	private:
		int T, n, m, u, v, w, now ,sum;
		int lev[maxn];
		struct edge {
			int c, f;
		} e[maxn][maxn];
		queue <int> que;

		inline int minn (int aa, int bb) {
			return aa<bb? aa:bb;
		}
		inline void flood_init () {
			memset (e, 0, sizeof e);
			sum = now = 0;
		}
		inline int flood_bfs () {
			while (!que.empty()) que.pop ();
			memset (lev, 0, sizeof lev);
			que.push(1);
			lev[1] = 1;
			while (!que.empty()) {
				u = que.front(), que.pop();
				for (rint i = 1; i <= n; i ++) {
					if (!lev[i] && e[u][i].c > e[u][i].f) {
						lev[i] = lev[u] + 1;
						que.push(i);
					}
				}
			}
			return lev[n];
		}
		inline int flood_dfs (int x, int QwQ) {
			if (x == n) return QwQ;
			int tem = QwQ, nexlev = lev[x] + 1, t = 0x3f3f3f3f;
			for (rint i = 1; i <= n && tem; i ++) {
				if (lev[i] != nexlev || e[x][i].c < e[x][i].f) continue;
				t = flood_dfs (i, minn (tem, e[x][i].c - e[x][i].f));
				e[x][i].f += t, e[i][x].f -= t;
				tem -= t;
			}
			return QwQ - tem;
		}
#undef maxn
	public:
#define inff 0x3f3f3f3f
		inline void niconiconi () {
			io.read(T);
			for (rint ca = 1; ca <= T; ca ++) {
				flood_init ();
				io.read(n), io.read(m);
				while (m --) {
					io.read(u), io.read(v), io.read(w);
					e[u][v].c += w;
				}
				while (flood_bfs ()) {
					while (now = flood_dfs (1, inff)) sum += now;
				}
				printf ("Case %d: %d\n", ca, sum);
			}
		}
#undef inff
#undef rint
} ellias;

int main () {
	ellias.niconiconi ();
	return 0;
}
