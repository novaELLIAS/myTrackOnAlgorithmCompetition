#pragma GCC optimize ("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2", 3)
#pragma G++ optimize ("Ofast", 3)
#pragma GCC optimize ("Ofast", 3)
#pragma G++ target ("avx","sse2")
#pragma GCC target ("avx","sse2")

#include <stdio.h>
#include <ctype.h>

class fastio {
//#define gc() getchar ()
	private:
		inline char gc() {
			static char buf[1<<14],*p1=buf,*p2=buf;
			return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
		}
	public:
		inline void read (long long &to) {
			unsigned long long x = 0; unsigned char c = gc();
			while (!isdigit(c)) c = gc();
			while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
			to = x;
		}
} io;

#define rint register int
#define ll long long
#define modn 1000000007

struct node {
    ll a[2][2];
    inline void set (int aa, int bb, int cc, int dd)
    {
        a[0][0] = aa, a[0][1] = bb, a[1][0] = cc, a[1][1] = dd;
    }
} nico, one, zero, ans;

long long n;

inline node xxx (node aa, node bb)
{
    node ret = zero;
    for (rint i = 0; i <= 1; i ++)
    {
        for (rint j = 0; j <= 1; j ++)
        {
            for (rint k = 0; k <= 1; k ++)
            {
                ret.a[i][j] += aa.a[i][k] * bb.a[k][j], ret.a[i][j] %= modn;
            }
        }
    }
    return ret;
}

inline void poww (node k, ll t)
{
    ans = nico;
    while (t)
    {
        if (t&1) ans = xxx (ans, k);
        t >>= 1;
        k = xxx (k, k);
    }
}

int main ()
{
    io.read(n);
    if (n == 0) return puts ("0"), 0;
    else if (n == 1 || n == 2) return puts ("1"), 0;
    nico.set (1, 1, 1, 0), one.set (1, 0, 0, 1);
    poww (nico, n-2);
    printf ("%d\n", ans.a[0][0]);
}
