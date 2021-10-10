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
        inline void read (double &to) {
			register int x = 0; register char c = gc(); register bool m = 0;
			while (!isdigit(c) && c != '-') c = gc();
			if (c == '-') c = gc(), m = 1;
			while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
			if (m) to = (double)-x;
			else to = (double)x;
		}
		inline void getdou (double &to) {
			register double x=0; register char ch = getchar (); register bool m = 0;
			while (!isdigit(ch) && ch != '-') ch = gc ();
			if (ch == '-') ch = gc(), m = 1;
			while (isdigit(ch)) x = x * 10 + (ch-48), ch = gc ();
			if (ch == '.') {
				double s = 0.1;
				ch = gc ();
				while (isdigit(ch)) x = x + (ch-48)*s,s/=10,ch = gc ();
			}
			if (m) to = -x;
			else to = x;
		}
} io;

#define maxn 102
#define rint register int
const double eps = 1e-7;
int n;
double tab[maxn][maxn], ans[maxn], tem[maxn];

inline double ffabs (double aa) {return aa<0? -aa:aa;}
inline void swapp (int x, int y)
{
    for (rint i = 1; i <= n+1; i ++) tem[i] = tab[x][i];
    for (rint i = 1; i <= n+1; i ++) tab[x][i] = tab[y][i];
    for (rint i = 1; i <= n+1; i ++) tab[y][i] = tem[i];
}

int main ()
{
    io.getint(n);
    for (rint i = 1; i <= n; i ++)
        for (rint j = 1; j <= n+1; j ++) io.read(tab[i][j]);
    register int pos;
    register double div;
    for (rint i = 1; i <= n; i ++)
    {
        pos = i;
        for (rint j = i+1; j <= n; j ++)
            if (ffabs(tab[pos][i]) < ffabs(tab[j][i])) pos = j;
        if (ffabs (tab[pos][i]) < eps) return puts("No Solution"), 0;
        if (pos != i) swapp (pos, i);
        div = tab[i][i];
        for (rint j = i; j <= n+1; j ++) tab[i][j] /= div;
        for (rint j = i+1; j <= n; j ++)
        {
            div = tab[j][i];
            for (rint k = i; k <= n+1; k ++) tab[j][k] -= tab[i][k] * div;
        }
    }
    ans[n] = tab[n][n+1];
    for (rint i = n-1; i >= 1; i --)
    {
        ans[i] = tab[i][n+1];
        for (rint j = i+1; j <= n; j ++) ans[i] -= tab[i][j] * ans[j];
    }
    for (rint i = 1; i <= n; i ++) printf ("%.2lf\n", ans[i]);
    return 0;
}
