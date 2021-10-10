/*

	nico nioc ni

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

inline const int& max (const int& a, const int& b) {return a>b? a:b;}
inline const int& min (const int& a, const int& b) {return a<b? a:b;}

#define maxn 1000001
#define addn 1000000
#define dmax 2000001
#define rint register int

int dat[maxn][21], sta[maxn], las[dmax];

inline int query (int l, int r)
{
	register int t = (int)log2(r-l+1);
	return max (dat[l][t], dat[r+1-(1<<t)][t]);
}

inline int find (int ql, int qr)
{
	if (qr == sta[ql]) return ql;
	else if (ql > sta[qr]) return qr + 1;
	register int l = ql, r = qr, mid;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		if (sta[mid] >= ql) r = mid - 1;
		else l = mid + 1;
	}
	return l;
}

int main ()
{
	register int n = read (), m = read (), x, y, mid, LOGN = (int)log2 (n);
	for (rint i = 1; i <= n; i ++)
	{
		x = read ();
		sta[i] = max (sta[i-1], las[x + addn] + 1);
		dat[i][0] = i - sta[i] + 1;
		las[x + addn] = i;
	}
	
	for (rint j = 1; j <= LOGN; j ++)
	{
		x = n + 1 - (1 << j);
		for (rint i = 1; i <= x; i ++)
		{
			dat[i][j] = max (dat[i][j-1], dat[i+(1<<j-1)][j-1]);
		}
	}
	
	register int ans = 0;
	while (m --)
	{
		ans = 0;
		x = read () + 1, y = read () + 1, mid = find (x, y);
		if (x <  mid) ans = mid - x;
		if (y >= mid) ans = max (ans, query(mid, y));
		write (ans); putchar ('\n');
	}
	return 0;
}
