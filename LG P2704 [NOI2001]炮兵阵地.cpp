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

inline void write (long long x) {
    if (x > 9) write (x / 10);
    putchar (x % 10 + 48);
}

#define rint register int
#define LoveLive long long
#define ll long long
#define maxn 101
#define maxm 11
#define maxt 1001

inline int maxx (int aa, int bb) {return aa>bb? aa:bb;}

int n, m, cnt, all, ans;
int mapp[maxn], sta[maxt], sum[maxt], dp[maxn][maxt][maxt];

inline void nico_input ()
{
    scanf ("%d %d", &n, &m);
    all = (1<<m);
    register char c;
    for (rint i = 1; i <= n; i ++)
    {
        for (rint j = m - 1; j >= 0; j --)
        {
            scanf ("\n%c", &c);
            if (c == 'H') mapp[i] |= (1 << j);
        }
    }
}

class nico_generation {
    private:
        inline bool check (int i)
        {
            if (((i<<2)&i) || ((i>>2)&i) || ((i<<1)&i) || ((i>>1)&i)) return false;
            else return true;
        }
        inline int getnum (int x)
        {
            register int ret = 0;
            while (x) ret ++, x -= x&(-x);
            return ret;
        }
    public:
        inline void generate ()
        {
            for (rint i = 0; i < all; i ++)
            {
                if (check (i)) {
                    sta[++ cnt] = i;
                    sum[cnt] = getnum (i);
                    if (!(i&mapp[1])) dp[1][0][cnt] = sum[cnt];
                }
            }
        }
} generation;

inline void second_work ()
{
    for (rint i = 1; i <= cnt; i ++)
    {
        for (rint j = 1; j <= cnt; j ++)
        {
            if (!(sta[i]&sta[j]) && !(sta[j]&mapp[2])) dp[2][i][j] = maxx (dp[2][i][j], dp[1][0][i] + sum[j]);
        }
    }
}

inline void nico_work ()
{
    for (rint i = 3; i <= n; i ++) // lines
    {
        for (rint j = 1; j <= cnt; j ++) // now standard
        {
            if (!(mapp[i] & sta[j])) {
                for (rint p = 1; p <= cnt; p ++) // pre standard
                {
                    if (!(sta[p]&sta[j])) {
                        for (rint q = 1; q <= cnt; q ++) // pre pre standard
                        {
                            if (!(sta[q]&sta[p]) && !(sta[q]&sta[j])) {
                                dp[i][p][j] = maxx (dp[i][p][j], dp[i-1][q][p] + sum[j]);
                            }
                        }
                    }
                }
            }
        }
    }
}

inline void get_ans ()
{
    for (rint i = 1; i <= cnt; i ++)
    {
        for (rint j = 1; j <= cnt; j ++)
        {
            ans = maxx (ans, dp[n][i][j]);
        }
    }
}

inline void final_check ()
{
    for(rint i = 1; i <= n; i ++)
    {
        printf ("---line %d ---\n", i);
        for(rint j = 0; j <= cnt; j ++)
        {
            for (rint k = 0; k <= cnt; k ++)
            {
                printf ("%d ", dp[i][j][k]);
            }
            puts ("");
        }
    }
}

inline void generate_check ()
{
    for (rint i = 1; i <= cnt; i ++) printf ("sta %d : %d %d\n", i, sta[i], sum[i]);
}

int main ()
{
    nico_input ();
    generation.generate ();

    //generate_check ();

    second_work ();
    nico_work ();

    //final_check ();

    get_ans ();
    printf ("%d\n", ans);
    return 0;
}
