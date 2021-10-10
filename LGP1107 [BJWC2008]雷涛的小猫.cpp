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
			int x = 0;char c = gc();bool m = 0;
			while (!isdigit(c) && c != '-') c = gc();
			if (c == '-') c = gc(), m = 1;
			while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
			if (m) to = -x;
			else to = x;
		}
} io;

class niconiconi {
    #define maxn 2002
    #define maxh 5002
    #define rint register int
    private:
        int n, h, d, x, y, z, mx, p;
        int dp[maxn][maxh], md[maxh], data[maxn][maxh];
        inline int maxx (int aa, int bb) {return aa>bb? aa:bb;}
    public:
        inline void work ()
        {
            io.read(n), io.read(h), io.read(d), x = h - d;
            for (rint i = 1; i <= n; i ++)
            {
                io.read(z);
                while (z --) io.read(y), data[i][y] ++;
            }

            for (rint i = 1; i <= n; i ++) dp[i][h] = data[i][h], md[h] = maxx (md[h], data[i][h]);
            for (rint j = h-1; j > x; j --)
            {
                for (rint i = 1; i <= n; i ++)
                {
                    dp[i][j] = maxx (dp[i][j+1] + data[i][j], dp[i][j]), md[j] = maxx (md[j], dp[i][j]);
                }
            }
            for (rint j = x; j >= 1; j --)
            {
                for (rint i = 1; i <= n; i ++)
                {
                    dp[i][j] = maxx (dp[i][j], dp[i][j+1] + data[i][j]);
                    dp[i][j] = maxx (dp[i][j], data[i][j] + md[j+d]);
                    md[j] = maxx (md[j], dp[i][j]);
                }
            }
            printf ("%d\n", md[1]);
        }
} elia;

int main ()
{
    elia.work ();
    return 0;
}
