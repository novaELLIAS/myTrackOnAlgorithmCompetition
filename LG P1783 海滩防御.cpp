#pragma GCC optimize ("Ofast", 3)
#pragma G++ optimize ("Ofast", 3)

#include <cstdio>
#include <cstring>

using namespace std;

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

#define Re register
#define maxn 1011
#define sqr(i,j) ((x[i]-x[j])*(x[i]-x[j])+((y[i]-y[j])*(y[i]-y[j])))

int x[maxn], y[maxn];
bool vis[maxn];
double dis[maxn][maxn];
const double eps = 1e-4;

int que[100000001], m, tm;

inline bool check (register double mid)
{
	register double x = mid * mid, dx = x * 4.0;
	register int i;
	memset (vis, 0, sizeof vis);
	//for (i = 1; i ^ tm; i ++) vis[i] = false;
	vis[0] = true;
	register int head = 0, tail = 0, fr;
	for (i = 1; i ^ m; i ++) if (dis[0][i] <= mid) que[++ tail] = i;
	//printf ("tail %d\n", tail);
	//for (i = 1; i <= tail; i ++) printf ("%d\n", que[i]);
	while (head < tail)
	{
		fr = que[++ head];
		if (dis[fr][m] <= mid) return true;
		for (i = 1; i ^ m; i ++)
		{
			if (!vis[i] && dis[fr][i] <= dx) vis[i] = true, que[++ tail] = i;
		}
	}
	return false;
}

int main ()
{
	register int n = read ();
	m = read () + 1, tm = m + 1;
	for (Re int i = 1; i ^ m; i ++)
	{
		x[i] = read(), y[i] = read ();
		dis[0][i] = dis[i][0] = x[i], dis[m][i] = dis[i][m] = n - x[i];
	}
	dis[0][m] = 10000000000.0;
	for (Re int i = 1; i ^ m; i ++)
	{
		for (Re int j = i + 1; j ^ m; j ++) dis[i][j] = dis[j][i] = sqr (i, j);
	}
	register double l = 0.0, r = 10001.0, ans, mid;
	while (r > eps + l)
	{
		mid = (l + r) / 2.0;
		//printf ("%.3lf\n", mid);
		if (check (mid)) ans = mid, r = mid;
		else l = mid;
	}
	printf ("%.2lf", ans);
	return 0;
}
