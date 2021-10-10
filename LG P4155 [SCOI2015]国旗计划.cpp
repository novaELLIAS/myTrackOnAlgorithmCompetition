#pragma GCC optimize ("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2", 3)
#pragma G++ optimize ("Ofast", 3)
#pragma GCC optimize ("Ofast", 3)
#pragma G++ target ("avx","sse2")
#pragma GCC target ("avx","sse2")

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
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
			int x = 0;char c = gc();
			while (!isdigit(c)) c = gc();
			while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
			to = x;
		}
} io;

#define rint register int
#define maxn 400002
#define maxm 1000000001

struct node {
    int sta, end, name;
    inline void set (int s,int ee,int n) {sta = s, end = ee, name = n;}
} e[maxn];

inline bool cmp (node aa, node bb) {return aa.sta==bb.sta? aa.end<bb.end:aa.sta<bb.sta;}

int n, m, c, d, top, cnt, ans[200001];
int id[maxn][20];

inline int find (rint l, rint r, rint x)
{
    register int ret, mid;
    while (l <= r)
    {
        mid = (l+r) >> 1;
        if (e[mid].sta <= x) l = mid + 1, ret = mid;
        else r = mid - 1;
    }
    return ret;
}

int main ()
{
    io.read(n), io.read(m), top = ceil(log2(n)), cnt = n;
    for (rint i = 1; i <= n; i ++)
    {
        io.read(c), io.read(d);
        e[i].set (c, d, i);
        if (c > d) e[i].end += m;
        else e[++ cnt].set(c+m, d+m, i);
    }
    sort (e+1, e+cnt+1, cmp);
    e[cnt+1].set (0, 2e9+10, 0);
    fill (id[0], id[0] + maxn*20, cnt+1);
    for (rint i = 1; i <= cnt; i ++) id[i][0] = find (i+1, cnt+1, e[i].end);
    for (rint j = 1; j <= top; j ++)
    {
        for (rint i = 1; i <= cnt; i ++) id[i][j] = id[id[i][j-1]][j-1];
    }
    /*
    for (register int i = 1; i <= cnt; i ++)
    {
        for (register int j = 0; j <= top; j ++)
        {
            printf ("%d ", id[i][j]);
        }
        putchar ('\n');
    }
    */
    register int now, pos, to;
    for (rint i = 1; i <= cnt; i ++)
    {
        pos = e[i].name;
        if (ans[pos] || !pos) continue;
        now = i, to = e[i].sta + m;
        for (rint j = top; j >= 0; j --)
        {
            if (e[id[now][j]].end < to) now = id[now][j], ans[pos] += (1 << j);
        }
    }
    for (rint i = 1; i <= n; i ++) printf ("%d ", ans[i] + 2);
    //putchar ('\n');
    return 0;
}
