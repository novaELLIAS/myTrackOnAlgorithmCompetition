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

#define maxn 30001
#define rint register int

int fa[maxn], sum[maxn], pre[maxn];

inline int find (int x)
{
    if (x == fa[x]) return x;
    register int fx = find (fa[x]);
    pre[x] += pre[fa[x]];
    return fa[x] = fx;
}

inline void nico_union (int a, int b)
{
    register int fx = find(a), fb = find(b);
    fa[fx] = fb;
    pre[fx] += sum[fb];
    sum[fb] += sum[fx];
    sum[fx] = 0;
}

inline void nico_query (int a, int b)
{
    if (find(a) != find(b)) puts ("-1");
    else write (pre[a]-pre[b]>0? pre[a]-pre[b]-1:pre[b]-pre[a]-1), putchar ('\n');
}

int main ()
{
    //freopen ("nico.in","r",stdin);
    for (rint i = 1; i <= 30000; i ++) fa[i] = i, sum[i] = 1;
    register int _ = read(), a, b;
    register char c; gc();
    while (_ --)
    {
        c = gc(), a = read(), b = read(), gc();
        if (c == 'M') nico_union (a, b);
        else nico_query (a, b);
    }
    return 0;
}
