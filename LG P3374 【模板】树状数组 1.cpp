#pragma GCC optimize ("Ofast", 3)
#pragma GCC target ("sse3","sse2","sse")
#pragma GCC target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target ("f16c")

#include <cstdio>

const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;
inline char gc() {
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline long long read ()
{
	register long long x = 0; register char c = gc(); register bool m = false;
	while ((c < '0' || c > '9') && (c ^ '-')) c = gc();
	if (c == '-') m = true, c = gc ();
	while (c>='0'&&c<='9') x = (x<<3) + (x<<1) + (c^'0'), c = gc();
	return m? -x:x;
}
inline const int max (const int& a, const int& b) {return a>b? a:b;}
inline const int min (const int& a, const int& b) {return a<b? a:b;}

#define Re register
#define maxn 500001
#define lowbit(x) ((x)&(-(x)))
#define swap(x,y) ((x)^=(y)^=(x)^=(y))

int dat[maxn];

inline void add (Re int x, Re int val, Re int n) {
	while (x <= n) dat[x] += val, x += lowbit(x);
}

inline int que (Re int x) {
	register int ret = 0;
	while (x) ret += dat[x], x -= lowbit(x);
	return ret;
}

signed main ()
{
	register int n = read (), m = read ();
	register int opt, x, y;
	for (Re int i = 1; i <= n; ++ i)
		x = read (), add(i, x, n);
	while (m --)
	{
		opt = read (), x = read (), y = read ();
		if (opt == 1) add (x, y, n);
		else {
			if (x > y) swap (x, y);
			printf ("%d\n", que(y)-que(x-1));
		}
	}
	return 0;
}
