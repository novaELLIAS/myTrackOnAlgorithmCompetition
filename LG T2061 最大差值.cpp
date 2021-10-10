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
	register int x = 0; register char c = gc(); register bool m = false;
	while ((c < '0' || c > '9') && (c ^ '-')) c = gc();
	if (c == '-') m = true, c = gc ();
	while (c>='0'&&c<='9') x = (x<<3) + (x<<1) + (c^'0'), c = gc();
	return m? -x:x;
}
inline const int max (const int& a, const int& b) {return a>b? a:b;}
inline const int min (const int& a, const int& b) {return a<b? a:b;}
#define Re register
#define maxn 1000001
int a[maxn];
signed main ()
{
	register int n = read (), dat, ans = -0x3f3f3f3f;
	a[0] = 0x3f3f3f3f;
	
	for (Re int i = 1; i <= n; ++ i)
	{
		dat = read ();
		a[i] = min (dat, a[i-1]);
		ans = max (ans, dat - a[i-1]);
	}
	
	printf ("%d", ans);
	return 0;
}
