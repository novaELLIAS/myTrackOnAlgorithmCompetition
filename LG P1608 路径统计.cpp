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
#include <ext/pb_ds/priority_queue.hpp>

using namespace std;
using namespace __gnu_pbds;

#define maxn 2001
#define rint register int

inline char gc() {
    static char buf[1<<14],*p1=buf,*p2=buf;
    return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
}

inline int read () {
	rint x = 0; register char c = gc();
	while (!isdigit(c)) c = gc();
	while (isdigit(c)) x = x * 10 + c - 48, c = gc();
	return x;
}

struct node {
	int val, name;
};

struct cmp {
	inline bool operator() (const node& aa, const node& bb) {
		return aa.val > bb.val;
	}
};

inline int minn (const int aa, const int bb) {return aa<bb? aa:bb;}

int n, m, fro, to, w;
int gra[maxn][maxn], dis[maxn], cnt[maxn];
bool vis[maxn];
vector <int> e[maxn];
__gnu_pbds::priority_queue <node, cmp, pairing_heap_tag> nico;

int main () {
	n = read (), m = read ();

    fill (dis+1, dis+n+1, 0x3f3f3f3f);
    fill (gra[0], gra[0] + maxn*maxn, 0x3f3f3f3f);

	for (rint i = 1; i <= m; i ++)
	{
		fro = read (), to = read (), w = read ();
        if (gra[fro][to] != 0x3f3f3f3f) gra[fro][to] = minn (gra[fro][to], w);
        else {e[fro].push_back (to); gra[fro][to] = w;}
	}

	dis[1] = 0, cnt[1] = 1;
	nico.push ((node) {0, 1});

	while (!nico.empty ()) {
		fro = nico.top ().name;
		nico.pop ();
        if (vis[fro]) continue;
        vis[fro] = true;
		for (rint i = e[fro].size()-1; i >= 0; i --) {
			to = e[fro][i], w = gra[fro][to];
			if (dis[fro] + w < dis[to]) {
				dis[to] = dis[fro] + w;
                cnt[to] = cnt[fro];
				if (!vis[to]) nico.push ((node) {dis[to], to});
			} else if (dis[fro] + w == dis[to]) cnt[to] += cnt[fro];
		}
	}

    if (cnt[n]) printf ("%d %d\n", dis[n], cnt[n]);
    else puts ("No answer");

	return 0;
}
