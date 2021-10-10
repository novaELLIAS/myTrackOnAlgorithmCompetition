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

inline int read ()
{
	register int x = 0;register char c = gc();register bool t = false;
	while (!isdigit(c) && c!='-') c = gc();
	if (c=='-') t = true, c = gc();
	while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
	if (t) return -x;
	else return x;
}

inline void write (int x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}

inline const int& max (const int&a, const int&b) {return a>b? a:b;}
inline const int& min (const int&a, const int&b) {return a<b? a:b;}

#define rint register int

int maxx[1000001][21], minn[1000001][21];

int main ()
{
	register int n = read(), k = read(), top = log2(k), tmp;
	for (rint i = 1; i <= n; i ++) maxx[i][0] = minn[i][0] = read ();
	for (rint j = 1; j <= top; j ++)
	{
		tmp = n + 1 - (1 << (j-1));
		for (rint i = 1; i <= tmp; i ++)
		{
			maxx[i][j] = max (maxx[i][j-1], maxx[i+(1<<(j-1))][j-1]);
			minn[i][j] = min (minn[i][j-1], minn[i+(1<<(j-1))][j-1]);
		}
	}
	tmp = n - k + 1;
	register int t = k - (1<<(top));
	for (rint i = 1; i <= tmp; i ++)
	{
		write (max (maxx[i][top], maxx[i+t][top]));
		putchar (' ');
		write (min (minn[i][top], minn[i+t][top]));
		putchar ('\n');
	}
	return 0;
}
