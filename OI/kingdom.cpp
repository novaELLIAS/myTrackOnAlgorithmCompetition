#include <cstdio>

using namespace std;

/****************************************************/
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
/****************************************************/

#define maxn 100001
#define Re register

int n, m;
int out[maxn], du[maxn];
int mapp[1001][1001], tmp[1001][1001];

inline void solve_tree ()
{
	register int ans = 0, u, v;
	for (Re int i = 0; i ^ m; i ++) du[read()] ++, du[read()] ++;
	for (Re int i = 1; i<= n; i ++) if (du[i] == 1) out[++ ans] = i;
	printf ("%d\n", ans);
	for (Re int i = 1; i <= ans; i ++) printf ("%d ", out[i]);
}

int fa[maxn];
inline int find (register int x)
{
	while (x ^ fa[x]) x = fa[x] = fa[fa[x]];
	return x;
}

inline void solve_small ()
{
	register int ans = 0, u, v, cnt = 0;
	register bool flag;
	for (Re int i = 0; i ^ m; i ++)
	{
		u = read (), v = read ();
		mapp[u][v] = mapp[v][u] = true;
	}
	for (Re int i = 1; i <= n; i ++)
	{
		for (Re int j = 1; j <= n; j ++)
		{
			for (Re int k = j + 1; k <= n; k ++) tmp[j][k] = tmp[k][j] = mapp[j][k];
		}
		flag = true;
		for (Re int j = 1; j <= n; j ++) tmp[j][i] = tmp[i][j] = false, fa[i] = i;
		for (Re int j = 1; j <= n && flag; j ++)
		{
			for (Re int k = j + 1; k <= n; k ++)
			{
				if (tmp[j][k])
				{
					u = find (j), v = find (k);
					if (u == v) {flag = false; break;}
					if (u ^ v)fa[u] = v;
				}
			}
		}
		if (flag)
		{
			for (Re int j = 1; j <= n; j ++) if (!(j^fa[j])) ++ cnt;
			if (cnt == 1) out[++ ans] = i;
		}
	}
	printf ("%d\n", ans);
	for (Re int i = 1; i <= ans; i ++) printf ("%d ", out[i]);
}

int main ()
{
	freopen ("kingdom.in","r",stdin);
	freopen ("kingdom.out","w",stdout);
	
	n = read (), m = read ();
	if (n == 2) {puts ("2"), puts ("1 2"); return 0;}
	if (m == n - 1) {solve_tree(); return 0;}
	else if (n <= 1000) {solve_small (); return 0;}
	else puts ("QwQ");
	return 0;
}
