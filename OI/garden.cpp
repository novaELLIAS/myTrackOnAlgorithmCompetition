#pragma G++ optimize ("Ofast", 3)

#include <cstdio>
#include <stdlib.h>

#define Re register

static char buf[1<<14],*p1=buf,*p2=buf;
inline char gc()
{
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0; register char c = gc();
	while (c < '0' || c > '9') c = gc();
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return x;
}
static void write (int x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}
static void writelen (int x) {write (x); putchar ('\n');}
inline const int& min (const int& a, const int& b) {return a<b? a:b;}

int flo[1001][1001];

inline void solve1 (register int n, register int m)
{
	for (Re int i = 1; i <= n; ++ i)
	{
		for (Re int j = i+1; j <= n; ++ j) flo[i][j] = flo[j][i] = 1000000000;
	}
	register int x, y, z;
	while (m --)
	{
		x = read (), y = read (), z = read ();
		flo[x][y] = flo[y][x] = min (flo[x][y], z);
	}
	for (Re int k = 1; k <= n; ++ k)
	{
		for (Re int i = 1; i <= n; ++ i)
		{
			for (Re int j = 1; j <= n; ++ j)
			{
				if (i ^ j) flo[i][j] = flo[j][i] = min (flo[i][j], flo[i][k] + flo[k][j]);
			}
		}
	}
	register int q = read ();
	while (q --)
	{
		x = read(), y = read();
		writelen (flo[x][y]);
	}
	fclose (stdin), fclose (stdout);
	exit (0);
}

int main ()
{
	freopen ("garden.in", "r", stdin);
	freopen ("garden.out","w",stdout);
	
	register int n = read (), m = read ();
	
	if (n <= 1000) solve1 (n, m);
	else puts ("QAQ");
	
	fclose (stdin), fclose (stdout);
	return 0;
}
