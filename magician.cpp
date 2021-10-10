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
static void write (long long x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}

#define Re register
#define maxn 200001
#define modn 1000000009ll

int fa[maxn];

inline int find (register int x)
{
	while (x ^ fa[x]) x = fa[x] = fa[fa[x]];
	return x;
}

signed main ()
{
	freopen ("magician.in", "r", stdin);
	freopen ("magician.out","w",stdout);
	
	register int n = read (), _ = read ();
	for (Re int i = 1; i <= n; ++ i) fa[i] = i;
	register int fr, to;
	register long long ans = 0ll;
	while (_ --)
	{
		fr = find (read()), to = find (read());
		if (fr ^ to) fa[fr] = to;
		else ans = ans<<1|1, ans %= modn;
		write (ans), putchar ('\n');
	}
	
	fclose (stdin), fclose (stdout);
	return 0;
}
