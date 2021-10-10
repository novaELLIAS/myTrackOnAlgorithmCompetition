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

class fastio {
	private:
		inline char gc() {
			static char buf[1<<14],*p1=buf,*p2=buf;
			return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
		}
	public:
        //#define gc() getchar ()
		inline void getint (int &to) {
			register int x = 0; register char c = gc(); register bool m = 0;
			while (!isdigit(c) && c != '-') c = gc();
			if (c == '-') c = gc(), m = 1;
			while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
			if (m) to = -x;
			else to = x;
		}
} io;

#define rint register int
#define LoveLive long long
#define maxn 10
#define maxk 82
#define maxs 2001

int n, K, cnt;
int uta[maxs], sta[maxs];
LoveLive ans, dp[maxn][maxs][maxk];

inline void nico_dfs (int ste, int now, int sum)
{
    if (ste >= n) {sta[++ cnt] = now, uta[cnt] = sum; return;}
    nico_dfs (ste+1, now, sum);
    nico_dfs (ste+2, now + (1<<ste), sum + 1);
}

int main ()
{
    io.getint(n), io.getint(K);
    nico_dfs (0, 0, 0);
    for (rint i = 1; i <= cnt; i ++) dp[1][i][uta[i]] = 1;
    for (rint i = 2; i <= n; i ++)
    {
        for (rint j = 1; j <= cnt; j ++)
        {
            for (rint k = 1; k <= cnt; k ++)
            {
                if (sta[j] & sta[k]) continue;
                if ((sta[j]<<1) & sta[k]) continue;
                if ((sta[j]>>1) & sta[k]) continue;
                for (rint m = uta[j]; m <= K; m ++)
                    dp[i][j][m] += dp[i - 1][k][m - uta[j]];
            }
        }
    }
    for (rint i = 1; i <= cnt; i ++) ans += dp[n][i][K];
    printf ("%lld\n", ans);
    return 0;
}
