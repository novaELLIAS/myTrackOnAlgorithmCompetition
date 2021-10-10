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

#include <cstdio>

const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;
inline char gc()
{
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0; register char c = gc();// register bool m = 0;
	while ((c < '0' || c > '9')/* && (c ^ '-')*/) c = gc();
	//if (c == '-') c = gc(), m = true;
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return x;
	//return m? -x:x;
}
static void write (long long x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}
static void writelen (long long x) {/*if(x<0)x=-x,putchar('-'); */write (x); putchar ('\n');}

#define Re register
#define maxn 50001
typedef long long ll;

int dat[maxn], ord[maxn], out[maxn];

inline bool check (register ll exp, register int n, Re int d)
{
	register long long now=0ll;
	for (Re int i=1, day=1; day<=d; ++ day)
	{
		now >>= 1;
		while (now<exp && i<=n) now += dat[i], ord[i]=day, ++ i;
		if (i>n && now<exp) return false;
	}
	return now>=exp;
}

inline void cp (register int n)
{
	//puts ("cp");
	for (Re int i=1; i<=n; ++ i)
		out[i]=ord[i];// printf ("%d ", ord[i]);
	//puts ("");
}

signed main ()
{
	//freopen ("nico.in","r",stdin); 
	register int n=read(), d=read();
	register int i;
	register long long ans=0ll, l=0ll, r=0ll, mid;
	for (i=1; i<=n; ++i) dat[i]=read(), r+=dat[i];
	while (l<=r)
	{
		mid=(l+r)>>1;
		//printf ("%d %d %d\n", l, r, mid);
		if (check(mid, n, d)) ans=mid, l=mid+1, cp(n);
		else r=mid-1;
	}
	writelen (ans);
	//for (i=1; i<=n; ++i) writelen (out[i]);
	for (i=1; i<=n; ++i)
	{
		if (out[i]>=out[i-1]) writelen(out[i]);
        else writelen(out[i]=d);
	}
	return 0;
}
