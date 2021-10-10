#pragma GCC optimize (2)
#pragma G++ optimize (2)
#pragma GCC optimize (3)
#pragma G++ optimize (3)
#pragma GCC optimize ("Ofast")
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
#pragma GCC optimize ("-fwhole-program")
#pragma GCC optimize ("-freorder-blocks")
#pragma GCC optimize ("-fschedule-insns")
#pragma GCC optimize ("inline-functions")
#pragma GCC optimize ("-ftree-tail-merge")
#pragma GCC optimize ("-fschedule-insns2")
#pragma GCC optimize ("-fstrict-aliasing")
#pragma GCC optimize ("-fstrict-overflow")
#pragma GCC optimize ("-falign-functions")
#pragma GCC optimize ("-fcse-skip-blocks")
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
#pragma GCC optimize ("-funsafe-loop-optimizations")
#pragma GCC optimize ("inline-functions-called-once")
#pragma GCC optimize ("-fdelete-null-pointer-checks")
#pragma GCC target ("sse3","sse2","sse")
#pragma GCC target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target ("f16c")
#pragma G++ target ("sse3","sse2","sse")
#pragma G++ target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma G++ target ("f16c")

#include <cstdio>

static char buf[1<<14],*p1=buf,*p2=buf;	
inline char gc()
{
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0; register char c = gc(); register bool m = 0;
	while (c < '0'|| c > '9') {if (c == '-') m = true; c = gc();}
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return m? -x:x;
}
static void write (int x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}
static void writespace (int x) {if (x<0) putchar('-'), x = -x; write (x); putchar (' ');}

inline const int& min (const int& a, const int& b) {return a<b? a:b;}
inline const int& max (const int& a, const int& b) {return a>b? a:b;}

#define Re register
#define maxn 1000001

int minque[maxn], maxque[maxn], maxans[maxn], minans[maxn], dat[maxn];

int main ()
{
	register int n = read (), k = read(), maxhead=1, minhead=1, maxtail=0, mintail=0;
	register int minpos = 0, maxpos = 0;
	for (Re int i = 1; i <= n; ++ i) dat[i] = read ();
	
	for (Re int i = 1; i ^ k; ++ i)
	{
		while (maxhead <= maxtail && dat[maxque[maxtail]]<=dat[i]) -- maxtail;
		while (minhead <= mintail && dat[minque[mintail]]>=dat[i]) -- mintail;
		maxque[++ maxtail] = minque[++ mintail] = i;
	}
	
	for(Re int i = k; i <= n; ++ i)
	{
		while (maxhead <= maxtail && dat[maxque[maxtail]]<=dat[i]) -- maxtail;
		maxque[++ maxtail] = i;
		if (maxque[maxhead] + k <= i) ++ maxhead;
		maxans[++ maxpos] = dat[maxque[maxhead]];
		
		while (minhead <= mintail && dat[minque[mintail]]>=dat[i]) -- mintail;
		minque[++ mintail] = i;
		if (minque[minhead] + k <= i) ++ minhead;
		minans[++ minpos] = dat[minque[minhead]];
	}
	
	for (Re int i = 1; i <= minpos; ++ i) writespace(minans[i]);
	putchar('\n');
	for (Re int i = 1; i <= maxpos; ++ i) writespace(maxans[i]);
	
	return 0;
}
