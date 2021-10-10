#pragma G++ optimize (3)

#include <cstdio>
#include <cmath>
#include <algorithm>

using std::sort;

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
#define maxn 50001
#define sqr(x) ((x)*(x))
typedef double dou;

struct node {
	int x, y, z;
} dat[maxn];

inline bool cmp (node a, node b) {return a.z < b.z;}

signed main ()
{
	register int n = read ();
	register double ans = 0.0;
	
	for (Re int i = 1; i <= n; ++ i)
		dat[i].x = read (), dat[i].y = read (), dat[i].z = read ();
	
	sort (dat + 1, dat + n + 1, cmp);
	
	for (Re int i = 2; i <= n; ++ i)
		ans += sqrt(sqr(dat[i-1].x-dat[i].x)+sqr(dat[i-1].y-dat[i].y)+sqr(dat[i].z-dat[i-1].z));
	
	printf ("%.3lf", ans);
	return 0;
}
