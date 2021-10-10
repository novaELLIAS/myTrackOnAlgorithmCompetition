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
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

inline char gc() {
	static char buf[1<<14],*p1=buf,*p2=buf;
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
}
//#define gc() getchar()
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
#define maxn 1000001
#define maxk 61

struct node { int name, pos;};
vector <node> data;
queue <node> nico;
int n, k, ans = 0x3f3f3f3f;
int bol[maxk];

inline bool cmp (node aa, node bb) {return aa.pos < bb.pos;}

int main ()
{
    n = read(), k = read();
    register int a;
    register node in;
    for (rint i = 1; i <= k; i ++)
    {
        a = read ();
        while (a --)
        {
            in.pos = read (), in.name = i;
            data.push_back (in);
        }
    }
    sort (data.begin(), data.end(), cmp);
    register int cnt = 0, delta;
    register node star, endn;
    for (rint i = 0; i < n; i ++)
    {
        nico.push (data[i]);
        bol[data[i].name] ++;
        if (bol[data[i].name] == 1) cnt ++;
        while (cnt == k)
        {
            star = nico.front ();
            endn = nico.back ();
            nico.pop ();
            delta = endn.pos - star.pos;
            ans = delta<ans? delta:ans;
            bol[star.name] --;
            if (!bol[star.name]) cnt --;
        }
    }
    printf ("%d\n", ans);
    return 0;
}
