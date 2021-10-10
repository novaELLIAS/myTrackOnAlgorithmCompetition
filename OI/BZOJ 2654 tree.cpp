#pragma GCC optimize ("Ofast", 3)
#pragma G++ optimize (3)

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
#define maxn 50001
#define maxe 100001

struct EDGE {
	int fr, to, va, col;
	bool operator < (const EDGE& a) const {
		return (va^a.va)? va<a.va:col<a.col;
	}
} e[maxe];

int fro[maxe], too[maxe], wei[maxe], col[maxe];
int fa[maxn], krs;

inline int find (register int x)
{
	while (x ^ fa[x]) x = fa[x] = fa[fa[x]];
	return x;
}

inline bool Kruskal (register int x, Re int n, Re int m, Re int need)
{
	for (Re int i = 1; i <= n; ++ i) fa[i] = i;
	register int cnt = 0, flc = 0, fr, to; krs = 0;
	for (Re int i = 1; i <= m; ++ i) {
		e[i] = (EDGE) {fro[i], too[i], wei[i], col[i]};
		if (!col[i]) e[i].va += x;
	}
	std::sort (e + 1, e + m + 1);
	for (Re int i = 1; i <= m; ++ i)
	{
		fr = find (e[i].fr), to = find (e[i].to);
		if (fr ^ to)
		{
			fa[fr] = to, krs += e[i].va, ++ cnt;
			if (!e[i].col) ++ flc;
		}
		if (cnt == n - 1) break;
	}
	return flc >= need;
}

int main ()
{
	register int n = read (), m = read (), need = read ();
	for (Re int i = 1; i <= m; ++ i)
		fro[i]=read()+1, too[i]=read()+1, wei[i]=read(), col[i]=read();
	register int l = -201, r = 201, mid, ans;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		if (Kruskal (mid, n, m, need)) l = mid + 1, ans = krs - need * mid;
		else r = mid - 1;
	}
	printf ("%d", ans);
	return 0;
}
