#pragma GCC optimize ("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2", 3)
#pragma G++ optimize ("Ofast", 3)
#pragma GCC optimize ("Ofast", 3)
#pragma G++ target ("avx","sse2")
#pragma GCC target ("avx","sse2")

#include <stdio.h>
#include <ctype.h>
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
		inline void read (long long &to) {
			unsigned long long x = 0; unsigned char c = gc();
			while (!isdigit(c)) c = gc();
			while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
			to = x;
		}
} io;

const unsigned long long table[19] = {
    1,
    10,
    100,
    1000,
    10000,
    100000ll,
    1000000ll,
    10000000ll,
    100000000ll,
    1000000000ll,
    10000000000ll,
    100000000000ll,
    1000000000000ll,
    10000000000000ll,
    100000000000000ll,
    1000000000000000ll,
    10000000000000000ll,
    100000000000000000ll,
    1000000000000000000ll
};

#define rint register int
#define ll long long

long long n, modn, cnt, t;
long long in[3][3];

struct node {
    long long a[3][3];
    short n, m;

    inline node (short x, short y)
    {
        fill (a[0], a[0] + 3*3, 0);
        n = x, m = y;
    }

    inline void set (long long aa[3][3])
    {
        for (rint i = 0; i <= 2; i ++)
            for (rint j = 0; j <= 2; j ++)
                a[i][j] = aa[i][j];
    }

    node operator * (const node &fu) const
    {
        node ret (n, fu.m);
        for (rint i = 0; i < n; i ++)
            for (rint j = 0; j < fu.m; j ++)
                for(int k = 0; k < m; k ++)
                    ret.a[i][j] = (ret.a[i][j] + a[i][k] * fu.a[k][j]) % modn;
        return ret;
    }

    node operator ^ (ll k) const
    {
        node ret (n, n), b = *this;
        for (rint i = 0; i < n; i ++) ret.a[i][i] = 1;
        for (; k; k >>= 1, b = b * b)
            if(k & 1) ret = ret * b;
        return ret;
    }
};

signed main ()
{
    io.read(n), io.read(modn);
    node ans (1, 3), nico (3, 3);
    for (rint i = 18; i >= 0; i --)
        if (table[i] <= n) {cnt = i; break;}
    for (rint i = 0; i < 3; i ++)
    {
        for (rint j = 0; j <= i; j ++) nico.a[i][j] = 1ll;
    }
    ans.a[0][2] = 1ll;
    for (rint i = 1; i <= cnt; i ++)
    {
        t = table[i];
        nico.a[0][0] = t % modn;
        ans = ans * (nico ^ (table[i-1] + (table[i-1] << 3)));
    }
    nico.a[0][0] = ((t<<1)+(t<<3)) % modn;
    ans = ans * (nico ^ (n - t + 1));
    printf ("%d\n", ans.a[0][0]);
}
