#pragma G++ optimize ("Ofast", 3)

#include <cstdio>
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
	while ((c < '0' || c > '9') && c != '-') c = gc();
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

inline const int& min (const int& a, const int& b) {return a<b? a:b;}
inline const int& max (const int& a, const int& b) {return a>b? a:b;}

#define Re register
#define maxn 2001
#define maxm 5001

int fa[maxn], vq[maxm];

struct node {
	int fr, to;
	int vp, vq;
} e[maxm];

inline bool cmp (node a, node b) {return a.vp < b.vp;}

inline int find (register int x)
{
	while (x != fa[x]) x = fa[x] = fa[fa[x]];
	return x;
}

inline int niconi (register int qlim, register int n, register int m)
{
	register int fr, to, va, cnt = 0, ret = -1;
	for (Re int i = 1; i <= n; ++ i) fa[i] = i;
	for (Re int i = 1; i <= m; ++ i)
	{
		if (e[i].vq <= qlim)
		{
			fr = find (e[i].fr), to = find (e[i].to);
			if (fr ^ to) ++ cnt, fa[fr] = to, ret = max (ret, e[i].vp);
			if (cnt == n-1) return ret;
		}
	}
	return 0x3f3f3f3f;
}

int main ()
{
	freopen ("meizi.in", "r", stdin);
	freopen ("meizi.out","w",stdout);
	
	register int n = read (), m = read ();
	for (Re int i = 1; i <= m; ++ i) e[i].fr = read (), e[i].to = read (), e[i].vp = read (), vq[i] = e[i].vq = read ();
	std::sort (e + 1, e + m + 1, cmp);
	register int ans = 0x3f3f3f3f;
	for (Re int i = 1; i <= m; ++ i) ans = min (ans, vq[i] + niconi(vq[i], n, m));
	printf ("%d", ans);
	fclose (stdin), fclose (stdout);
	return 0;
}
