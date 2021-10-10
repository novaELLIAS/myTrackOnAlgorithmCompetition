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
			int x = 0;
			char c = gc();
			bool m = 0;
			while (!isdigit(c) && c != '-') c = gc();
			if (c == '-') c = gc(), m = 1;
			while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
			if (m) to = -x;
			else to = x;
		}
} io;

class niconiconi {
    #define rint register int
    #define maxn 32001
    #define maxm 61
    private:
        int n, m;
        int val[maxm], cst[maxm], v, p, opt;
        int dp[maxn], fjv[maxm][3], fjw[maxm][3];
        inline void get_item ()
        {
            for (rint i = 1; i <= m; i ++)
            {
                io.read(v), io.read(p), io.read(opt);
                if (opt)
                {
                    fjw[opt][0] ++;
                    fjw[opt][fjw[opt][0]] = v;
                    fjv[opt][fjw[opt][0]] = v * p;
                } else cst[i] = v, val[i] = v * p;
            }
        }
        inline int maxx (int aa, int bb) {return aa>bb? aa:bb;}
    public:
        inline void work ()
        {
            io.read(n), io.read(m);
            get_item ();
            for (rint i = 1; i <= m; i ++)
            {
                for (rint j = n; j >= cst[i]; j --)
                {
                    dp[j] = maxx (dp[j], dp[j-cst[i]] + val[i]);
                    if (j >= cst[i] + fjw[i][1]) dp[j] = maxx (dp[j], dp[j-cst[i]-fjw[i][1]] + val[i] + fjv[i][1]);
                    if (j >= cst[i] + fjw[i][2]) dp[j] = maxx (dp[j], dp[j-cst[i]-fjw[i][2]] + val[i] + fjv[i][2]);
                    if (j >= cst[i] + fjw[i][1] + fjw[i][2]) dp[j] = maxx (dp[j], dp[j-cst[i]-fjw[i][1]-fjw[i][2]] + val[i] + fjv[i][1] + fjv[i][2]);
                }
            }
            printf ("%d\n", dp[n]);
        }
} elia;

int main ()
{
    elia.work ();
    return 0;
}
