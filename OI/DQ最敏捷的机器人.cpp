/*

FUCK I64d

*/
#prag\
ma G++ optimize ("Ofast", 3)
#prag\
ma GCC optimize ("Ofast", 3)
#prag\
ma GCC target ("sse3","sse2","sse")
#prag\
ma GCC target ("avx","sse4","sse4.1","sse4.2","ssse3")
#prag\
ma GCC target ("f16c")
#prag\
ma G++ target ("sse3","sse2","sse")
#prag\
ma G++ target ("avx","sse4","sse4.1","sse4.2","ssse3")
#prag\
ma G++ target ("f16c")

#include <stdio.h>
#include <ctype.h>
#include <math.h>

inline char gc()
{
	static char buf[1<<14],*p1=buf,*p2=buf;
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
}

inline long long read ()
{
	register long long x = 0;register char c = gc();register bool t = false;
	while (!isdigit(c) && c!='-') c = gc();
	if (c=='-') t = true, c = gc();
	while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
	if (t) return -x;
	else return x;
}

inline void wwrite (long long x)
{
	if (x > 9) wwrite (x / 10);
	putchar (x % 10 + 48);
}

inline void write (long long x)
{
	if (x<0) putchar ('-'), x = -x;
	wwrite (x);
}

#define maxn 100001
#define rint register int

long long a[maxn], q1[maxn], q2[maxn];
int fr1, tl1, fr2, tl2;

int main(){
	//freopen ("nico.in","r",stdin);
	//freopen ("nico.out","w",stdout);
	register int n = read(), k = read(), t;
	for (rint i = 1; i <= n; ++ i) a[i] = read();
	for (rint i = 1; i < k; ++ i)
	{
		while (fr1 < tl1 && a[q1[tl1]] <= a[i]) -- tl1;
		q1[++ tl1] = i;
		while (fr2 < tl2 && a[q2[tl2]] >= a[i]) -- tl2;
		q2[++ tl2] = i;
	}
	for (rint i = k; i <= n; ++ i)
	{
		while (fr1 < tl1 && a[q1[tl1]] <= a[i]) -- tl1;
		while (fr1 < tl1 && i-q1[fr1+1]+1 > k) ++ fr1;
		q1[++ tl1] = i;
		while (fr2 < tl2 && a[q2[tl2]] >= a[i]) -- tl2;
		while (fr2 < tl2 && i-q2[fr2+1]+1 > k) ++ fr2;
		q2[++ tl2] = i;
		write (a[q1[fr1 + 1]]); putchar (' ');
		write (a[q2[fr2 + 1]]); putchar('\n');
	}
	return 0;
}
