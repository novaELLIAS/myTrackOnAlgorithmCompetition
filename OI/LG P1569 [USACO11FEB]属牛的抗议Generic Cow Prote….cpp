#pragma G++ optimize (3)
#include <cstdio>

inline char gc()
{
	static char buf[1<<14],*p1=buf,*p2=buf;
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0; register char c = gc(); register bool m = false;
	while ((c < '0' || c > '9') && (c ^ '-')) c = gc();
	if (c == '-') m = true, c = gc ();
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c - '0'), c = gc();
	return m? -x:x;
}
inline const int& max (const int& a, const int& b) {return a>b? a:b;}
#define Re register

int dat[1000001], dp[1000001];

signed main ()
{
	register int n = read ();
	for (Re int i = 1; i <= n; ++ i)
		dp[i] = (dat[i] = dat[i-1] + read ())>=0? 1:0;
	for (Re int i = 1; i <= n; ++ i)
		for (Re int j = 1; j < i; ++ j)
			if (dp[j] && dat[i]>=dat[j])
				dp[i] = max (dp[i], dp[j] + 1);
	if (dp[n]) printf ("%d", dp[n]);
	else printf ("Impossible");
	return 0;
}
