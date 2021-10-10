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
		inline void read (int &to) {
			int x = 0;char c = gc();
			while (!isdigit(c)) c = gc();
			while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
			to = x;
		}
} io;

inline int maxx (int aa, int bb) {return aa>bb? aa:bb;}

#define maxn 1001
#define maxt 101
#define rint register int

int n, m, a[maxn], b[maxn], p[maxn], t[maxt][maxn], c, cnt, dp[maxn];

int main ()
{
    io.read(m), io.read(n);
    for (rint i = 1; i <= n; i ++)
    {
        io.read(a[i]), io.read(b[i]), io.read(c);
        cnt = maxx (cnt, c), p[c] ++, t[c][p[c]] = i;
    }
    for (rint i = 1; i <= cnt; i ++)
    {
        for (rint j = m; j >= 0; j --)
        {
            for (rint k = 1; k <= p[i]; k ++)
            {
                if (j < a[t[i][k]]) continue;
                dp[j] = maxx (dp[j], dp[j-a[t[i][k]]] + b[t[i][k]]);
            }
        }
    }
    printf ("%d\n", dp[m]);
    return 0;
}
