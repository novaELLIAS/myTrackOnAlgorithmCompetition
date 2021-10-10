#pragma G++ optimzie (3)

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
inline const int& min (const int& a, const int& b) {return a<b? a:b;}
inline const int& max (const int& a, const int& b) {return a>b? a:b;}
static void write (int x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}
static void writelen (int x) {write (x); putchar ('\n');}

#define Re register
#define maxn 10001

bool vis[maxn][maxn];
int dat[maxn];

signed main ()
{
	register int n = read (), p = read (), h = read (), _ = read ();
	register int x, y;
	while (_ --)
	{
		x = read (), y = read ();
		if (x > y) x ^= y ^= x ^= y;
		if (!vis[x][y])
		{
			vis[x][y] = true;
			-- dat[x+1], ++ dat[y];
		}
	}
	for (Re int i = 1; i <= n; ++ i)
	{
		dat[i] = dat[i-1] + dat[i];
		writelen (dat[i] + h);
	}
	return 0;
}
