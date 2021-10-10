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

signed main ()
{
	
}
