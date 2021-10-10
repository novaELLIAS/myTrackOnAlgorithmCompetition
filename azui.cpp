#pragma G++ optimize ("Ofast", 3)

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
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return x;
}
static void write (int x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}
static void writelen (int x) {write (x); putchar ('\n');}

bool a[1000001];

inline bool azui (int x, int y) {return x==y;}

int main ()
{
	freopen ("azui.in", "r", stdin);
	freopen ("azui.out","w",stdout);
	
	register int n = read (); a[1] = read ();
	for (register int i = 2; i <= n; ++ i) a[i] = azui(a[i-1], read ());
	register int m = read (), l, r;
	while (m --)
	{
		l = read (), r = read ();
		writelen (l==1? a[r]:azui(a[r], a[l-1]));
	}
	
	fclose (stdin), fclose (stdout);
	return 0;
}
