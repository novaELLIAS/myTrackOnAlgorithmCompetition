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
	register int x = 0; register char c = gc(); register bool m = 0;
	while ((c<'0'||c>'9') && c != '-') c = gc();
	if (c == '-') c = gc(), m = 1;
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return m? -x:x;
}
static void write (int x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}
static void writelen (int x) {write (x); putchar ('\n');}

#define Re register
#define maxn 3000001

inline const int& max (const int& a, const int& b) {return a>b? a:b;}

int a[maxn], dp[maxn], la[maxn];

int main ()
{
	freopen ("cake.in", "r", stdin);
	freopen ("cake.out","w",stdout);
	
	register int n = read (), ans = -0x3f3f3f3f;
	for (Re int i = 1; i <= n; i ++) a[i] = read (), la[i] = dp[i] = -0x3f3f3f3f;
	
	for (Re int i = 1; i <= n; i ++)
	{
		dp[i] = max (dp[i-1] + a[i], a[i]);
		la[i-1] = ans;
		ans = max (ans, dp[i]);
	}
	
	ans = -0x3f3f3f3f;
	for (Re int i = 2; i <= n; i ++)
	{
		dp[i] = max (dp[i-1] + a[i], la[i-1] + a[i]);
		ans = max (ans, dp[i]);
	}
	
	write (ans);
	
	return 0;
}
