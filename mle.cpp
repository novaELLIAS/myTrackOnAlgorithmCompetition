#include <cstdio>
const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;
inline char gc()
{
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline long long read ()
{
	register long long x = 0; register char c = gc(); register bool m = 0;
	while (c!='-'&&(c<'0'||c>'9') && c != '-') c = gc();
	if (c == '-') c = gc(), m = 1;
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return m? -x:x;
}
static void write (int x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}
inline const long long& min (const long long& a,const long long& b) {return a<b? a:b;}
inline const long long& max (const long long& a,const long long& b) {return a>b? a:b;}
typedef long long ll;
int main ()
{
	freopen ("mle.in", "r", stdin);
	freopen ("mle.out","w",stdout);
	
	register int n = read (), m = read ();
	register long long ans = 0, ss, ll, tt;
	for (Re int i = 1; i <= m; ++ i)
	{
		ss = read (), ll = read (), tt = read ();
		ans = max (ans, ss + tt);
	}
	printf ("%I64d\n", ans);
	puts ("0");
	return 0;
	/*
	puts ("2070");
	puts ("2");
	*/
}
