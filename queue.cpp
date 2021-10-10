#pragma G++ optimize ("Ofast", 3)

#include <cstdio>

inline const int& max (const int& a, const int& b) {return a>b? a:b;}

#define Re register
#define maxn 2000011

const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;
inline char gc()
{
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}

int main ()
{
	freopen ("queue.in", "r", stdin);
	freopen ("queue.out","w",stdout);
	
	register int n, cnt = 0, ans = 0; scanf ("%d\n", &n);
	for (Re int i = 0; i ^ n; ++ i)
	{
		if (gc() == 'G') ans = max (ans + (i != cnt), i - cnt), ++ cnt;
	}
	
	printf ("%d", ans);
	
	return 0;
}
