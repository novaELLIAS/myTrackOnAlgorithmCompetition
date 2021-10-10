#pragma GCC optimize ("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2", 3)
#pragma G++ optimize ("Ofast", 3)
#pragma GCC optimize ("Ofast", 3)
#pragma G++ target ("avx","sse2")
#pragma GCC target ("avx","sse2")

#include <stdio.h>
#include <ctype.h>
#include <ext/pb_ds/priority_queue.hpp>

using namespace std;
using namespace __gnu_pbds;

#define maxn 100001
#define maxm 200001
#define inff 2147483647


inline int read () {
    int x = 0; char c = getchar(); bool m = false;
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') c = getchar(), m = true;
    while (isdigit(c)) x = x * 10 + c - 48, c = getchar();
    if (m) return -x;
    else return x;
}

inline void fastwrite (int x) {
    if(x < 0) x = -x, putchar('-');
    if(x > 9) fastwrite(x / 10);
    putchar(x%10 + '0');
}
inline void fastwritespace (int x) {
    fastwrite(x);
    putchar(' ');
}

struct node {
    int val, name;
};

struct cmp {
    inline bool operator() (const node& aa, const node& bb) {
        return aa.val > bb.val;
    }
};


int n, m, s, fro, to, w;
int dis[maxn];
bool visit[maxn];
vector <pair <int, int> > data[maxn];
__gnu_pbds::priority_queue <node, cmp, pairing_heap_tag> nico;

int main () {
    n = read (), m = read (), s = read ();

    for (int i = 1; i <= m; i ++)
    {
        fro = read (), to = read (), w = read ();
        data[fro].push_back (make_pair (to, w));
    }

    for (int i = 1; i <= n; i ++) dis[i] = inff;
    dis[s] = 0;
    nico.push ((node) {
        0, s
    });
    
    while (!nico.empty ()) {
        fro = nico.top ().name;
        nico.pop ();
        if (visit[fro]) continue;
        visit[fro] = true;
        for (int i = 0; i < data[fro].size (); i ++) {
            to = data[fro][i].first;
            w = data[fro][i].second;
            if (!visit[to] && dis[fro] + w < dis[to]) {
                dis[to] = dis[fro] + w;
                nico.push ((node) {
                    dis[to], to
                });
            }
        }
    }

    for (int i = 1; i <= n; i ++) fastwritespace (dis[i]);

    return 0;
}
