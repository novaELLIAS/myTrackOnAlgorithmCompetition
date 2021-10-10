#pragma G++ optimize (3)

#include <cstdio>

const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;
inline char gc()
{
    return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
    register int x = 0; register char c = gc();
    while (c < '0' || c > '9') c = gc();
    while (c>='0'&&c<='9') x = (x<<3) + (x<<1) + (c^'0'), c = gc();
    return x;
}
static void write (int x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}
static void writelen (int x) {write (x); putchar ('\n');}
inline const int& min (const int& a, const int& b) {return a<b? a:b;}

#define Re register
#define maxn 50001

int dat[maxn];

inline int find (register int x, register int n)
{
	register int l = 0, r = n + 1, mid, ans;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		if (dat[mid] > x) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	return ans;
}

signed main ()
{
	register int n = read (), m = read (), que;
	for (Re int i = 1; i <= n; ++ i) dat[i] = dat[i-1] + read ();
	while (m --)
	{
		que = read ();
		writelen (find (que, n));
	}
	return 0;
}
