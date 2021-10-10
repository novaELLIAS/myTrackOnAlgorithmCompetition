#include <cstdio>

#define Re register
#define maxn 400001
#define maxm 200001

inline char gc()
{
	static char buf[1<<14],*p1=buf,*p2=buf;
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0; register char c = gc();
	while (c < '0' || c > '9') c = gc();
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c - '0'), c = gc();
	return x;
}

struct edge {
	int nxt, fr, to;
}e[maxn];
int cnte, head[maxn];
inline void addedge (int u, int v)
{
	e[++ cnte].fr = u, e[cnte].nxt = head[u], head[u] = cnte, e[cnte].to = v;
	e[++ cnte].fr = v, e[cnte].nxt = head[v], head[v] = cnte, e[cnte].to = u;
}

bool dead[maxn];
int fa[maxn], kill[maxn], ans[maxn];

inline int find (register int x)
{
	while (x != fa[x]) x = fa[x] = fa[fa[x]];
	return x;
}

int main ()
{
	register int n = read (), m = read (), dm = m << 1, u, v, fu, fv;
	for (Re int i = 0; i ^ n; i ++) fa[i] = i, head[i] = -1;
	for (Re int i = 0; i ^ m; i ++) addedge (read (), read ());
	register int k = read (), tot = n - k;
	for (Re int i = 1; i <= k; i ++) dead[kill[i] = read ()] = true;
	for (Re int i = 1; i <= dm; i ++) if (!dead[e[i].fr] && !dead[e[i].to] && ((fu = find(e[i].fr)) ^ (fv = find (e[i].to)))) -- tot, fa[fu] = fv;
	ans[k + 1] = tot;
	for (Re int i = k; i; i --)
	{
		tot ++, dead[kill[i]] = false;
		for (Re int j = head[kill[i]]; j ^ (-1); j = e[j].nxt)
		{
			if (!dead[e[j].to] && (fu = find(kill[i])) ^ (fv = find(e[j].to))) -- tot, fa[fu] = fv;
		}
		ans[i] = tot;
	}
	k += 2;
	for (Re int i = 1; i ^ k; i ++) printf ("%d\n", ans[i]);
	return 0;
}
