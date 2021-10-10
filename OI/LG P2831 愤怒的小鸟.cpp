#pragma GCC optimize ("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2", 3)
#pragma G++ optimize ("Ofast", 3)
#pragma GCC optimize ("Ofast", 3)
#pragma G++ target ("avx","sse2")
#pragma GCC target ("avx","sse2")

#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define gc() getchar()
#define rint register int
#define maxn 20

inline int getint ()
{
    int x = 0;char c = gc();bool m = 0;
    while (!isdigit(c) && c != '-') c = gc();
    if (c == '-') c = gc(), m = 1;
    while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
    if (m) return -x;
    else return x;
}

inline double getdou ()
{
    double x=0;char ch = getchar ();while (!isdigit(ch)) ch = getchar ();
    while (isdigit(ch)) x = x * 10 + (ch-48), ch = getchar ();
    if (ch == '.') {
        double s = 0.1;
        ch = getchar ();
        while (isdigit(ch)) x = x + (ch-48)*s,s/=10,ch = getchar ();
    }
    return x;
}

const double eps = 1e-10;

int n, T, ans;
double x[maxn], y[maxn], shoota[maxn], shootb[maxn], spx[maxn], spy[maxn];

inline bool cmp (double a, double b) {return fabs (a-b) < eps;}
inline double get_a (int p, int i) {return (y[p]*spx[i]-x[p]*spy[i]) / (x[p]*x[p]*spx[i]-x[p]*spx[i]*spx[i]);}
inline double get_b (double a, int p) {return (y[p]-a*x[p]*x[p])/x[p];}

inline void nico_dfs (int p, int u, int v)
{
	//printf ("%d %d %d %d\n", ans, p, u, v);
	bool flag = true;
	double a, b, xx, yy;
	if (u + v >= ans) return;
	if (p > n) {ans = u + v; return;}
	for (rint i = 1; i <= u; i ++)
	{
		if (cmp (shoota[i]*x[p]*x[p] + shootb[i]*x[p], y[p]))
		{
			//puts ("check1");
			nico_dfs (p+1, u, v);
			flag = false;
			break;
		}
	}
	if (flag)
	{
		for (int i = 1; i <= v; i ++)
		{
			if (cmp (x[p], spx[i])) continue;
			a = (y[p]*spx[i]-x[p]*spy[i]) / (x[p]*x[p]*spx[i]-x[p]*spx[i]*spx[i]);
			b = (y[p]-a*x[p]*x[p])/x[p];
			if (a >= 0) continue;
			//puts ("check2");
			shoota[u+1] = a, shootb[u+1] = b;
			xx = spx[i], yy = spy[i];
			for (rint j = i; j < v; j ++) spx[j] = spx[j+1], spy[j] = spy[j+1];
			nico_dfs (p+1, u+1, v-1);
			for (rint j = v; j > i; j --) spx[j] = spx[j-1], spy[j] = spy[j-1];
			spx[i] = xx, spy[i] = yy;
		}
		spx[v+1] = x[p], spy[v+1] = y[p];
		//puts ("check3");
		nico_dfs (p+1, u, v+1);
	}
}

int main ()
{
	T = getint ();
	while (T --)
	{
		n = getint (); getint ();
		ans = 30;
		for (rint i = 1; i <= n; i ++) x[i] = getdou (), y[i] = getdou ();
		nico_dfs (1, 0, 0);
		printf ("%d\n", ans);
	}
	return 0;
}
