#pragma G++ optimize (3)
#pragma GCC optimize ("Ofast", 3)

#include <cstdio>
#include <cmath>
#include <algorithm>

const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;
inline char gc()
{
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0; register char c = gc(); register bool m = 0;
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

#define Re register
#define maxn 500
#define sqr(x) ((x)*(x))

struct Node {
	int fr, to;
	double dis;
} e[250001];

inline bool cmp (const Node& a, const Node& b) {return a.dis < b.dis;}

int fa[maxn], xx[maxn], yy[maxn];

inline int find (register int x)
{
	while (x ^ fa[x]) x = fa[x] = fa[fa[x]];
	return x;
}

int main ()
{
	register int n = read (), k = read (), ecnt = 0;
	if (n <= k)
	{
		putchar ('0'), putchar ('.'), putchar ('0'), putchar ('0');
		return 0;
	}
	for (Re int i = 1; i <= n; ++ i) xx[i] = read (), yy[i] = read (), fa[i] = i;
	for (Re int i = 1; i ^  n; ++ i)
		for (Re int j = i + 1; j <= n; ++ j)
			e[++ ecnt].fr=i,e[ecnt].to=j,e[ecnt].dis=std::sqrt(sqr(xx[i]-xx[j])+sqr(yy[i]-yy[j]));
	std::sort (e + 1, e + ecnt + 1, cmp);
	register int fr, to, cnt = 0;
	for (Re int i = 1; i <= ecnt; ++ i)
	{
		fr = find (e[i].fr), to = find (e[i].to);
		if (fr ^ to)
		{
			fa[fr] = to, ++ cnt;
			if (cnt == n - k) return printf ("%.2lf", e[i].dis), 0;
		}
	}
	puts ("Err");
	return 0;
}
