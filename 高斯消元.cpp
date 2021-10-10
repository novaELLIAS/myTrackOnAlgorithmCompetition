#pragma GCC optimize (2)
#pragma GCC optimize ("inline")
#pragma GCC optimize ("-fgcse")
#pragma GCC optimize ("-fgcse-lm")
#pragma GCC optimize ("-fipa-sra")
#pragma GCC optimize ("-ftree-pre")
#pragma GCC optimize ("-ftree-vrp")
#pragma GCC optimize ("-fpeephole2")
#pragma GCC optimize ("-ffast-math")
#pragma GCC optimize ("-fsched-spec")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("-falign-jumps")
#pragma GCC optimize ("-falign-loops")
#pragma GCC optimize ("-falign-labels")
#pragma GCC optimize ("-fdevirtualize")
#pragma GCC optimize ("-fcaller-saves")
#pragma GCC optimize ("-fcrossjumping")
#pragma GCC optimize ("-fthread-jumps")
#pragma GCC optimize ("-funroll-loops")
#pragma GCC optimize ("-freorder-blocks")
#pragma GCC optimize ("-fschedule-insns")
#pragma GCC optimize ("inline-functions")
#pragma GCC optimize ("-ftree-tail-merge")
#pragma GCC optimize ("-fschedule-insns2")
#pragma GCC optimize ("-fstrict-aliasing")
#pragma GCC optimize ("-falign-functions")
#pragma GCC optimize ("-fcse-follow-jumps")
#pragma GCC optimize ("-fsched-interblock")
#pragma GCC optimize ("-fpartial-inlining")
#pragma GCC optimize ("no-stack-protector")
#pragma GCC optimize ("-freorder-functions")
#pragma GCC optimize ("-findirect-inlining")
#pragma GCC optimize ("-fhoist-adjacent-loads")
#pragma GCC optimize ("-frerun-cse-after-loop")
#pragma GCC optimize ("inline-small-functions")
#pragma GCC optimize ("-finline-small-functions")
#pragma GCC optimize ("-ftree-switch-conversion")
#pragma GCC optimize ("-foptimize-sibling-calls")
#pragma GCC optimize ("-fexpensive-optimizations")
#pragma GCC optimize ("inline-functions-called-once")
#pragma GCC optimize ("-fdelete-null-pointer-checks")
#pragma GCC optimize ("Ofast", 3)
#pragma GCC target ("sse3","sse2","sse")
#pragma GCC target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target ("f16c")
#pragma GCC optimize ("Ofast", 3)

#include <cstdio>

typedef double dou;
#define Re register

const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;
inline char gc()
{
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0; register char c = gc(); register bool m = false;
	while ((c < '0' || c > '9') && (c ^ '-')) c = gc();
	if (c == '-') m = true, c = gc ();
	while (c>='0'&&c<='9') x = (x<<3) + (x<<1) + (c^'0'), c = gc();
	return m? -x:x;
}

/*------------------------------------------------------------*/
double dat[101][102], tmp[102], ans[101];
const double eps = 1e-7;
/*------------------------------------------------------------*/

inline void swap (Re int a, Re int b, Re int n)
{
	++ n;
	for (Re int i = 1; i <= n; ++ i)
		tmp[i]=dat[a][i], dat[a][i]=dat[b][i];
	for (Re int i = 1; i <= n; ++ i) dat[b][i]=tmp[i];
}
inline double abs (Re double x) {return x<0? -x:x;}

signed main ()
{
	register int n=read(), nn = n + 1, i, j, pos, k;
	register double div;
	for (i = 1; i <= n; ++ i)
		for (j = 1; j <= nn; ++ j)
			dat[i][j]=1.0*read();
	for (i = 1; i <= n; ++ i)
	{
		pos = i;
		for (j = i + 1; j <= n; ++ j)
			if (abs(dat[j][i])>abs(dat[pos][i])) pos=j;
		if (abs(dat[pos][i])<eps) return printf("No Solution"), 0;
		if (pos^i) swap (pos, i, n);
		div = dat[i][i];
		for (j = i; j <= nn; ++ j) dat[i][j] /= div;
		for (j = i+1; j <= n; ++ j) {
			div = dat[j][i];
			for (k = i; k <= nn; ++ k) dat[j][k] -= div * dat[i][k];
		}
	}
	ans[n] = dat[n][nn];
	for (i = n-1; i; -- i)
	{
		ans[i] = dat[i][nn];
		for (j = i+1; j <= n; ++ j) ans[i] -= ans[j] * dat[i][j];
	}
	for (i = 1; i <= n; ++ i) printf ("%.2lf\n", ans[i]);
	return 0;
}
