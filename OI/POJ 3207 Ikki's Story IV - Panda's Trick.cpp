#pragma GCC optimize ("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2", 3)
#pragma G++ optimize ("Ofast", 3)
#pragma GCC optimize ("Ofast", 3)
#pragma G++ target ("avx","sse2")
#pragma GCC target ("avx","sse2")

#include <stdio.h>
#include <ctype.h>

#define rint register int

int n, m;

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
			bool m = 0;
			while (!isdigit(c) && c != '-') c = gc();
			if (c == '-') c = gc(), m = 1;
			while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
			if (m) to = -x;
			else to = x;
		}
} io;

class niconi {
#define maxn 1001
#define dman 2002
#define maxm 500
	private:
		int fa[dman];
		struct node {
			int sta, end;
		} e[maxm];
		inline int find (int x) {
			while (fa[x] != x) x = fa[x] = fa[fa[x]];
			return x;
		}
		inline bool check (int s1, int e1, int s2, int e2) {
			return (s2>s1 && s2<e1 && e2>e1) || (e2>s1 && e2<e1 && s2<s1);
		}
#undef maxn
#undef maxn
#undef maxm
	public:

		inline void init () {
			io.read(n), io.read(m), m --;
			for (rint i = 1; i <= n; i ++) fa[i] = i;
			for (rint i = 0; i <= m; i ++) io.read(e[i].sta), io.read(e[i].end);
		}
		inline void work () {
			for (rint i = 0; i < m; i ++) {
				for (rint j = i+1; j <= m; j ++) {
					if (check(e[i].sta, e[i].end, e[j].sta, e[j].end)) {
						fa[find(i<<1)] = find(j<<1|1);
						fa[find(j<<1)] = find(i<<1|1);
					}
				}
			}
		}
		inline void prin () {
			bool flag = false;
			for (rint i = 0; i <= m; i ++) {
				if (find(i<<1) == find(i<<1|1)) {
					flag = true;
					break;
				}
			}
			if (flag) printf ("the evil panda is lying again");
			else printf("panda is telling the truth...\n");
		}

} kiana;

int main () {
	kiana.init ();
	kiana.work ();
	kiana.prin ();
	return 0;
}
