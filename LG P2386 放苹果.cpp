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

#define rint register int

inline char gc() {
    static char buf[1<<14],*p1=buf,*p2=buf;
    return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
}
//#define gc() getchar ()
inline int read () {
	rint x = 0; register char c = gc();
	while (!isdigit(c)) c = gc();
	while (isdigit(c)) x = x * 10 + c - 48, c = gc();
	return x;
}

int t, m, n;
const int table[11][11] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2},
    {2, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3},
    {3, 1, 3, 4, 5, 5, 5, 5, 5, 5, 5},
    {5, 1, 3, 5, 6, 7, 7, 7, 7, 7, 7},
    {7, 1, 4, 7, 9, 10, 11, 11, 11, 11, 11},
    {11, 1, 4, 8, 11, 13, 14, 15, 15, 15, 15},
    {15, 1, 5, 10, 15, 18, 20, 21, 22, 22, 22},
    {22, 1, 5, 12, 18, 23, 26, 28, 29, 30, 30},
    {30, 1, 6, 14, 23, 30, 35, 38, 40, 41, 42}
};

int main ()
{
    t = read();
    while (t --) printf ("%d\n", table[read()][read()]);
    return 0;
}
