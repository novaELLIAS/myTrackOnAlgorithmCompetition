// c tmd star
// FA Q
#pragma GCC optimize ("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2", 3)
#pragma G++ optimize ("Ofast", 3)
#pragma GCC optimize ("Ofast", 3)
#pragma G++ target ("avx","sse2")
#pragma GCC target ("avx","sse2")

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <queue>

using namespace std;

class fastio {
		//#define gc() getchar()
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
#define maxn 10010
	private:
		int S, T, n, m, u, v, w, now ,sum, cnt;
		int lev[maxn], fir [maxn], cur[maxn];
		struct edge {
			int next, to, w;
		} e[200010];
		queue <int> que;

		inline void addedge (int u,int v,int dis) {
			e[++cnt].to=v,e[cnt].next=fir[u],e[cnt].w=dis,fir[u]=cnt;
			e[++cnt].to=u,e[cnt].next=fir[v],e[cnt].w=0,fir[v]=cnt;
		}
		inline int minn (int aa, int bb) {
			return aa<bb? aa:bb;
		}
		bool flood_bfs () {
			while (!que.empty()) que.pop ();
			memset (lev, 0, sizeof lev);
			que.push(S);
			lev[S] = 1;
			int to;
			while (!que.empty()) {
				u = que.front(), que.pop();
				for (rint i = fir[u]; i; i = e[i].next) {
					to = e[i].to;
					if (!lev[to] && e[i].w) {
						que.push(to);
						lev[to]=lev[u]+1;
					}
				}
			}
			return lev[T];
		}
		int flood_dfs (int x, int QwQ) {
			if (x == T) return QwQ;
			int tem = QwQ, nexlev = lev[x] + 1, t = 0x3f3f3f3f, to;
			for (rint &i = cur[x]; i && tem; i = e[i].next) {
				if (lev[e[i].to] == nexlev && e[i].w) {
					t = flood_dfs (e[i].to, minn (tem, e[i].w));
					e[i].w -= t, e[i^1].w += t, tem -= t;
				}
			}
			return QwQ - tem;
		}
#undef maxn
	public:
#define inff 0x3f3f3f3f
		inline void niconiconi () {
			cnt=1;
			io.read(n), io.read(m), io.read(S), io.read(T);
			while (m --) {
				io.read(u), io.read(v), io.read(w);
				addedge(u, v, w);
			}
			while (flood_bfs ()) {
				for (rint i=1;i<=n;++i) cur[i] = fir[i];
				while (now = flood_dfs (S, inff)) sum += now;
			}
			printf ("%d", sum);
		}
#undef inff
#undef rint
} ellias;

int main () {
	//freopen ("nico.in","r",stdin);
	ellias.niconiconi ();
	return 0;
}
