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
inline void read (int &to) {
	register int x = 0; register char c = gc();
	while (!isdigit(c)) c = gc();
	while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
	to = x;
}
