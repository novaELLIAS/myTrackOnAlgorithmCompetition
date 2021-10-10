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
#include <vector>
#include <string.h>

#define rint register int
#define ll long long
#define maxn 500001

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

inline ll maxx (ll aa, ll bb) {return aa>bb? aa:bb;}

int n, s, a, b, t;
ll ans, fl[maxn];
vector <pair <int, int> > e[maxn];
bool vis[maxn];

inline void floor_dfs (int x)
{
    vis[x] = true;
    int to, val;
    for (rint i = e[x].size()-1; i >= 0; i --)
    {
        to = e[x][i].first, val = e[x][i].second;
        if (vis[to]) continue;
        floor_dfs (to);
        fl[x] = maxx (fl[x], fl[to] + val);
    }
}

inline void getans_dfs (int x)
{
    vis[x] = true;
    int to, val;
    for (rint i = e[x].size()-1; i >= 0; i --)
    {
        to = e[x][i].first, val = e[x][i].second;
        if (vis[to]) continue;
        getans_dfs (to);
        ans += fl[x] - fl[to] - val;
    }
}

inline void nico_dfs (int x)
{
    vis[x] = true;
    int cnt = 0, to, val;
    for (rint i = e[x].size()-1; i >= 0; i --)
    {
        to = e[x][i].first, val = e[x][i].second;
        if (vis[to]) continue;
        nico_dfs (to);
        if (fl[to] + val > fl[x]) ans += (fl[to] + val - fl[x]) * cnt, fl[x] = val + fl[to];
        else ans += fl[x] - fl[to] - val;
        cnt ++;
    }
}

int main ()
{
    io.read(n), io.read(s);
    for (rint i = 1; i < n; i ++)
    {
        io.read(a), io.read(b), io.read(t);
        e[a].push_back (make_pair (b, t)), e[b].push_back(make_pair(a, t));
    }
    /*
    floor_dfs (s);
    fill (vis+1, vis+n+1, 0);
    getans_dfs (s);*/
    nico_dfs (s);
    printf ("%lld\n", ans);
    return 0;
}
