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

inline const int& min (const int& x,const int& y) {return x<y? x:y;}

#define maxn 100
#define maxa 1000
#define rint register int

int a, b, n, d[maxa][maxa], mx[maxa][maxa], mn[maxa][maxa], ans = 0x3f3f3f3f;
deque <int> qmax, qmin;

int main ()
{
    a = read(), b = read(), n = read() - 1;
    for (rint i = 0; i < a; i ++)
    {
        for (rint j = 0; j < b; j ++)
        {
            d[i][j] = read();
        }
    }
    for (rint i = 0; i < a; i ++)
    {
        qmax.clear (), qmin.clear ();
        for (rint j = 0; j < n; j ++)
        {
            while (!qmax.empty() && d[i][qmax.back()] < d[i][j]) qmax.pop_back();
            qmax.push_back (j);
            while (!qmin.empty() && d[i][qmin.back()] > d[i][j]) qmin.pop_back();
            qmin.push_back (j);
        }
        for (rint j = n; j < b; j ++)
        {
            while (!qmax.empty() && qmax.front() < j-n) qmax.pop_front();
            while (!qmax.empty() && d[i][qmax.back()] < d[i][j]) qmax.pop_back();
            qmax.push_back (j);
            mx[i][j-n] = d[i][qmax.front()];

            while (!qmin.empty() && qmin.front() < j-n) qmin.pop_front();
            while (!qmin.empty() && d[i][qmin.back()] > d[i][j]) qmin.pop_back();
            qmin.push_back (j);
            mn[i][j-n] = d[i][qmin.front()];
        }
    }
    /*
    puts("mx check");
    for (rint i = 0; i < a; i ++)
    {
        for (rint j = 0; j < b; j ++)
        {
            printf ("%d ", mx[i][j]);
        }
        puts ("");
    }
    puts("mn check");
    for (rint i = 0; i < a; i ++)
    {
        for (rint j = 0; j < b; j ++)
        {
            printf ("%d ", mn[i][j]);
        }
        puts("");
    }
    */
    for (rint i = 0; i < b-n; i ++)
    {
        qmax.clear (), qmin.clear ();
        for (rint j = 0; j < n; j ++)
        {
            while (!qmax.empty() && mx[qmax.back()][i] < mx[j][i]) qmax.pop_back();
            qmax.push_back (j);
            while (!qmin.empty() && mn[qmin.back()][i] > mn[j][i]) qmin.pop_back();
            qmin.push_back (j);
        }
        for (rint j = n; j < a; j ++)
        {
            while (!qmax.empty() && qmax.front() < j-n) qmax.pop_front();
            while (!qmax.empty() && mx[qmax.back()][i] < mx[j][i]) qmax.pop_back();
            qmax.push_back (j);

            while (!qmin.empty() && qmin.front() < j-n) qmin.pop_front();
            while (!qmin.empty() && mn[qmin.back()][i] > mn[j][i]) qmin.pop_back();
            qmin.push_back (j);

            ans = min (ans, mx[qmax.front()][i] - mn[qmin.front()][i]);
        }
    }
    printf ("%d\n", ans);
    return 0;
}
