#pragma G++ optimize ("Ofast", 3)
#pragma GCC optimize ("Ofast", 3)
#pragma GCC target ("sse3","sse2","sse")
#pragma GCC target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target ("f16c")
#pragma G++ target ("sse3","sse2","sse")
#pragma G++ target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma G++ target ("f16c")

#include <cstdio>
#include <algorithm>

static char buf[1<<14],*p1=buf,*p2=buf;	
inline char gc()
{
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
}
inline long long read ()
{
	register long long x = 0; register char c = gc();
	while (c < '0' || c > '9') c = gc();
	while (c>='0' && c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return x;
}

inline const int& max (const int& a, const int& b) {return a>b? a:b;}
inline const int& min (const int& a, const int& b) {return a<b? a:b;}
#define abs(x) ((x)<0? -(x):(x))

#define Re register
#define maxn 4001

struct node {
	int x, y, wei, exp;
} dat[maxn];
inline bool cmp (node a, node b) {return a.x < b.x;}

int main ()
{
	register int n = read (), m = read (), k = read (), t = read ();
	for (Re int i = 1; i <= k; ++ i)
	{
		dat[i].x = read(), dat[i].y = read(), dat[i].wei = dat[i].exp = read();
	}
	std::sort (dat + 1, dat + k + 1, cmp);
	
	for (Re int i = 1; i <= k; ++ i)
	{
		for (Re int j = 1; j < i; ++ j)
		{
			if (abs(dat[i].y - dat[j].y) <= t * abs(dat[i].x - dat[j].x))
			{
				dat[i].exp = max (dat[i].exp, dat[j].exp + dat[i].wei);
			}
		}
	}
	
	register int ans = -1;
	for (Re int i = 1; i <= k; ++ i) ans = max (ans, dat[i].exp);
	
	printf ("%d", ans);
	
	return 0;
}
